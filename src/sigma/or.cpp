#include "sigma/or.hpp"
#include "util/errorhandling.hpp"

// TODO: CM...
#ifndef CM_ENABLE_CODE_COLLECTING

using namespace ZKCompiler;

namespace ZKCompiler {
    namespace sigma {

        Or::Or(Parser *p, unsigned int n_, char *const params[])
        {
            bnz_t min, cp;
            bnz_init(min);
            bnz_init(cp);

            n = n_;
            proofs = new Sigma*[n];
            for(unsigned int i = 0; i < n; ++i) {
                proofs[i] = p->getSigma(params[i]);
                proofs[i]->getCPlus(cp);
                if(i == 0 || bnz_cmp(cp, min) < 0) bnz_set(min, cp);
            }

            setCPlus(min);
            bnz_clear(min);
            bnz_clear(cp);
        }

        Or::~Or()
        {
            for(unsigned int i = 0; i < n; ++i) delete proofs[i];
            delete[] proofs;
        }

        unsigned Or::getCommitmentSize() const
        {
            unsigned size = 0;
            for (unsigned int i = 0; i < n; i++)
                size += proofs[i]->getCommitmentSize();
            return size;
        }

        void Or::getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned u) const
        {
            unsigned curOffset = 0;
            for(unsigned i = 0; i < n; ++i)
            {
                unsigned offset = proofs[i]->getCommitmentSize();
                if (curOffset + offset > u)
                    ZK_HANDLE_ERROR("wrong size");
                proofs[i]->getCommitmentPtrs(vpDst + curOffset, offset);
                curOffset += offset;
            }
        }

        void Or::setCommitment(const CMV::bnz_t* vpSrc[], unsigned u)
        {
            unsigned curOffset = 0;
            for(unsigned i = 0; i < n; ++i)
            {
                unsigned offset = proofs[i]->getCommitmentSize();
                if (curOffset + offset > u)
                    ZK_HANDLE_ERROR("wrong size");
                proofs[i]->setCommitment(vpSrc + curOffset, offset);
                curOffset += offset;
            }
        }

        unsigned Or::getResponseSize() const
        {
            unsigned size = 0;
            for (unsigned int i = 0; i < n; i++)
                size += proofs[i]->getResponseSize();
            return size;
        }

        void Or::getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned u) const
        {
            unsigned curOffset = 0;
            for(unsigned i = 0; i < n; ++i)
            {
                unsigned offset = proofs[i]->getResponseSize();
                if (curOffset + offset > u)
                    ZK_HANDLE_ERROR("wrong size");
                proofs[i]->getResponsePtrs(vpDst + curOffset, offset);
                curOffset += offset;
            }
        }

        void Or::setResponse(const CMV::bnz_t* vpSrc[], unsigned u)
        {
            unsigned curOffset = 0;
            for(unsigned i = 0; i < n; ++i)
            {
                unsigned offset = proofs[i]->getResponseSize();
                if (curOffset + offset > u)
                    ZK_HANDLE_ERROR("wrong size");
                proofs[i]->setResponse(vpSrc + curOffset, offset);
                curOffset += offset;
            }
        }

        void Or::P1()
        {
            /* simulate all but the first known sub proof */
            bool k = false;
            for(unsigned int i = 0; i < n; ++i) {
                bool sn = proofs[i]->simulationNeeded();
                if(k || sn) {
                    /* generate random challenge and simulate proofs[i] */
                    proofs[i]->genChallenge();
                    proofs[i]->S();
                } else {
                    k = true;
                    known_sigma = i;
                    proofs[i]->P1();
                }
            }
        }


        void Or::P2()
        {
            bnz_t challenge_sum;
            bnz_t temp;

            bnz_init_set(challenge_sum, c);
            bnz_init(temp);

            // Collect and sum up challenges
            for (unsigned int i = 0; i < n; i++)
            {
                if(i == known_sigma) continue;
                proofs[i]->getChallenge(temp);
                bnz_sub(challenge_sum, challenge_sum, temp);
            }

            bnz_mod(challenge_sum, challenge_sum, cplus);

            // Set challenge of known sigma
            proofs[known_sigma]->setChallenge(challenge_sum);

            // Call P2 of known sigma
            proofs[known_sigma]->P2();

            bnz_clear(challenge_sum);
            bnz_clear(temp);
        }

        CMV::zk_bool_t Or::V(bool interactive)
        {
            /* run V for all sub proofs. If at least one is false, our return value is false as well */
            bool equal = true;
            for(unsigned int i = 0; i < n; ++i) if(proofs[i]->V(interactive) == false) equal = false;
            return equal;
        }

        void Or::S()
        {
            /* simulate this proof. Calculate ch = c - c1 - c2 - c3 - ... - cn-1 */
            bnz_t ch, pc;
            bnz_init_set(ch, c);
            bnz_init(pc);

            /* generate random challenges for sub proofs 1..n-1 and simulate them */
            for(unsigned int i = 1; i < n; ++i) {
                proofs[i]->genChallenge();
                proofs[i]->getChallenge(pc);
                bnz_sub(ch, ch, pc);
                proofs[i]->S();
            }
            bnz_mod(ch, ch, cplus);

            /* finally, simulate proofs[0] */
            proofs[0]->setChallenge(ch);
            proofs[0]->S();
            bnz_clear(pc);
            bnz_clear(ch);
        }

        void Or::R()
        {		
            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->R();
            }
        }

        void Or::setCPlus(const bnz_t& cp)
        {
            Sigma::setCPlus(cp);
            for(unsigned int i = 0; i < n; ++i) proofs[i]->setCPlus(cp);
        }

        void Or::setCommitment(Message r)
        {
            // Split commitment into sub-commitments
            Message *single_r = new Message[n];
            Convert::messageToMessages(r, single_r, n, 0);

            // Set commitments to predicates
            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->setCommitment(single_r[i]);
            }	
            delete[] single_r;
        }

        void Or::setResponse(Message s)
        {
            bnz_t ch, pc;
            bnz_init_set(ch, c);
            bnz_init(pc);
            Message *msg = new Message[n + n - 1]; /* n sub responses, n-1 challenges */
            Convert::messageToMessages(s, msg, n + n - 1, 0);
            for(unsigned int i = 0; i < n; ++i) {
                proofs[i]->setResponse(msg[i]);
                if(i > 0) { /* challenge for proofs[0] gets calculated and set later */
                    Convert::messageToMpzt(msg[n + i - 1], pc);
                    proofs[i]->setChallenge(pc);
                    bnz_sub(ch, ch, pc);
                }
            }
            bnz_mod(ch, ch, cplus);
            proofs[0]->setChallenge(ch);
            bnz_clear(pc);
            bnz_clear(ch);
            delete[] msg;
        }
        
        void Or::setAuxCommitment(Message msg)
        {
            Message *m = new Message[n];
            Convert::messageToMessages(msg, m, n, 0);
            for(unsigned int i = 0; i < n; ++i)
                proofs[i]->setAuxCommitment(m[i]);
            delete[] m;
        }

        Message Or::getCommitment()
        {
            // Collent commitments
            Message *single_r = new Message[n];		
            for (unsigned int i = 0; i < n; i++)
            {
                single_r[i] = proofs[i]->getCommitment();	
            }

            // Build single message
            Message r = Convert::messagesToMessage(single_r, n);
            for (unsigned int i = 0; i < n; i++)
            {
                delete[] single_r[i].data;
            }
            delete[] single_r;
            return r;
        }

        Message Or::getResponse()
        {
            // Collect commitments
            Message *single_s = new Message[n + n - 1];	
            for (unsigned int i = 0; i < n; i++)
            {
                single_s[i] = proofs[i]->getResponse();	
                if(i > 0) single_s[n + i - 1] = proofs[i]->getChallenge();
            }

            // Build single message
            Message s = Convert::messagesToMessage(single_s, n + n - 1);
            for (unsigned int i = 0; i < n + n - 1; i++)
            {
                delete[] single_s[i].data;
            }
            delete[] single_s;
            return s;
        }

        Message Or::getPublic()
        {
            // Collent commitments
            Message *single_x = new Message[n];	
            for (unsigned int i = 0; i < n; i++)
            {
                single_x[i] = proofs[i]->getPublic();	
            }

            // Build single message
            Message x = Convert::messagesToMessage(single_x, n);
            for (unsigned int i = 0; i < n; i++)
            {
                delete[] single_x[i].data;
            }
            delete[] single_x;
            return x;
        }
        
        Message Or::getAuxCommitment()
        {
            Message *m = new Message[n];

            for(unsigned i = 0; i < n; ++i)
                m[i] = proofs[i]->getAuxCommitment();

            Message msg = Convert::messagesToMessage(m, n);

            for(unsigned i = 0; i < n; ++i)
                delete[] m[i].data;
            delete[] m;

            return msg;
        }

        bool Or::simulationNeeded()
        {
            bool ret = true;
            for(unsigned int i = 0; i < n; ++i) {
                if(!proofs[i]->simulationNeeded()) ret = false;
            }
            return ret;
        }
    }
}
#endif

#include "sigma/and.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    CMO_USING_OPERATORS;
    namespace sigma {

        And::And(Sigma **proofs_, unsigned int n_)
        {
            proofs = proofs_;
            n = n_;
            // determine minimum cplus
            CMV(bnz_t min);
            CMV(bnz_t cp);
            CMI(bnz_init(min));
            CMI(bnz_init(cp));

            for(unsigned int i = 0; i < n; ++i) {
                proofs[i]->getCPlus(cp);
                if(i == 0)
                    CMI(bnz_set(min, cp));
                else
                {
                    CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))
                        CMI(bnz_set(min, cp));
                    CMM_ENDIF
                }
            }

            setCPlus(min);
            CMI(bnz_clear(min));
            CMI(bnz_clear(cp));
        }

        And::And(Parser *p, unsigned int n_, char *const params[])
        {
            // determine minimum cplus
            CMV(bnz_t min);
            CMV(bnz_t cp);
            CMI(bnz_init(min));
            CMI(bnz_init(cp));

            n = n_;
            proofs = new Sigma*[n];
            for(unsigned int i = 0; i < n; ++i) {
                proofs[i] = p->getSigma(params[i]);
                proofs[i]->getCPlus(cp);
                if(i == 0)
                    CMI(bnz_set(min, cp));
                else
                {
                    CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))
                        CMI(bnz_set(min, cp));
                    CMM_ENDIF
                }
            }

            setCPlus(min);
            CMI(bnz_clear(min));
            CMI(bnz_clear(cp));
        }


        And::~And()
        {
            for (unsigned int i = 0; i < n; i++) {
                delete proofs[i];
            }
            delete[] proofs;
        }

        unsigned And::getCommitmentSize() const
        {
            unsigned size = 0;
            for (unsigned int i = 0; i < n; i++)
                size += proofs[i]->getCommitmentSize();
            return size;
        }

        void And::getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned u) const
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

        void And::setCommitment(const CMV::bnz_t* vpSrc[], unsigned u)
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

        unsigned And::getResponseSize() const
        {
            unsigned size = 0;
            for (unsigned int i = 0; i < n; i++)
                size += proofs[i]->getResponseSize();
            return size;
        }

        void And::getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned u) const
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

        void And::setResponse(const CMV::bnz_t* vpSrc[], unsigned u)
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

        void And::P1()
        {
            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->P1();
            }
        }

        void And::P2()
        {
            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->P2();
            }
        }

        CMV::zk_bool_t And::V(bool interactive)
        {
            CMV(zk_bool_t ret);
            ret = CMV_IN(true);

            for (unsigned int i = 0; i < n; i++)
            {
                CMM_IF(!proofs[i]->V(interactive))
                    ret = CMV_IN(false);
                CMM_ENDIF
            }
            return ret;
        }

        void And::S()
        {
            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->S();
            }
        }

        void And::R()
        {
            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->R();
            }
        }

        void And::setCPlus(const CMV::bnz_t& cp)
        {
            Sigma::setCPlus(cp);
            for(unsigned int i = 0; i < n; ++i) proofs[i]->setCPlus(cp);
        }

        void And::setChallenge(const CMV::bnz_t& c_)
        {
            Sigma::setChallenge(c_);
            for(unsigned int i = 0; i < n; ++i) proofs[i]->setChallenge(c_);
        }

        void And::setCommitment(Message r)
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

        void And::setResponse(Message s)
        {
            Message *single_s = new Message[n];
            Convert::messageToMessages(s, single_s, n, 0);

            for (unsigned int i = 0; i < n; i++)
            {
                proofs[i]->setResponse(single_s[i]);
            }
            delete[] single_s;
        }

        void And::setAuxCommitment(Message msg)
        {
            Message *m = new Message[n];
            Convert::messageToMessages(msg, m, n, 0);
            for(unsigned int i = 0; i < n; ++i)
                proofs[i]->setAuxCommitment(m[i]);
            delete[] m;
        }

        Message And::getCommitment()
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

        Message And::getResponse()
        {
            // Collent commitments
            Message *single_s = new Message[n];	
            for (unsigned int i = 0; i < n; i++)
            {
                single_s[i] = proofs[i]->getResponse();	
            }

            // Build single message
            Message s = Convert::messagesToMessage(single_s, n);
            for (unsigned int i = 0; i < n; i++)
            {
                delete[] single_s[i].data;
            }
            delete[] single_s;
            return s;
        }

        Message And::getPublic()
        {
            // Collect commitments
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

        Message And::getAuxCommitment()
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

        bool And::simulationNeeded()
        {
            bool ret = false;
            for(unsigned int i = 0; i < n; ++i) {
                if(proofs[i]->simulationNeeded()) ret = true;
            }
            return ret;
        }


    }
}

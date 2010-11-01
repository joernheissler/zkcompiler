#include "sigma/phi.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    CMO_USING_OPERATORS;
    namespace sigma {

        Phi::Phi(Parser *p, unsigned int n, char *const params[])
        {
            if (n != 4) ZK_HANDLE_ERROR("ERROR: Invalid number of parameters!");

            phi = p->getHom(params[0]);
            x = p->getVar(params[1]);
            w = p->getVar(params[2]);
            r = phi->getDstElement();
            s = phi->getSrcElement();
            state = phi->getSrcElement();
            bnz_t cp;
            if(bnz_init_set_str(cp, params[3], 0)) ZK_HANDLE_ERROR("conversion error");
            setCPlus(CMV_IN(cp));
            bnz_clear(cp);
        }

        Phi::~Phi()
        {
            delete r;
            delete s;
            delete state;
        }

        unsigned Phi::getCommitmentSize() const
        {
            return r->getSize();
        }

        void Phi::getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned n) const
        {
            r->getPtrs(vpDst, n);
        }

        void Phi::setCommitment(const CMV::bnz_t* vpSrc[], unsigned n)
        {
            r->set(vpSrc, n);
        }

        unsigned Phi::getResponseSize() const
        {
            return s->getSize();
        }

        void Phi::getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned n) const
        {
            s->getPtrs(vpDst, n);
        }

        void Phi::setResponse(const CMV::bnz_t* vpSrc[], unsigned n)
        {
            s->set(vpSrc, n);
        }

        void Phi::P1()
        {
            // state of P1 for P2
            state->random();

            // calculate phi(state) and save to r
            r->map(phi, state);
        }

        void Phi::P2()
        {
            // s = w*c (add. group!)
            s->pow(w, c);
            // s = k + s (add. group!)
            s->op(s, state);
        }

        CMV::zk_bool_t Phi::V(bool interactive)
        {
            
			if (!interactive)
			{
				return CMV_IN(true);
			}

			Element *left, *right;
            CMV(zk_bool_t is_equal);

            // left side of verification cong. relation
			left = phi->getDstElement();
			left->map(phi, s);

			// right side of verification cong. relation
			right = phi->getDstElement();
			right->pow(x, c);
			right->op(right, r);

			CMM_IF((left->cmp(right) == CMV_IN(R_ID)))
				is_equal = CMV_IN(true);
			CMM_ELSE
				is_equal = CMV_IN(false);
			CMM_ENDIF
			            
			delete left;
			delete right;

			return is_equal;
        }

        void Phi::S()
        {
            // set s to random
            s->random();
            R();
        }

        void Phi::R()
        {
            Element *temp = phi->getDstElement();

            // temp = x^-c
            temp->ipow(x, c);

            // r = phi(s)
            r->map(phi, s);

            // r = phi(s) * x^-c
            r->op(r, temp);

            delete temp;
        }
        
        void Phi::setCommitment(Message msg)
        {
            r->set(msg);
        }
        
        void Phi::setResponse(Message msg)
        {
            s->set(msg);
        }


        Message Phi::getCommitment()
        {
            return r->get();
        }
        
        Message Phi::getResponse()
        {
            return s->get();
        }

        Message Phi::getPublic()
        {
            return x->get();
        }

        bool Phi::simulationNeeded()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Sigma::simulationNeeded() is not allowed to be called in not executed code regions when code is collecting!");
            return !w->isSet();
        }
    }
}

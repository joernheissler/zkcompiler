#include <cerrno>
#include <cstdlib>

#include "sigma/gsp.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    CMO_USING_OPERATORS;
    namespace sigma {

        Gsp::Gsp(Parser *p, unsigned int n, char *const params[]) : CMV_CONSTRUCT(l)
        {

            if(n != 5) ZK_HANDLE_ERROR("ERROR: Gsp needs 5 parameters");
            phi = p->getHom(params[0]);
            x = p->getVar(params[1]);
            w = p->getVar(params[2]);

            errno = 0;
            l = CMV_IN((unsigned) strtoul(params[4], 0, 10));
            if(errno) ZK_HANDLE_ERROR("conversion error");

            bnz_t cp;
            if(bnz_init_set_str(cp, params[3], 0)) {
                bnz_clear(cp);
                ZK_HANDLE_ERROR("conversion error");
            }
            setCPlus(CMV_IN(cp));
            bnz_clear(cp);

            r = phi->getDstElement();
            s = phi->getSrcElement();
            state = phi->getSrcElement();
        }

        Gsp::~Gsp()
        {
            delete r;
            delete s;
            delete state;
        }

        unsigned Gsp::getCommitmentSize() const
        {
            return r->getSize();
        }

        void Gsp::getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned n) const
        {
            r->getPtrs(vpDst, n);
        }

        void Gsp::setCommitment(const CMV::bnz_t* vpSrc[], unsigned n)
        {
            r->set(vpSrc, n);
        }

        unsigned Gsp::getResponseSize() const
        {
            return s->getSize();
        }

        void Gsp::getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned n) const
        {
            s->getPtrs(vpDst, n);
        }

        void Gsp::setResponse(const CMV::bnz_t* vpSrc[], unsigned n)
        {
            s->set(vpSrc, n);
        }

        void Gsp::randomstate(Element *e)
        {
            CMV(bnz_t tight);
            CMI(bnz_init(tight));
            Element *tmp = phi->getSrcElement();

            e->max();                           // e = R
            tmp->min();                         // tmp = L
            tmp->op(tmp, e);                    // tmp = L+R
            CMI(bnz_mul_2exp(tight, cplus, CMV::zk_ulong_t(l + CMV_IN(1u))));  // tight = cplus * 2^(l+1)
            e->random(tight);                   // e in [2 * L * cplus * 2^l, 2 * R * cplus * 2^l ]
            CMI(bnz_tdiv_q_2exp(tight, tight, CMV_IN(1ul)));   // shift right tight by 1 -> tight = cplus * 2^l
            tmp->pow(tmp, tight);               // tmp = (L+R) * cplus * 2^l
            e->iop(e, tmp);                     // e in [-m * cplus * 2^l, m * cplus * 2^l ]

            CMI(bnz_clear(tight));
            delete tmp;
        }

        void Gsp::P1()
        {
            randomstate(state);
            // calculate phi(state) and save to r
            r->map(phi, state);
        }

        void Gsp::S()
        {
            Element *tmp = phi->getSrcElement();
            tmp->random();          // tmp in [L,R]
            s->min();               // s = L
            tmp->iop(tmp, s);       // tmp in [0,m]
            tmp->pow(tmp, c);       // tmp in [0,m*c]
            randomstate(s);         // s in [-m * cplus * 2^l, m * cplus * 2^l ]
            s->op(s, tmp);          // s in [-m * cplus * 2^l, m * (cplus * 2^l + c) ]
            delete tmp;
            
            R();
        }

        void Gsp::R()
        {
            Element *temp = phi->getDstElement();
            Element *s_temp = phi->getSrcElement();

            // prepare s_temp
            s_temp->min();          // s_temp = L
            s_temp->pow(s_temp, c); // s_temp = L * c
            s_temp->op(s, s_temp);  // s_temp = s + L * c
            r->map(phi, s_temp);    // r = phi(s + L * c)

            // calculate corresponding message r
            temp->ipow(x, c);       // temp = x^-c
            r->op(r, temp);         // r = phi(s + L * c) * x^-c

            delete temp;
            delete s_temp;
        }

        Message Gsp::getPublic()
        {
            return x->get();
        }

        void Gsp::setResponse(Message msg)
        {
            s->set(msg);
        }

        Message Gsp::getCommitment()
        {
            return r->get();
        }

        void Gsp::P2()
        {
            s->min();           // s = L
            s->iop(w, s);       // s = w - L
            s->pow(s, c);       // s = (w - L) * c
            s->op(s, state);    // s = k + (w - L) * c
        }

        Message Gsp::getResponse()
        {
            return s->get();
        }

        void Gsp::setCommitment(Message msg)
        {
            r->set(msg);
        }

        CMV::zk_bool_t Gsp::V(bool interactive)
        {
            CMV(zk_bool_t is_in_range);
            is_in_range = CMV_IN(true);

            CMV(bnz_t t);
            CMI(bnz_init(t));
            Element *tmp0 = phi->getSrcElement();
            Element *tmp1 = phi->getSrcElement();
            
            CMI(bnz_mul_2exp(t, cplus, CMV::zk_ulong_t(l)));  // t = cplus * 2^l
            tmp0->min();                // tmp0 = L
            tmp1->max();                // tmp1 = R
            tmp1->iop(tmp1, tmp0);      // tmp1 = R - L = m
            tmp0->pow(tmp1, t);         // tmp0 = m * cplus * 2^l
            tmp0->op(s, tmp0);          // tmp0 = s + m * cplus * 2^l. Should be in [0, m * (cplus * 2^(l+1) + c) ]
            CMI(bnz_mul_2exp(t, t, CMV_IN(1ul)));      // t = cplus * 2^(l+1)
            CMI(bnz_add(t, t, c));           // t = cplus * 2^(l+1) + c
            tmp1->pow(tmp1, t);         // tmp1 = m * (cplus * 2^(l+1) + c)

            CMM_IF((CMV::zk_uint_t)tmp0->cmp(tmp1) & CMV_IN(8u))
                is_in_range = CMV_IN(false);
            CMM_ENDIF
            tmp1->identity();
            CMM_IF((CMV::zk_uint_t)tmp0->cmp(tmp1) & CMV_IN(4u))
                is_in_range = CMV_IN(false);
            CMM_ENDIF
            delete tmp0;
            delete tmp1;
            CMI(bnz_clear(t));

            if (!interactive)
                return is_in_range;

            CMV(zk_bool_t result);
            CMM_IF(is_in_range)
                CMV(zk_bool_t is_equal);
                is_equal = CMV_IN(true);

                Element *temp  = phi->getSrcElement();
                Element *left  = phi->getDstElement();
                Element *right = phi->getDstElement();

                temp->min();                // temp = L
                temp->pow(temp, c);         // temp = L*c
                temp->op(temp, s);          // temp = L*c + s
                left->map(phi, temp);       // left = phi(s + L*c)

                right->pow(x, c);           // right = x^c
                right->op(right, r);        // right = r * x^c

                CMM_IF((CMV::zk_uint_t)left->cmp(right) & CMV_IN(14u))
                    is_equal = CMV_IN(false);
                CMM_ELSE
                    is_equal = CMV_IN(true);
                CMM_ENDIF

                delete left;
                delete right;
                delete temp;

                result = is_equal;
            CMM_ELSE
                result = is_in_range;
            CMM_ENDIF

            return result;
        }

        bool Gsp::simulationNeeded()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Sigma::simulationNeeded() is not allowed to be called in not executed code regions when code is collecting!");
            return !w->isSet();
        }

    }
}

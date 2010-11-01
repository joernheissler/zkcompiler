#if 0 // shut up doxygen
#include <cerrno>
#include "sigma/SigmaExp.hpp"
#include "util/convert.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
	namespace sigma {
	
		SigmaExp::SigmaExp(Hom *phi, Theta *theta, Element *x, Element *w, Element *L, Element *Rb, bnz_t cplus, unsigned int l, unsigned int u)
		{
			// generate new elements for member variables			
			bnz_init(c);
			s = phi->getSrcGroup()->element();
			state = phi->getSrcGroup()->element();	
			m = phi->getSrcGroup()->element();
			t = phi->getDstGroup()->element();
            r = phi->getDstGroup()->element();
			

			// assign member variables
			this->phi = phi;
			this->theta = theta;
			this->x = x;
			this->w = w;	
			this->u = u;
			this->L = L;
			this->Rb = Rb;
			this->l = l;
                        setCPlus(cplus);

			// Save interval lengths in member m
			m->iop(Rb, L);

			bnz_init(xx);
			bnz_init(tt);
			bnz_init(ss);
			bnz_init(ww);
			bnz_init(rr);			
		}

        SigmaExp::SigmaExp(Parser *p, unsigned int n, char *const params[])
        {
            static Theta *FIXME = 0;

            if(n != 5) ZK_HANDLE_ERROR("ERROR: SigmaGsp needs 5 parameters");
            phi = p->getHom(params[0]);
            x = p->getVar(params[1]);
            w = p->getVar(params[2]);
            u = w->getSize();

            errno = 0;
            l = strtoul(params[4], 0, 10);
            if(errno) ZK_HANDLE_ERROR("conversion error");

            bnz_t cp;
            if(bnz_init_set_str(cp, params[3], 0)) {
                bnz_clear(cp);
                ZK_HANDLE_ERROR("conversion error");
            }
            setCPlus(cp);
            bnz_clear(cp);

            r = phi->getDstGroup()->element();
            s = phi->getSrcGroup()->element();
            state = phi->getSrcGroup()->element();

            if(!FIXME) FIXME = new Theta(u);
            theta = FIXME;
			
            bnz_init(xx);
			bnz_init(tt);
			bnz_init(ss);
			bnz_init(ww);
			bnz_init(rr);
			
            m = phi->getSrcGroup()->element();
            L = phi->getSrcGroup()->element();
            Rb = phi->getSrcGroup()->element();

            L->min();
            Rb->max();
            m->iop(Rb, L);
			t = phi->getDstGroup()->element();
        }

		SigmaExp::~SigmaExp()
		{
            delete s;
            delete state;
            delete m;
            delete t;
            delete r;

			bnz_clear(xx);
			bnz_clear(tt);
			bnz_clear(ss);
			bnz_clear(ww);
			bnz_clear(rr);
		}

        unsigned SigmaExp::getCommitmentSize() const
        {
            // TODO: implement...
            ZK_HANDLE_ERROR("Not implemented yet! Needed for CM...");
            return 0;
        }

        void SigmaExp::getCommitment(const CMV::bnz_t* /*vpDst*/[], unsigned /*u*/) const
        {
            // TODO: implement...
            ZK_HANDLE_ERROR("Not implemented yet! Needed for CM...");
        }

        void SigmaExp::setCommitment(const CMV::bnz_t* /*vpSrc*/[], unsigned /*u*/)
        {
            // TODO: implement...
            ZK_HANDLE_ERROR("Not implemented yet! Needed for CM...");
        }

        unsigned SigmaExp::getResponseSize() const
        {
            // TODO: implement...
            ZK_HANDLE_ERROR("Not implemented yet! Needed for CM...");
            return 0;
        }

        void SigmaExp::getResponse(const CMV::bnz_t* /*vpDst*/[], unsigned /*u*/) const
        {
            // TODO: implement...
            ZK_HANDLE_ERROR("Not implemented yet! Needed for CM...");
        }

        void SigmaExp::setResponse(const CMV::bnz_t* /*vpSrc*/[], unsigned /*u*/)
        {
            // TODO: implement...
            ZK_HANDLE_ERROR("Not implemented yet! Needed for CM...");
        }

        void SigmaExp::P1()
		{			
			bnz_t border, n;
			unsigned int i;

			bnz_init(border);
			bnz_init(n);

			theta->getN(n);

			// generate random numbers and save numbers to "state"
			for (i = 0; i < u; i++)
			{
				bnz_ui_pow_ui(border, 2, l);
				bnz_mul(border, border, cplus);
				bnz_mul(border, border, m->getZ()[i]);
				bnz_mul_ui(border, border, 2);
				ZKCompiler::Random::posrange(state->getZ()[i], border);
				bnz_divexact_ui(border, border, 2);
				bnz_sub(state->getZ()[i], state->getZ()[i], border);

			}
	                   state->set();
			
			// generate random number ww
			bnz_ui_pow_ui(border, 2, l);
			bnz_mul(border, border, n);
			ZKCompiler::Random::posrange(ww, border);
            

			// generate random number rr
			bnz_ui_pow_ui(border, 2, 2*l);
			bnz_mul(border, border, cplus);
			bnz_mul(border, border, n);
			bnz_mul_ui(border, border, 2);
			ZKCompiler::Random::posrange(rr, border);
			bnz_divexact_ui(border, border, 2);
			bnz_sub(rr, rr, border);
       
			
			// calculate phi(state) and save to t
            t->map(phi, state);
			zkprintf("t = %Zd\n", t->getZ()[0]);

			// calculate theta(w_i, ww) and save to xx
			theta->getTheta(xx, w->getZ(), ww, u);
			zkprintf("xx = %Zd\n", xx);
             

			// calculate theta(r_i, rr) and save to tt
			theta->getTheta(tt, state->getZ(), rr, u);
			zkprintf("tt = %Zd\n", tt);
             

			bnz_clear(border);
			bnz_clear(n);
		}
		
		void SigmaExp::S()
		{
			P1();

			Element *temp = phi->getDstGroup()->element();
			Element *s_temp = phi->getSrcGroup()->element();
			bnz_t c; 			
			bnz_t random, border, left, right, n;
			unsigned int i;

			bnz_init_set(c, this->c);
			bnz_init(border);
			bnz_init(random);
			bnz_init(left);
			bnz_init(right);
			bnz_init(n);
			
			theta->getN(n);

			// generate random numbers for message s
			for (i = 0; i < u; i++)
			{
				bnz_ui_pow_ui(border, 2, l);
				bnz_mul(border, border, cplus);
				bnz_mul(border, border, m->getZ()[i]);
				bnz_mul_ui(border, border, 2);
				ZKCompiler::Random::posrange(random, border);
				bnz_divexact_ui(border, border, 2);
				bnz_sub(random, random, border);
				bnz_set(s->getZ()[i], random);
			}		
                        s->set();
			
			// prepare s_temp
			bnz_t *s_temp2 = new bnz_t[s->getSize()]; 
			for (unsigned int i = 0; i < s->getSize(); i++)
			{
				bnz_init(s_temp2[i]);
				bnz_mul(s_temp2[i], c, L->getZ()[i]);
				bnz_sub(s_temp2[i], s->getZ()[i], s_temp2[i]);
			}
			
			s_temp->pow(L, c); // c * L_i
			s_temp->iop(s, s_temp); // s_i - c * L_i
			
			// calculate corresponding message t
			temp->pow(x, c);	// x^c	
			t->map(phi, s_temp); // phi(s_i - c * L_i)
			t->op(t, temp); // x^c * phi(s_i - c * L_i)
			
			// generate random number for message ss
			bnz_ui_pow_ui(left, 2, 2*l); // 2^(2l)
			bnz_mul(left, left, cplus); // 2^(2l) * c+
			bnz_mul(left, left, n); // 2^(2l) * c+ * n
			bnz_ui_pow_ui(right, 2, l);	// 2^l
			bnz_mul(right, right, cplus); // 2^l * c+
			bnz_mul(right, right, n); // 2^l * c+ * n			
			bnz_mul_ui(border, left, 2); // 2 * 2^(2l) * c+ * n
			bnz_sub(border, border, right); // 2 * 2^(2l) * c+ * n - 2^l * c+ * n			
			ZKCompiler::Random::posrange(random, border);			
			bnz_sub(ss, random, left);
			bnz_add(ss, ss, right);
                       
			
			// calculate corresponding message tt
			bnz_powm(left, xx, c, n); // xx^c	
			theta->getTheta(tt, s_temp2, ss, u); // theta(s_i - c * L_i, ss)			
                  
			bnz_mul(tt, tt, left); // xx^c * theta(s_i - c * L_i, ss)	
			
            delete temp;
            delete s_temp;
			bnz_clear(c);
			bnz_clear(random);
			bnz_clear(border);
			bnz_clear(left);
			bnz_clear(right);
			bnz_clear(n);
			for (unsigned int i = 0; i < s->getSize(); i++)
			{
				bnz_clear(s_temp2[i]);
			}
			delete[] s_temp2;
		}		

		void SigmaExp::getCommitment(Element *t, Element *xx, Element *tt)
		{		
                    t->set(this->t);
		}

		Message SigmaExp::getCommitment()
		{		
			Message *msg = new Message[3];

			msg[0] = t->getMessage();
			msg[1] = Convert::mpztToMessage(xx);
			msg[2] = Convert::mpztToMessage(tt);

			return Convert::messagesToMessage(msg, 3);
		}

		void SigmaExp::P2()
		{
			Element *temp = phi->getSrcGroup()->element();

			temp->iop(w, L); // w_i - L_i
			temp->pow(temp, c); // c * (w_i - L_i)
			s->iop(state, temp); // r_i - c * (w_i - L_i)
			
			bnz_t n;
			bnz_init(n);
			theta->getN(n);

			bnz_mul(ss, ww, c);
			bnz_sub(ss, rr, ss);


			bnz_clear(n);
            delete temp;
		}

		void SigmaExp::getResponse(Element *s, Element *ss)
		{
                    s->set(this->s);
		}

		Message SigmaExp::getResponse()
		{

			Message *msg = new Message[2];

			msg[0] = s->getMessage();
			msg[1] = Convert::mpztToMessage(ss);

			return Convert::messagesToMessage(msg, 2);
		}

		void SigmaExp::setCommitment(Element *t, Element *xx, Element *tt)
		{
                    this->t->set(t);
		}

		void SigmaExp::setCommitment(Message r)
		{
                    this->r->setMessage(r);
		}

		void SigmaExp::setResponse(Element *s, Element *ss)
		{
                    this->s->set(s);
                    //this->ss->set(ss);
		}

		void SigmaExp::setResponse(Message s)
		{
			Message *msg = new Message[2];
			Convert::messageToMessages(s, msg, 2, 1);
            this->s->setMessage(msg[0]);
            //this->ss->setMessage(msg[1]);
			Convert::messageToMpzt(msg[1], ss);
		}

		CMV::zk_bool_t SigmaExp::V(bool interactive)
		{
			Element *expr1, *expr2, *expr3;
			bnz_t left;
			bnz_t right;
			int count_not_equal = 0;
			int count_not_in_range = 0;
			unsigned int i = 0;
			bnz_t border;
			bnz_t n;
			bnz_t s_temp;

			expr1 = phi->getSrcGroup()->element();
			expr2 = phi->getDstGroup()->element();
			expr3 = phi->getDstGroup()->element();

			bnz_init(left);
			bnz_init(right);
			bnz_init(border);
			bnz_init(n);
			theta->getN(n);
			bnz_init(s_temp);

			// first test
			for (i = 0; i < u; i++)
			{
				bnz_ui_pow_ui(left, 2, l);		
				bnz_mul(left, left, cplus);
				bnz_mul(left, left, m->getZ()[i]);
				bnz_mul(right, cplus, m->getZ()[i]);

				bnz_mul_ui(border, left, 2);
				bnz_sub(border, border, right);

				bnz_add(s_temp, s->getZ()[i], left);
				bnz_sub(s_temp, s_temp, right);

				if (bnz_cmp(s_temp, border) > 0)
				{
					count_not_in_range++;
				}
			}

			// second test	
			if (count_not_in_range == 0)
			{
				bnz_ui_pow_ui(left, 2, 2*l);		
				bnz_mul(left, left, cplus);
				bnz_mul(left, left, n);
				bnz_ui_pow_ui(right, 2, l);		
				bnz_mul(right, right, cplus);
				bnz_mul(right, right, n);
				
				bnz_mul_ui(border, left, 2);
				bnz_sub(border, border, right);
				
				bnz_add(s_temp, ss, left);
				bnz_sub(s_temp, s_temp, right);

				if (bnz_cmp(s_temp, border) > 0)
				{
					count_not_in_range++;
				}
			}

			// third test 
			if (count_not_in_range == 0 && interactive == true)
			{
				expr1->pow(L, c); // c * L_i
				expr1->iop(s, expr1); // s_i - c * L_i
				expr2->map(phi, expr1); // phi(s_i - c * L_i)

				expr3->pow(x, c); // x^c
				expr3->op(expr3, expr2); // x^c * phi(s_i - c * L_i)
				
				if (bnz_cmp( expr3->getZ()[0], t->getZ()[0] ) != 0)
				{
					count_not_equal++;
				}
			}

			// fourth test
			if (count_not_in_range == 0 && count_not_equal == 0 && interactive == true)
			{
				// Notice that calculated is needed to take place in Z*_n.
				// With n = theta->n.
				bnz_t expr4, expr5;
				bnz_init(expr4);
				bnz_init(expr5);

						
				expr1->pow(L, c); // c * L_i
				
				expr1->iop(s, expr1); // s_i - c * Li
				
				bnz_t *si_temp = new bnz_t[s->getSize()];
				for (unsigned int i = 0; i < s->getSize(); i++) 
				{
					bnz_init(si_temp[i]);
					bnz_mul(si_temp[i], c, L->getZ()[i]);
					bnz_sub(si_temp[i], s->getZ()[i], si_temp[i]);					
				}
				theta->getTheta(expr5, si_temp, ss, expr1->getSize()); // theta(s_i - c * L_i, ss)				
                expr2->set();				
				
				bnz_powm(expr4, xx, c, n); // xx ^ c mod n


				bnz_mul(expr4, expr4, expr5); // xx ^ c mod n * theta(s_i - c * L_i, ss)

				bnz_mod(expr4, expr4, n); // xx ^ c mod n * theta(s_i - c * L_i, ss) mod n
				
				if (bnz_cmp( expr4, tt ) != 0)
				{
					count_not_equal++;
				}


				bnz_clear(expr4);
				bnz_clear(expr5);
			}


			bnz_clear(left);
			bnz_clear(right);
			bnz_clear(border);
			bnz_clear(n);
			bnz_clear(s_temp);

            delete expr1;
            delete expr2;
            delete expr3;


			if ((count_not_in_range > 0) || (count_not_equal > 0))
			{
				return false;
			}
			else
			{	
				return true;
			}
		}



        bool SigmaExp::simulationNeeded()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Sigma::simulationNeeded() is not allowed to be called in not executed code regions when code is collecting!");
            return !w->isSet();
        }

        Message SigmaExp::getPublic()
        {
            return x->getMessage();
        }

        void SigmaExp::R()
        {
            /* FIXME */
        }

	}
}
#endif

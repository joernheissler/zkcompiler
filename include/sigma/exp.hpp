#if 0 // shut up doxygen
#ifndef _SIGMAEXP_HPP_
#define _SIGMAEXP_HPP_

#include "theta/theta.hpp"
#include "sigma/SigmaGsp.hpp"

using namespace ZKCompiler;
using namespace ZKCompiler::sigma;
using namespace std;

namespace ZKCompiler {
    namespace sigma {

        /*! \brief SigmaExp protocol */
        class SigmaExp : public Sigma {
            public:			
                /*! \brief Constructor for prover party 
                 *
                 *	The constructor generates elements for the member variables used.
                 *  The parameters are also saved to member variables.
                 *  The difference R - L is saved to member m.
                 *
                 *  \param phi Homomorphismus that maps elements from G+ to H*
                 *	\param G additive group
                 *  \param H multiplicative group
                 *  \param x public value phi(w)
                 *	\param w secret value
                 *	\param L left border for secret value
                 *	\param R right border for secret value
                 *	\param cplus upper bound for challenge
                 *	\param l security parameter, usually 80 or 100
                 *	\param u number of elements in tuple w (defaults to 1)
                 */	
                SigmaExp(Hom *phi, Theta *theta, Element *x, Element *w, Element *L, Element *R, bnz_t cplus, unsigned int l, unsigned int u = 1);

                /*! \brief Parser constructor
                 *
                 *      This constructor takes a parser configuration.
                 *
                 *  \param p pointer to parser
                 *  \param n Number of parameters
                 *  \param params String array of parameter names
                 */
                SigmaExp(Parser *p, unsigned int n, char *const params[]);

                /*! \brief Destructor for prover party 
                 *
                 *	Frees used memory by deleting Element objects.
                 */
                ~SigmaExp();

                unsigned getCommitmentSize() const;
                void getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned n) const;
                void setCommitment(const CMV::bnz_t* vpSrc[], unsigned n);
                unsigned getResponseSize() const;
                void getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned n) const;
                void setResponse(const CMV::bnz_t* vpSrc[], unsigned n);

                /*! \brief Prover's P1 function 
                 *
                 *	First generates u random numbers and saves them to member
                 *  variable state. The numbers are chosen from the interval 
                 *  [ -2^l * cplus * m_i , 2^l * cplus * m_i ].
                 *  The message r is calculated by phi(state_i)
                 */
                void P1();

                /*! \brief Prover's S function 
                 *
                 *	The simulator for the Sigma Exp protocol is again an extension
                 *  to the GSP simulator. Since the verifier does two range checks, 
                 *  one has to assure that the random values are in those ranges.
                 *  Also, the verifier's V function does two equality checks, testing
                 *  equality for messages t and tt.
                 *  To have a value assigned to xx, it is needed to run the P1 function
                 *  prior to S.
                 */
                void S();

                /*! \brief Get commitment messages 
                 *
                 *  Used to receive the commitment message from the prover object.
                 *  The parameter r is an Element from group H.
                 *
                 *	\param t Commitment messages
                 *	\param xx Commitment messages
                 *	\param tt Commitment messages
                 */
                void getCommitment(Element *t, Element *xx, Element *tt);
                Message getCommitment();

                /*! \brief Prover's P2 function 
                 *
                 *	The prover's P2 function calculates the response and stores
                 *  the result in the member variable s.
                 *
                 *	In difference to the manual, the response is calculated as
                 *  k_i + c * (w_i - L_i).
                 *	Note the + between k_i and c. The manual is considered wrong
                 *  in this equation.
                 */
                void P2();

                /*! \brief Get response messages 
                 *
                 *	The response message, which may be a tuple consisting of 
                 *  various Intgr Elements, is delivered to the parameter s of
                 *  this function.
                 *  This has to be done by using  a lot of dynamic casts by now.
                 *
                 *	\param s Response messages
                 *	\param ss Response messages
                 */
                void getResponse(Element *s, Element *ss);
                Message getResponse();

                /*! \brief Set commitment messages
                 *
                 *	Used to deliver the commitment message generated by the prover
                 *  to the verifier object. 
                 *  The Element parameter r is an Element from group H.
                 *
                 *	\param t Commitment messages
                 *	\param xx Commitment messages
                 *	\param tt Commitment messages
                 */
                void setCommitment(Element *t, Element *xx, Element *tt);
                void setCommitment(Message r);

                /*! \brief Set response messages
                 *
                 *	Used to deliver the response message generated by the prover
                 *  to the verifier object. 
                 *  The Element parameter s is an Element from group G.
                 *
                 *	\param s Response messages
                 *	\param ss Response messages
                 */
                void setResponse(Element *s, Element *ss);
                void setResponse(Message s);

                /*! \brief Verifier's V function 
                 *
                 *	The verifier's V function runs two tests to decide if the response
                 *  leads to an so-called accepting conversation.
                 *	
                 *  The first test is a range test. It is checked, if every single resonse
                 *  comes from the interval [ -2^l * cplus * m_i - cplus * m_i, 2^l * cplus* m_i ].
                 *  To do this, the borders are changed to [ 0, 2 * 2^l * cplus * m_i - cplus * m_i ].
                 *  If a s_i is from outside the interval, V returns false.
                 *  
                 *  The second test does a check if the following equation holds:
                 *  phi(s_i + c*L_i)= r * x^c.
                 *  This, again, is a corrected version from the manual, since it contained errors
                 *  not only in the diagram but also in the definition of the P2 and V functions.
                 *  See the documentation for details on this.
                 *
                 *  \return True if the proof succeeded, false otherwise.
                 */
                CMV::zk_bool_t V(bool interactive);

                /*! \brief Checks whether or not a Sigma protocol needs to be simulated
                 * \returns false: no, true: yes
                 */
                bool simulationNeeded();
                void R();

                Message getPublic();

            private:
                /*! \brief Number of elements in tuple w */
                unsigned int u;
                
                /*! \brief Security parameter 
                 *
                 *  The security parameter is usually set to 80 or 100.
                 *  It applies to the interval the random numbers in the
                 *  prover are chosen from. The interval borders are 
                 *  multiplicated with a factor 2^l.
                 */
                unsigned int l;

                Theta *theta;
                Element *t;

                /*Element *ww;
                  Element *rr;
                  Element *xx;
                  Element *tt;
                  Element *ss;*/

                /*! \brief Left border of interval the secret value lies in */
                Element *L;

                /*! \brief Right border of interval the secret value lies in */
                Element *Rb;

                /*! \brief Difference between right and left border */
                Element *m;

                bnz_t ww, rr, xx, tt, ss;

                /*! \brief Commitment messages */
                Element *r;

                /*! \brief Response messages */
                Element *s;

                /*! \brief Homomorphism to use */
                Hom *phi;

                /*! \brief Public known value */
                Element *x;

                /*! \brief Secret value */
                Element *w;

                /*! \brief state variable */
                Element *state;

        };
    }
}

#endif
#endif

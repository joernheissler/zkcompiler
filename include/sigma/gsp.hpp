#ifndef ZK_SIGMA_GSP_HPP
#define ZK_SIGMA_GSP_HPP

#include "sigma/sigma.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    namespace sigma {

        /*! \brief SigmaGSP protocol */
        class Gsp : public Sigma {
            public:		
                /*! \brief Parser constructor
                 *
                 *      This constructor takes a parser configuration.
                 *
                 *  \param p pointer to parser
                 *  \param n Number of parameters (must be 5)
                 *  \param params String array of parameter names
                 *  expected arguments in params[]:
                 *  phi: name of a homomorphism
                 *  x  : public variable
                 *  w  : secret variable
                 *  c+ : upper border for challenges
                 *  l  : security parameter
                 */
                Gsp(Parser *p, unsigned int n, char *const params[]);

                /*! \brief Destructor for prover party 
                 *
                 *	Frees used memory by deleting Element objects.
                 */
                ~Gsp();

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
                 *	The simulator for the Sigma GSP protocol is very similar to
                 *  the basic Sigma Phi simulator. 
                 *  The only difference is that we need to calculate a value
                 *  s_temp = s-c*L which will be used in order to generate the
                 *  message r.
                 *  Additionally, the message s needs to come from an specified
                 *  interval.
                 */
                void S();

                /*! \brief Get commitment messages 
                 *
                 *  Used to receive the commitment message from the prover object.
                 *
                 *	\return Message
                 */
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
                 */
                Message getResponse();


                /*! \brief Set commitment messages
                 *
                 *	Used to deliver the commitment message generated by the prover
                 *  to the verifier object. 
                 *  The Element parameter r is an Element from group H.
                 *
                 *	\param r Commitment messages
                 */
                void setCommitment(Message r);

                /*! \brief Set response messages
                 *
                 *	Used to deliver the response message generated by the prover
                 *  to the verifier object. 
                 *  The Element parameter s is an Element from group G.
                 *
                 *	\param s Response messages
                 */
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

                void R();

                Message getPublic();
                /*! \brief Checks whether or not a Sigma protocol needs to be simulated
                 * \returns false: no, true: yes
                 */
                bool simulationNeeded();

            private:
                /*! \brief Security parameter 
                 *
                 *  The security parameter is usually set to 80 or 100.
                 *  It applies to the interval the random numbers in the
                 *  prover are chosen from. The interval borders are 
                 *  multiplicated with a factor 2^l.
                 */
                CMV::zk_uint_t l;

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

                /** \brief create a random state
                 ** \param e Element to create random state in
                 **/
                void randomstate(Element *e);
        };
    }
}

#endif

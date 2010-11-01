#ifndef ZK_SIGMA_HPP
#define ZK_SIGMA_HPP

namespace ZKCompiler {
    class Sigma;
}

#include "bignum/bignum.hpp"
#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "hash/hash.hpp"


using namespace ZKCompiler;

namespace ZKCompiler {
    /*! \brief Sigma protocol base class */
        class Sigma {
            public:
                /** Sigma factory
                 ** \param parser pointer to the Parser object; used by the Sigma Protocols
                 ** \param type name of sigma protocol (e.g. "SigmaPhi").
                 **        This object lives until Parser is destroyed.
                 ** \param n number of parameters
                 ** \param params parameters to sigma protocol
                 **        This object lives until Parser is destroyed; must not be changed.
                 ** Creates a new Sigma Object; this function should be used by the Parser.
                 **/
                static Sigma *create(Parser *parser, const char *type, unsigned n, char *const params[]);


                /*! \brief constructor */
                Sigma();

                /*! \brief destructor */
                virtual ~Sigma();


                /*! \brief Prover's P1 function */
                virtual void P1() = 0;

                /*! \brief Prover's P2 function */
                virtual void P2() = 0;

                /*! \brief Verifier's V function */
                CMV::zk_bool_t V();

                /*! \brief Verifier's V function */
                virtual CMV::zk_bool_t V(bool interactive) = 0;

                /*! \brief Prover's S function */
                virtual void S() = 0;

                /*! \brief Compute/Simulate r from public,challenge,response */
                virtual void R() = 0;


                /*! \brief Generate challenges */
                void genChallenge();

                /*! \brief Checks whether or not a Sigma protocol needs to be simulated
                 *  \returns false: no, true: yes
                 */
                virtual bool simulationNeeded() = 0;


                /*! \brief get cplus */
                void getCPlus(CMV::bnz_t& cplus);

                /*! \brief get challenge */
                void getChallenge(CMV::bnz_t& c);

                /*! \brief get challenge */
                const CMV::bnz_t& getChallenge() const;

                /*! \brief Get challenge messages
                 */
                Message getChallenge();

                /** \brief get number of commitments numbers
                 ** \return number of commitments numbers
                 **/
                virtual unsigned getCommitmentSize() const = 0;

                /** \brief copy commitment to an array of const pointers to numbers
                 ** \param vpDst array of pointers to numbers.
                 ** \param n number of pointers in array. Must match size of commitment numbers in this protocol.
                 **/
                virtual void getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned n) const = 0;

                /** \brief get commitment to an array of numbers
                 ** \param vDst array of numbers to be set.
                 ** \param n number of numbers in array. Must match size of commitment numbers in this protocol.
                 **/
                void getCommitment(CMV::bnz_t vDst[], unsigned n) const;

                /*! \brief Get commitment messages
                 */
                virtual Message getCommitment() = 0;

                /** \brief get number of response numbers
                 ** \return number of response numbers
                 **/
                virtual unsigned getResponseSize() const = 0;

                /** \brief copy response to an array of const pointers to numbers
                 ** \param vpDst array of pointers to numbers.
                 ** \param n number of pointers in array. Must match size of response numbers in this protocol.
                 **/
                virtual void getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned n) const = 0;

                /** \brief get response to an array of numbers
                 ** \param vDst array of numbers to be set.
                 ** \param n number of numbers in array. Must match size of response numbers in this protocol.
                 **/
                void getResponse(CMV::bnz_t vDst[], unsigned n) const;

                /*! \brief Get response messages
                 */
                virtual Message getResponse() = 0;

                /*! \brief Get public messages
                 */
                virtual Message getPublic() = 0;

                /*! \brief Get auxiliary commitment
                 *  \return auxiliary commitment
                 */
                virtual Message getAuxCommitment();


                /*! \brief set cplus */
                virtual void setCPlus(const CMV::bnz_t& cplus);

                /*! \brief Set challenge
                 *    \param c Challenge
                 */
                virtual void setChallenge(const CMV::bnz_t& c);

                /*! \brief Set challenge messages
                 *    \param msg Challenge messages
                 */
                void setChallenge(Message msg);

                /** \brief set commitment from an array of pointers to numbers
                 ** \param vpSrc array of pointers to numbers.
                 ** \param n number of pointers in array. Must match size of commitment numbers in this protocol.
                 **/
                virtual void setCommitment(const CMV::bnz_t* vpSrc[], unsigned n) = 0;

                /** \brief set commitment from an array numbers
                 ** \param vSrc array of numbers.
                 ** \param n number of numbers in array. Must match size of commitment numbers in this protocol.
                 **/
                void setCommitment(const CMV::bnz_t vSrc[], unsigned n);

                /*! \brief Set commitment messages
                 *    \param msg Commitment messages
                 */
                virtual void setCommitment(Message msg) = 0;

                /** \brief set response from an array of pointers to numbers
                 ** \param vpSrc array of pointers to numbers.
                 ** \param n number of pointers in array. Must match size of response numbers in this protocol.
                 **/
                virtual void setResponse(const CMV::bnz_t* vpSrc[], unsigned n) = 0;

                /** \brief set response from an array of numbers
                 ** \param vSrc array of numbers.
                 ** \param n number of numbers in array. Must match size of response numbers in this protocol.
                 **/
                void setResponse(const CMV::bnz_t vSrc[], unsigned n);

                /*! \brief Set response messages
                 *    \param msg Response messages
                 */
                virtual void setResponse(Message msg) = 0;

                /*! \brief Set auxiliary commitment
                 *  \param msg auxiliary commitment
                 */
                virtual void setAuxCommitment(Message msg);


                /*! \brief create a noninteractive signature */
                Message sign(Hash *h);

                /*! \brief verify a noninteractive signature */
                bool verify(Hash *h, Message sig);

            protected:
                /*! \brief cplus */
                CMV::bnz_t cplus;

                /*! \brief Challenge */
                CMV::bnz_t c;
        };
}


#endif

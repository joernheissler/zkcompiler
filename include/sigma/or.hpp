#ifndef ZK_SIGMA_OR_HPP
#define ZK_SIGMA_OR_HPP

#include "sigma/sigma.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    namespace sigma {

        /*! \brief OR composition of Sigma protocols */
        class Or : public Sigma {
            public:

                /*! \brief Constructor parser mode *
                 *  \param p pointer to Parser object
                 *  \param n Number of parameters (must be at least 1)
                 *  \param params String array of parameter names
                 *
                 *  expected arguments in params[]: n names of sigma protocols
                 */
                Or(Parser *p, unsigned int n, char *const params[]);

                ~Or();

                unsigned getCommitmentSize() const;
                void getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned n) const;
                void setCommitment(const CMV::bnz_t* vpSrc[], unsigned n);
                unsigned getResponseSize() const;
                void getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned n) const;
                void setResponse(const CMV::bnz_t* vpSrc[], unsigned n);

                void P1();
                void P2();
                CMV::zk_bool_t V(bool interactive);
                void S();
                void R();

                void setCPlus(const CMV::bnz_t& cplus);
                void setCommitment(Message r);
                void setResponse(Message s);
                void setAuxCommitment(Message msg);

                Message getCommitment();
                Message getResponse();
                Message getPublic();
                Message getAuxCommitment();
                /*! \brief Checks whether or not a Sigma protocol needs to be simulated
                 * \returns false: no, true: yes
                 */
                bool simulationNeeded();

            private:
                /** \brief array of sub proofs **/
                Sigma **proofs;
                /** \brief number of sub proofs **/
                unsigned int n;
                /** \brief remember which sigma doesn't have to be simulated **/
                unsigned int known_sigma;

        };
    }
}


#endif

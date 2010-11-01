#ifndef ZK_SIGMA_LIPMAA_HPP
#define ZK_SIGMA_LIPMAA_HPP

#include "sigma/sigma.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    namespace sigma {
        class Lipmaa : public Sigma {
            public:
                Lipmaa(Parser *p, unsigned int n, char *const params[]);
                ~Lipmaa();
                void P1();
                void P2();
                CMV::zk_bool_t V(bool interactive);
                void S();
                void R();
                bool simulationNeeded();
                Message getCommitment();
                Message getResponse();
                Message getPublic();
                Message getAuxCommitment();
                void setCommitment(Message msg);
                void setResponse(Message msg);
                void setAuxCommitment(Message msg);
                
                unsigned getCommitmentSize() const;
                void getCommitmentPtrs(const CMV::bnz_t* vpDst[], unsigned n) const;
                void setCommitment(const CMV::bnz_t* vpSrc[], unsigned n);
                unsigned getResponseSize() const;
                void getResponsePtrs(const CMV::bnz_t* vpDst[], unsigned n) const;
                void setResponse(const CMV::bnz_t* vpSrc[], unsigned n);
            private:
        };
    }
}

#endif

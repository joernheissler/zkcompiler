#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_ZK_C_CODE_TESTER_HPP
#define ZK_ZK_C_CODE_TESTER_HPP

#include <gmp.h>

extern "C"
{
    #include "zk_prover.h"
    #include "zk_verifier.h"
}

#include "random/random.hpp"

namespace ZKCompiler
{
    class ZKCCodeTester
    {
    public:
        static void initMPZsArray(mpz_t*& rpMPZs, unsigned int size, const char* vpInit[] = NULL);
        static void clearMPZsArray(mpz_t* pMPZs, unsigned int size);
        static void printMPZsArray(mpz_t* pMPZs, unsigned int size, const char* pIdent);
        static bool test(zk_bool vVerification[1]);
    };
}

#endif

#endif

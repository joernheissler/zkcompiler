#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ZKCCodeTester.hpp"

#include <cstdio>
#include "random/random.hpp"

using namespace ZKCompiler;

void zk_handle_error(zk_pcchar pMessage, zk_pcchar srcFileName, zk_int srcLine, zk_pcchar fileName, zk_int line)
{
    printf("%s:%d: error in zk - original message of ZKCompiler:\n", fileName, line);
    printf("%s:%d: error: %s\n", srcFileName, srcLine, pMessage);
}

void zk_Random_range(mpz_t d, const mpz_t min, const mpz_t max)
{
    bnz_t bnD(*d);
    Random::range(bnD, bnz_t(*min), bnz_t(*max));
}

void zk_Random_range0(mpz_t d, const mpz_t max)
{
    bnz_t bnD(*d);
    Random::range0(bnD, bnz_t(*max));
}

void zk_Random_irange(mpz_t d, const mpz_t min, const mpz_t max)
{
    bnz_t bnD(*d);
    Random::irange(bnD, bnz_t(*min), bnz_t(*max));
}

void zk_Random_irange0(mpz_t d, const mpz_t max)
{
    bnz_t bnD(*d);
    Random::irange0(bnD, bnz_t(*max));
}

void ZKCCodeTester::initMPZsArray(mpz_t*& rpMPZs, unsigned int size, const char* vpInit[])
{
    rpMPZs = new mpz_t[size];
    for (unsigned int i = 0; i < size; ++i)
    {
        if (vpInit != NULL)
            mpz_init_set_str(rpMPZs[i], vpInit[i], 10);
        else
            mpz_init(rpMPZs[i]);
    }
}

void ZKCCodeTester::clearMPZsArray(mpz_t* pMPZs, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
        mpz_clear(pMPZs[i]);
    delete[] pMPZs;
}

void ZKCCodeTester::printMPZsArray(mpz_t* pMPZs, unsigned int size, const char* pIdent)
{
    printf("vStr_%s[] = {", pIdent);
    for (unsigned i = 0; i < size; ++i)
    {
        printf("\"");
        mpz_out_str(NULL, 10, pMPZs[i]);
        printf("\"%s", i + 1 == size ? "}\n" : ", ");
    }
}

bool ZKCCodeTester::test(zk_bool vVerification[1])
{
    bool noErrors = false;
    do
    {
        /* We assume the protocol is already initialized! */

        /* Execute protocol... */
        printf("Execute...\n");
        mpz_t* pCommitment;
        initMPZsArray(pCommitment, zk_argSize_vCommitment);
        noErrors = zk_Prover_p1(pCommitment);
        if (!noErrors)
        {
            clearMPZsArray(pCommitment, zk_argSize_vCommitment);
            break;
        }
        printMPZsArray(pCommitment, zk_argSize_vCommitment, "vCommitment");

        mpz_t* pChallenge;
        initMPZsArray(pChallenge, zk_argSize_vChallenge);
        noErrors = zk_Verifier_c(pChallenge, pCommitment);
        clearMPZsArray(pCommitment, zk_argSize_vCommitment);
        if (!noErrors)
        {
            clearMPZsArray(pChallenge, zk_argSize_vChallenge);
            break;
        }
        printMPZsArray(pChallenge, zk_argSize_vChallenge, "vChallenge");

        mpz_t* pResponse;
        initMPZsArray(pResponse, zk_argSize_vResponse);
        noErrors = zk_Prover_p2(pResponse, pChallenge);
        clearMPZsArray(pChallenge, zk_argSize_vChallenge);
        if (!noErrors)
        {
            clearMPZsArray(pResponse, zk_argSize_vResponse);
            break;
        }
        printMPZsArray(pResponse, zk_argSize_vResponse, "vResponse");

        noErrors = zk_Verifier_v(vVerification, pResponse);
        clearMPZsArray(pResponse, zk_argSize_vResponse);
        if (!noErrors)
            break;
    }
    while (false);

    /* Free protocol... */
    printf("Free prover and verifier...\n");
    zk_Prover_free();
    zk_Verifier_free();

    return noErrors;
}

#endif

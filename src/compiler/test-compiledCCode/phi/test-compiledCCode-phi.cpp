#include "ZKCCodeTester.hpp"

using namespace ZKCompiler;

bool initZKProver(const char* vStr_vSecret_w[], const char* vStr_vPublicCommitment_x[])
{
    bool noErrors = false;

    mpz_t* pSecret_w;
    mpz_t* pPublicCommitment_x;
    ZKCCodeTester::initMPZsArray(pSecret_w, zk_argSize_vSecret_w, vStr_vSecret_w);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, vStr_vPublicCommitment_x);
    ZKCCodeTester::printMPZsArray(pSecret_w, zk_argSize_vSecret_w, "vSecret_w");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, "vPublicCommitment_x");
    noErrors = zk_Prover_init(pPublicCommitment_x, pSecret_w);
    ZKCCodeTester::clearMPZsArray(pSecret_w, zk_argSize_vSecret_w);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x);

    return noErrors;
}

bool initZKVerifier(const char* vStr_vPublicCommitment_x[])
{
    bool noErrors = false;

    mpz_t* pPublicCommitment_x;
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, vStr_vPublicCommitment_x);
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, "vPublicCommitment_x");
    noErrors = zk_Verifier_init(pPublicCommitment_x);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x);

    return noErrors;
}

#define TEST_CHECK(msg, expVer, retVal) \
    {\
        printf("%s\n", (msg));\
        if ((retVal) && (expVer) == verification)\
        {\
            printf("OK\n");\
        }\
        else\
        {\
            printf("FAIL\n");\
            ret = 1;\
        }\
    } (void)0

int main()
{
    int ret = 0;
    zk_bool verification = false;

    const char* vStr_vSecret_w[] = {"250", "458"};
    const char* vStr_wrong_vSecret_w[] = {"454", "92"};
    const char* vStr_vPublicCommitment_x[] = {"772"};

    Random::init();
    TEST_CHECK(">>> posive test <<<", true,
            initZKProver(vStr_vSecret_w, vStr_vPublicCommitment_x) &&
            initZKVerifier(vStr_vPublicCommitment_x) &&
            ZKCCodeTester::test(&verification));
    TEST_CHECK(">>> negative test <<<", false,
            initZKProver(vStr_wrong_vSecret_w, vStr_vPublicCommitment_x) &&
            initZKVerifier(vStr_vPublicCommitment_x) &&
            ZKCCodeTester::test(&verification));
    Random::free();

    return ret;
}

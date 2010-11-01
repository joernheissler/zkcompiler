#include "ZKCCodeTester.hpp"

using namespace ZKCompiler;

bool initZKProver(const char* vStr_vSecret_w0[], const char* vStr_vSecret_w1[], const char* vStr_vSecret_w2[],
        const char* vStr_vPublicCommitment_x0[], const char* vStr_vPublicCommitment_x1[], const char* vStr_vPublicCommitment_x2[])
{
    bool noErrors = false;

    mpz_t* pSecret_w0;
    mpz_t* pSecret_w1;
    mpz_t* pSecret_w2;
    mpz_t* pPublicCommitment_x0;
    mpz_t* pPublicCommitment_x1;
    mpz_t* pPublicCommitment_x2;
    ZKCCodeTester::initMPZsArray(pSecret_w0, zk_argSize_vSecret_w0, vStr_vSecret_w0);
    ZKCCodeTester::initMPZsArray(pSecret_w1, zk_argSize_vSecret_w1, vStr_vSecret_w1);
    ZKCCodeTester::initMPZsArray(pSecret_w2, zk_argSize_vSecret_w2, vStr_vSecret_w2);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x0, zk_argSize_vPublicCommitment_x0, vStr_vPublicCommitment_x0);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x1, zk_argSize_vPublicCommitment_x1, vStr_vPublicCommitment_x1);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x2, zk_argSize_vPublicCommitment_x2, vStr_vPublicCommitment_x2);
    ZKCCodeTester::printMPZsArray(pSecret_w0, zk_argSize_vSecret_w0, "vSecret_w0");
    ZKCCodeTester::printMPZsArray(pSecret_w1, zk_argSize_vSecret_w1, "vSecret_w1");
    ZKCCodeTester::printMPZsArray(pSecret_w2, zk_argSize_vSecret_w2, "vSecret_w2");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x0, zk_argSize_vPublicCommitment_x0, "vPublicCommitment_x0");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x1, zk_argSize_vPublicCommitment_x1, "vPublicCommitment_x1");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x2, zk_argSize_vPublicCommitment_x2, "vPublicCommitment_x2");
    noErrors = zk_Prover_init(pPublicCommitment_x0, pPublicCommitment_x1, pPublicCommitment_x2,
        pSecret_w0, pSecret_w1, pSecret_w2);
    ZKCCodeTester::clearMPZsArray(pSecret_w0, zk_argSize_vSecret_w0);
    ZKCCodeTester::clearMPZsArray(pSecret_w1, zk_argSize_vSecret_w1);
    ZKCCodeTester::clearMPZsArray(pSecret_w2, zk_argSize_vSecret_w2);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x0, zk_argSize_vPublicCommitment_x0);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x1, zk_argSize_vPublicCommitment_x1);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x2, zk_argSize_vPublicCommitment_x2);

    return noErrors;
}

bool initZKVerifier(const char* vStr_vPublicCommitment_x0[], const char* vStr_vPublicCommitment_x1[], const char* vStr_vPublicCommitment_x2[])
{
    bool noErrors = false;

    mpz_t* pPublicCommitment_x0;
    mpz_t* pPublicCommitment_x1;
    mpz_t* pPublicCommitment_x2;
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x0, zk_argSize_vPublicCommitment_x0, vStr_vPublicCommitment_x0);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x1, zk_argSize_vPublicCommitment_x1, vStr_vPublicCommitment_x1);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x2, zk_argSize_vPublicCommitment_x2, vStr_vPublicCommitment_x2);
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x0, zk_argSize_vPublicCommitment_x0, "vPublicCommitment_x0");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x1, zk_argSize_vPublicCommitment_x1, "vPublicCommitment_x1");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x2, zk_argSize_vPublicCommitment_x2, "vPublicCommitment_x2");
    noErrors = zk_Verifier_init(pPublicCommitment_x0, pPublicCommitment_x1, pPublicCommitment_x2);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x0, zk_argSize_vPublicCommitment_x0);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x1, zk_argSize_vPublicCommitment_x1);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x2, zk_argSize_vPublicCommitment_x2);

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

    const char* vStr_vSecret_w0[] = {"346", "381"};
    const char* vStr_vSecret_w1[] = {"114", "96"};
    const char* vStr_vSecret_w2[] = {"83", "166"};
    const char* vStr_wrong_vSecret_w2[] = {"227", "422"};
    const char* vStr_vPublicCommitment_x0[] = {"222"};
    const char* vStr_vPublicCommitment_x1[] = {"725"};
    const char* vStr_vPublicCommitment_x2[] = {"720"};

    Random::init();
    TEST_CHECK(">>> posive test <<<", true,
            initZKProver(vStr_vSecret_w0, vStr_vSecret_w1, vStr_vSecret_w2,
                    vStr_vPublicCommitment_x0, vStr_vPublicCommitment_x1, vStr_vPublicCommitment_x2) &&
            initZKVerifier(vStr_vPublicCommitment_x0, vStr_vPublicCommitment_x1, vStr_vPublicCommitment_x2) &&
            ZKCCodeTester::test(&verification));
    TEST_CHECK(">>> negative test <<<", false,
            initZKProver(vStr_vSecret_w0, vStr_vSecret_w1, vStr_wrong_vSecret_w2,
                    vStr_vPublicCommitment_x0, vStr_vPublicCommitment_x1, vStr_vPublicCommitment_x2) &&
            initZKVerifier(vStr_vPublicCommitment_x0, vStr_vPublicCommitment_x1, vStr_vPublicCommitment_x2) &&
            ZKCCodeTester::test(&verification));
    Random::free();

    return ret;
}

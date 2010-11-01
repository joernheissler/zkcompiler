//#define CM_ENABLE_CODE_COLLECTING
#include <cstdlib>
#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "util/errorhandling.hpp"
#include "util/foursquares.hpp"
#include "util/zkprint.hpp"
#include "random/random.hpp"

#include "CodeManagement/core/impl/CodeCollector.hpp"
#include "CodeManagement/misc/stream/impl/FileStream.hpp"
#include "CodeManagement/misc/stream/impl/Logger.hpp"
#include "compiler/ZKFileToProgramCCRCompiler.hpp"
#include "compiler/ZKProgramCCRTester.hpp"
#include "compiler/ProgramCCRtoCCodeCompiler.hpp"

CM_INIT_CODE_MANAGER;

using namespace CodeManagement;
using namespace ZKCompiler;

#define CHECK(msg, exp, val) \
    {\
        printf("%s\n", (msg));\
        if ((exp) == (val))\
        {\
            printf("OK\n");\
        }\
        else\
        {\
            printf("FAIL\n");\
            ret = 1;\
        }\
    } (void)0

int main(int argc, char *argv[])
{
    int ret = 0;
    if (argc != 3)
    {
        printf("I need the .zk file and the output directory as parameter!\n");
        return 1;
    }
    try
    {
        // Compile the protocol to CCR.
        printf("Compiling from zk-file to ccr-structure...\n");
        ZKFileToProgramCCRCompiler zkToCCR(argv[1], "sigma");
        zkToCCR.getSecretVars().push_back("w");
        zkToCCR.getPublicCommitmentVars().push_back("x");
        zkToCCR.getAuxVars().push_back("gi");

        CodeCollector proverCC("prover");
        zkToCCR.compileProver(proverCC);

        CodeCollector verifierCC("verifier");
        zkToCCR.compileVerifier(verifierCC);

        // Test the compiled CCR.
        printf("Testing compiled ccr-structure...\n");
        ZKProgramCCRTester tester(zkToCCR);

        Random::init();
        Parser *p = Parser::fromFile(argv[1]);

        Element *w = p->getVar("w");
        Element *x = p->getVar("x");
        Element *wi = p->getElement("Gx9");
        bnz_t secret[9];
        CMV(bnz_t tmp);
        bnz_init_set_str(secret[0], "31337", 0);
        for(int i = 1; i < 9; ++i) bnz_init(secret[i]);
        CMI(bnz_init(tmp));

        p->getVar("a")->get(tmp);
        CMI(bnz_sub(tmp, CMV_IN(secret[0]), tmp));
        foursquares(secret[1], secret[2], secret[3], secret[4], CMV_OUT(tmp));

        p->getVar("b")->get(tmp);
        CMI(bnz_sub(tmp, tmp, CMV_IN(secret[0])));
        foursquares(secret[5], secret[6], secret[7], secret[8], CMV_OUT(tmp));

        CMI(bnz_clear(tmp));

        CMV::bnz_t* pTmp;
        CMV_NEW_ARRAY(pTmp, bnz_t, 9);
        for (int i = 0; i < 9; ++i)
            CMI(bnz_init_set(pTmp[i], CMV_IN(secret[i])));
        wi->set(pTmp, 9);
        for (int i = 0; i < 9; ++i)
            CMI(bnz_clear(pTmp[i]));
        CMV_DELETE_ARRAY(pTmp, bnz_t, 9);

        for(int i = 0; i < 9; ++i) bnz_clear(secret[i]);
        wi->print(); printf("\n");

        p->map("gi","phi_H_inverse","g");

        p->getVar("gi")->print();

        w->map(p->getHom("phi_W"), wi);
        w->print();

        delete wi;
        x->map(p->getHom("phi_W_X"), w);
        x->print();

        CHECK(">>> posive test <<<", true, tester.test(*p, *p, proverCC.getProgram(), verifierCC.getProgram()));
        // FIXME: set a fix wrong value for w!
        w->random();
        CHECK(">>> negative test <<<", false, tester.test(*p, *p, proverCC.getProgram(), verifierCC.getProgram()));

        delete p;

        Random::free();

        // Compile the CCR to c-code.
        printf("Compiling from ccr-structure to c-code...\n");
        ProgramCCRtoCCodeCompiler ccrToC;
        DebugInfo::setOutStreamShowFileNameAndLine(false);
        ccrToC.setShowDebugInfo(true);

        std::string dir = argv[2];
        ::system((std::string("mkdir -p \"") + dir + "\"").c_str());

        FileStream proverCSourceFile((dir + "/zk_prover.c").c_str());
        FileStream proverCHeaderFile((dir + "/zk_prover.h").c_str());
        ccrToC.compile(proverCC.getProgram(), &proverCSourceFile, &proverCHeaderFile, "zk_prover.h");

        FileStream verifierCSourceFile((dir + "/zk_verifier.c").c_str());
        FileStream verifierCHeaderFile((dir + "/zk_verifier.h").c_str());
        ccrToC.compile(verifierCC.getProgram(), &verifierCSourceFile, &verifierCHeaderFile, "zk_verifier.h");
    }
    catch (...)
    {
        ret = 2;
    }
    return ret;
}

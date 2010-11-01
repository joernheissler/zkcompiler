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
        zkToCCR.getSecretVars().push_back("w0");
        zkToCCR.getSecretVars().push_back("w1");
        zkToCCR.getSecretVars().push_back("w2");
        zkToCCR.getPublicCommitmentVars().push_back("x0");
        zkToCCR.getPublicCommitmentVars().push_back("x1");
        zkToCCR.getPublicCommitmentVars().push_back("x2");

        CodeCollector proverCC("prover");
        zkToCCR.compileProver(proverCC);

        CodeCollector verifierCC("verifier");
        zkToCCR.compileVerifier(verifierCC);

        // Test the compiled CCR.
        printf("Testing compiled ccr-structure...\n");
        ZKProgramCCRTester tester(zkToCCR);

        Random::init();
        Parser *pAuxParser  = Parser::fromFile(argv[1]);

        pAuxParser->getVar("w0")->random();
        pAuxParser->getVar("w1")->random();
        pAuxParser->getVar("w2")->random();
        pAuxParser->map("x0","phi","w0");
        pAuxParser->map("x1","phi","w1");
        pAuxParser->map("x2","phi","w2");
        CHECK(">>> posive test <<<", true, tester.test(*pAuxParser, *pAuxParser, proverCC.getProgram(), verifierCC.getProgram()));
        // FIXME: set fix wrong values!
        pAuxParser->getVar("w2")->random();
        CHECK(">>> negative test <<<", false, tester.test(*pAuxParser, *pAuxParser, proverCC.getProgram(), verifierCC.getProgram()));

        delete pAuxParser;

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

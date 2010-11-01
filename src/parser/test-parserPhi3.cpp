#include <cstring>
#include <iomanip>
#include <stdio.h>
#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"
#include "random/random.hpp"

CM_INIT_CODE_MANAGER;

using namespace std;
using namespace ZKCompiler;


int main(int argc, char *argv[])
{
    int ret;
    if(argc != 2) {
        printf("I need the .zk file as parameter!\n");
        return 1;
    }
    try {
        Random::init();
        Message msg;
        
        /* initialize prover */
        Parser *prover   = Parser::fromFile(argv[1]);
        Sigma *prover_s = prover->getSigma("sigma");

        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);
        Sigma *verifier_s = verifier->getSigma("sigma");
        
        /* verifier chooses a random x */
        verifier->getVar("x")->random();

        /* transmit public value x from verifier to prover */
        msg = verifier->getVar("x")->get();
        printHex(msg, "x");
        prover->getVar("x")->set(msg);
        delete[] msg.data;

        if(!prover_s->simulationNeeded()) {
            printf("simulationNeeded==false but should be true\n");
            return 1;
        }

        /* prover generates challenge */
        prover_s->genChallenge();

        /* prover calls S */
        prover_s->S();

        /* transmit commitment from prover to verifier */
        msg = prover_s->getCommitment();
        printHex(msg, "r");
        verifier_s->setCommitment(msg);
        delete[] msg.data;

        /* transmit challenge from prover to verifier */
        msg = prover_s->getChallenge();
        printHex(msg, "c");
        verifier_s->setChallenge(msg);
        delete[] msg.data;

        /* transmit response from prover to verifier */
        msg = prover_s->getResponse();
        printHex(msg, "s");
        verifier_s->setResponse(msg);
        delete[] msg.data;

        /* verifier calls V */
        if(CMV_OUT(verifier_s->V())) {
            printf("OK\n");
            ret = 0;
        } else {
            printf("Verification failed\n");
            ret = 1;
        }

        delete verifier_s;
        delete verifier;
        delete prover_s;
        delete prover;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 2;
    }
    return ret;
}

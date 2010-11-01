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

        /* prover chooses a random w and calculates x */
        prover->getVar("w")->random();
        prover->map("x","phi","w");
        
        /* change w to a wrong value */
        Element *w = prover->getVar("w");
        w->op(w, prover->getVar("v"));

        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);
        Sigma *verifier_s = verifier->getSigma("sigma");

        /* transmit public value x from prover to verifier */
        msg = prover->getVar("x")->get();
        printHex(msg, "x");
        verifier->getVar("x")->set(msg);
        delete[] msg.data;

        if(prover_s->simulationNeeded()) {
            printf("simulationNeeded==true but should be false\n");
            return 1;
        }

        /* prover calls P1 */
        prover_s->P1();

        /* transmit commitment from prover to verifier */
        msg = prover_s->getCommitment();
        printHex(msg, "r");
        verifier_s->setCommitment(msg);
        delete[] msg.data;

        /* verifier generates challenge */
        verifier_s->genChallenge();

        /* transmit challenge from verifier to prover */
        msg = verifier_s->getChallenge();
        printHex(msg, "c");
        prover_s->setChallenge(msg);
        delete[] msg.data;

        /* prover calls P2 */
        prover_s->P2();

        /* transmit response from prover to verifier */
        msg = prover_s->getResponse();
        printHex(msg, "s");
        verifier_s->setResponse(msg);
        delete[] msg.data;

        /* verifier calls V */
        if(CMV_OUT(verifier_s->V())) {
            printf("Verification succeeded, but should not have.\n");
            ret = 1;
        } else {
            printf("OK\n");
            ret = 0;
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

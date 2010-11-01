#include <cstring>
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
    if(argc != 3) {
        printf("I need the .zk files as parameters!\n");
        return 1;
    }
    struct ProxyLookup proxy;
    const char *groups[] = { "G", "H", 0 };
    const char *vars[] = { "g", "x", "w", 0 };
    const char *homs[] = { "phi", 0 };
    const char *sigmas[] = { "sigma", 0 };
    proxy.groups = groups;
    proxy.vars = vars;
    proxy.homs = homs;
    proxy.sigmas = sigmas;

    try {
        Random::init();
        Message msg;
        
        /* initialize prover */
        Parser *prover0  = Parser::fromFile(argv[1]);
        proxy.p = prover0;
        Parser *prover1  = Parser::fromFile(argv[2], &proxy);
        Sigma *prover_s = prover1->getSigma("sigma");

        /* prover chooses a random w and calculates x */
        prover0->getVar("w")->random();
        prover0->map("x","phi","w");
        
        prover1->getVar("w")->random();
        prover1->map("x","phi","w");

        /* initialize verifier */
        Parser *verifier0 = Parser::fromFile(argv[1]);
        proxy.p = verifier0;
        Parser *verifier1 = Parser::fromFile(argv[2], &proxy);
        Sigma *verifier_s = verifier1->getSigma("sigma");

        /* transmit public value x from prover to verifier */
        msg = prover0->getVar("x")->get();
        printHex(msg, "x0");
        verifier0->getVar("x")->set(msg);
        delete[] msg.data;
        msg = prover1->getVar("x")->get();
        printHex(msg, "x1");
        verifier1->getVar("x")->set(msg);
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
            printf("OK\n");
            ret = 0;
        } else {
            printf("Verification failed\n");
            ret = 1;
        }

        delete verifier_s;
        delete verifier1;
        delete verifier0;
        delete prover_s;
        delete prover1;
        delete prover0;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 2;
    }
    return ret;
}


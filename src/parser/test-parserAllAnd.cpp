#include <cstring>
#include <iomanip>
#include <stdio.h>
#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"
#include "random/random.hpp"
#include "hash/sha1.hpp"

CM_INIT_CODE_MANAGER;

using namespace std;
using namespace ZKCompiler;


bool noninter(Sigma *p, Sigma *v)
{
    Message sig;
    Hash *h;
    bool ret;
    
    /* prover creates a hash function object */
    h = new SHA1();
    /* prover creates a signature */
    sig = p->sign(h);
    delete h;

    /* verifier creates a hash function object */
    h = new SHA1();
    /* verifier verifies the signature */
    ret = v->verify(h, sig);
    delete h;

    /* delete signature */
    delete[] sig.data;
    delete p;
    delete v;

    return ret;
}

bool inter(Sigma *p, Sigma *v)
{
    Message msg;
    bool ret;

    if(p->simulationNeeded()) {
        printf("simulationNeeded==true but should be false\n");
        ret = false;
        goto out;
    }
    
    /* prover calls P1 */
    p->P1();
    
    /* transmit commitment from prover to verifier */
    msg = p->getCommitment();
    printHex(msg, "r");
    v->setCommitment(msg);
    delete[] msg.data;

    /* verifier generates challenge */
    v->genChallenge();

    /* transmit challenge from verifier to prover */
    msg = v->getChallenge();
    printHex(msg, "c");
    p->setChallenge(msg);
    delete[] msg.data;

    /* prover calls P2 */
    p->P2();

    /* transmit response from prover to verifier */
    msg = p->getResponse();
    printHex(msg, "s");
    v->setResponse(msg);
    delete[] msg.data;

    /* verifier calls V */
    ret = CMV_OUT(v->V());
out:
    delete p;
    delete v;
    return ret;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("I need the .zk file as parameter!\n");
        return 6;
    }
    try {
        Random::init();
        Message msg;
        
        /* initialize prover */
        Parser *prover  = Parser::fromFile(argv[1]);
        
        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);

        struct { const char *w, *x, *h; } wx[] = { {"w0a","x0a","phi0a"}, {"w0b","x0b","phi0b"}, {"w0c","x0c","phi0c"}, {"w0d","x0d","phi0d"},
                                                   {"w1a","x1a","phi1a"}, {"w1b","x1b","phi1b"}, {"w1c","x1c","phi1c"},
                                                   {"w2a","x2a","phi1a"}, {"w2b","x2b","phi1b"}, {"w2c","x2c","phi1c"},
                                                   {0, 0, 0} };
        
        for(int i = 0; wx[i].w; ++i) {
            /* choose random witnesses */
            prover->getVar(wx[i].w)->random();

            /* calculate public value */
            prover->map(wx[i].x, wx[i].h, wx[i].w);

            /* transmit public value to verifier */
            msg = prover->getVar(wx[i].x)->get();
            printHex(msg, wx[i].x);
            verifier->getVar(wx[i].x)->set(msg);
            delete[] msg.data;
        }

        printf("sub test 1/4\n");
        printf("testing interactive And (Phi, Phi, Phi, Phi) proof\n");
        if(inter(prover->getSigma("s0"), verifier->getSigma("s0"))) printf("OK\n"); else { printf("fail\n"); return 1; }
        printf("\n");

        printf("sub test 2/4\n");
        printf("testing non-interactive And (Phi, Phi, Phi, Phi) proof\n");
        if(noninter(prover->getSigma("s0"), verifier->getSigma("s0"))) printf("OK\n"); else { printf("fail\n"); return 2; }
        printf("\n");

        printf("sub test 3/4\n");
        printf("testing interactive And (Gsp, Gsp, Gsp) proof\n");
        if(inter(prover->getSigma("s1"), verifier->getSigma("s1"))) printf("OK\n"); else { printf("fail\n"); return 3; }
        printf("\n");

        printf("sub test 4/4\n");
        printf("testing non-interactive And (Gsp, Gsp, Gsp) proof\n");
        if(noninter(prover->getSigma("s1"), verifier->getSigma("s1"))) printf("OK\n"); else { printf("fail\n"); return 4; }
        printf("\n");

        // SigmaExp Protocol is not working yet!!!		
        // printf("sub test 5/5\n");
        // sprintf("testing interactive And (Exp, Exp, Exp) proof\n");
        // if(inter(prover->getSigma("s2"), verifier->getSigma("s2"))) printf("OK\n"); else { printf("fail\n"); return 5; }
        // printf("\n");

        delete verifier;
        delete prover;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 6;
    }
    return 0;
}

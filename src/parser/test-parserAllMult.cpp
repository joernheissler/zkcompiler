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
        return 7;
    }
    try {
        Random::init();
        Message msg;
        
        /* initialize prover */
        Parser *prover  = Parser::fromFile(argv[1]);
        
        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);

        /* prover chooses random values for w0,w1,p; phi, gsp */
        prover->getVar("wi" )->random();
        prover->getVar("wzi")->random();

        /* prover calculates w2 = w0*w1, random numbers for commitments, etc. */
        prover->map("w","phi_G3_GW","wi");
        prover->map("wz","phi_GZI_GZW","wzi");

        /* prover calculates public values x,x0,x1,x2 */
        prover->map("x4","phi_GW_H4","w");
        prover->map("xz4","phi_GZW_H4","wz");

        /* transmit public value (x,x0,x1,x2) to verifier */
        msg = prover->getVar("x4")->get();
        printHex(msg, "x4");
        verifier->getVar("x4")->set(msg);
        delete[] msg.data;
        
        msg = prover->getVar("xz4")->get();
        printHex(msg, "xz4");
        verifier->getVar("xz4")->set(msg);
        delete[] msg.data;

        /* prover and verifier expand x4 to real public value x */
        prover->map("x","phi_H4_H5","x4");
        verifier->map("x","phi_H4_H5","x4");
        prover->map("xz","phi_H4_H5","xz4");
        verifier->map("xz","phi_H4_H5","xz4");

        /* now, everything is ready for the proofs */

        printf("sub test 1/4\n");
        printf("testing interactive Mult/Phi proof\n");
        if(inter(prover->getSigma("sphi"), verifier->getSigma("sphi"))) printf("OK\n"); else { printf("fail\n"); return 1; }
        printf("\n");

        printf("sub test 2/4\n");
        printf("testing non-interactive Mult/Phi proof\n");
        if(noninter(prover->getSigma("sphi"), verifier->getSigma("sphi"))) printf("OK\n"); else { printf("fail\n"); return 2; }
        printf("\n");

        printf("sub test 3/4\n");
        printf("testing interactive Mult/Gsp proof\n");
        if(inter(prover->getSigma("sgsp"), verifier->getSigma("sgsp"))) printf("OK\n"); else { printf("fail\n"); return 3; }
        printf("\n");

        printf("sub test 4/4\n");
        printf("testing non-interactive Mult/Gsp proof\n");
        if(noninter(prover->getSigma("sgsp"), verifier->getSigma("sgsp"))) printf("OK\n"); else { printf("fail\n"); return 4; }
        printf("\n");

        // SigmaExp Protocol is not working yet!!!		
        // printf("sub test 5/5\n");
        // printf("testing interactive Mult/Exp proof\n");
        // if(inter(prover->getSigma("sexp"), verifier->getSigma("sexp"))) printf("OK\n"); else { printf("fail\n"); return 5; }
        // printf("\n");

        delete verifier;
        delete prover;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 7;
    }
    return 0;
}

#include <cstring>
#include <iomanip>
#include <stdio.h>
#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"
#include "random/random.hpp"
#include "util/foursquares.hpp"
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

Message init_prover(Parser *p, const char *w_value)
{
        CMV::bnz_t* pSecret;
        CMV_NEW_ARRAY(pSecret, bnz_t, 9);
        CMV::bnz_t* pSec;
        CMV_NEW_ARRAY(pSec, bnz_t, 2);
        
        CMI(bnz_init_set_str(pSec[0], CMV_IN(w_value), CMV_IN(0)));
        CMI(bnz_init(pSec[1]));

        Element *m = p->getElement("Gp");
        m->random();
        m->get(pSec[1]);
        delete m;

        for(int i = 0; i < 9; ++i) CMI(bnz_init(pSecret[i]));

        CMV(bnz_t tmp);
        CMI(bnz_init(tmp));
        p->getVar("min")->get(tmp);
        CMI(bnz_sub(tmp, pSec[0], tmp));
        CMI(foursquares(pSecret[0], pSecret[1], pSecret[2], pSecret[3], tmp));
        p->getVar("max")->get(tmp);
        CMI(bnz_sub(tmp, tmp, pSec[0]));
        CMI(foursquares(pSecret[4], pSecret[5], pSecret[6], pSecret[7], tmp));
        CMI(bnz_clear(tmp));

        CMI(bnz_set(pSecret[8], pSec[1]));

        m = p->getElement("Gsecret");
        m->set(pSec, 2);
        CMI(bnz_clear(pSec[0]));
        CMI(bnz_clear(pSec[1]));
        CMV_DELETE_ARRAY(pSec, bnz_t, 2);
        p->getVar("x")->map(p->getHom("phi_commit"), m);
        delete m;
        
        Element *winp = p->getElement("Ginp");
        winp->set(pSecret, 9);
        for(int i = 0; i < 9; ++i) CMI(bnz_clear(pSecret[i]));
        CMV_DELETE_ARRAY(pSecret, bnz_t, 9);

        printf("winp = \n");
        winp->print();

        p->getVar("wlo")->map(p->getHom("phi_lo"), winp);
        p->getVar("whi")->map(p->getHom("phi_hi"), winp);
        delete winp;
        
        printf("\nwlo = \n");
        p->getVar("wlo")->print();
        printf("\nwhi = \n");
        p->getVar("whi")->print();

        Element *trans = p->getElement("Htrans");
        trans->map(p->getHom("phi_htrans"), p->getVar("dummy"));
        
        printf("\ntrans = \n");
        trans->print();
        
        p->getVar("xlo")->map(p->getHom("phi_trans_lo"), trans);
        p->getVar("xhi")->map(p->getHom("phi_trans_hi"), trans);
        
        Message msg[2];
        msg[0] = trans->get();
        msg[1] = p->getVar("x")->get();
        delete trans;
        Message ret = Convert::messagesToMessage(msg, 2);
        delete[] msg[0].data;
        delete[] msg[1].data;
        return ret;
}

void init_verifier(Parser *p, Message msg)
{
    Message m[2];
    Convert::messageToMessages(msg, m, 2, 0);

    Element *trans = p->getElement("Htrans");
    trans->set(m[0]);
    p->getVar("x")->set(m[1]);

    p->getVar("xlo")->map(p->getHom("phi_trans_lo"), trans);
    p->getVar("xhi")->map(p->getHom("phi_trans_hi"), trans);

    delete trans;
    delete[] msg.data;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("I need the .zk file as parameter!\n");
        return 3;
    }
    try {
        Random::init();
        
        /* initialize prover */
        Parser *prover  = Parser::fromFile(argv[1]);
        Message trans = init_prover(prover, "1959");
        
        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);
        init_verifier(verifier, trans);

        printf("sub test 1/2\n");
        printf("testing interactive interval proof\n");
        if(inter(prover->getSigma("S"), verifier->getSigma("S"))) printf("OK\n"); else { printf("fail\n"); return 1; }
        printf("\n");

        printf("sub test 2/2\n");
        printf("testing non-interactive interval proof\n");
        if(noninter(prover->getSigma("S"), verifier->getSigma("S"))) printf("OK\n"); else { printf("fail\n"); return 2; }
        printf("\n");

        delete prover;
        delete verifier;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 3;
    }
    return 0;
}

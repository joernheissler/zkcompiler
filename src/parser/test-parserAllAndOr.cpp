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

struct witness { const char *w, *x, *h; };

void rnd(Parser *p, struct witness *w, unsigned long k)
{
    for(unsigned i = 0; i < 3; ++i) {
        if(i == 2 || k == 2 || i == k) {
            /* choose random witnesses */
            p->getVar(w[i].w)->random();
            
            /* calculate public value */
            p->map(w[i].x, w[i].h, w[i].w);
        } else {
            /* choose random public value */
            p->getVar(w[i].x)->random();
        }
    }
}

int subtest(unsigned a, unsigned n, const char *dscr, const char *s, Parser *p, Parser *v)
{
    printf("sub test %u/%u\n", a, n);
    printf("testing interactive %s proof\n", dscr);
    if(inter(p->getSigma(s), v->getSigma(s))) printf("OK\n"); else { printf("fail\n"); return a; }
    printf("\n");
    
    printf("sub test %u/%u\n", (a + 1), n);
    printf("testing non-interactive %s proof\n", dscr);
    if(noninter(p->getSigma(s), v->getSigma(s))) printf("OK\n"); else { printf("fail\n"); return a + 1; }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[])
{
    int ret;

    if(argc != 2) {
        printf("I need the .zk file as parameter!\n");
        return 13;
    }
    try {
        Random::init();
        Message msg;
        
        /* initialize prover */
        Parser *prover  = Parser::fromFile(argv[1]);
        
        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);

        struct witness wx[] = { {"w0a","x0a","phi0a"}, {"w0b","x0b","phi0b"}, {"w0c","x0c","phi0c"},
                                {"w1a","x1a","phi1a"}, {"w1b","x1b","phi1b"}, {"w1c","x1c","phi1c"},
                                {"w2a","x2a","phi1a"}, {"w2b","x2b","phi1b"}, {"w2c","x2c","phi1c"},
                                {0, 0, 0} };
        bnz_t r;
        bnz_init(r);
        
        /* generate random witnesses and calculate public values.
         * Or, generate a random public value without witness */
        bnz_set_ui(r, 3);
        Random::range0(r, r);
        rnd(prover, wx + 0, bnz_get_ui(r));
        
        bnz_set_ui(r, 3);
        Random::range0(r, r);
        rnd(prover, wx + 3, bnz_get_ui(r));
        
        bnz_set_ui(r, 3);
        Random::range0(r, r);
        rnd(prover, wx + 6, bnz_get_ui(r));

        bnz_clear(r);
        
        for(int i = 0; i < 9; ++i) {
            /* transmit public value to verifier */
            msg = prover->getVar(wx[i].x)->get();
            printHex(msg, wx[i].x);
            verifier->getVar(wx[i].x)->set(msg);
            delete[] msg.data;
        }

        ret = subtest( 1, 8, "OrAnd (Phi, Phi, Phi)", "s0x", prover, verifier); if(ret) return ret;
        ret = subtest( 3, 8, "AndOr (Phi, Phi, Phi)", "s0y", prover, verifier); if(ret) return ret;
        ret = subtest( 5, 8, "OrAnd (Gsp, Gsp, Gsp)", "s1x", prover, verifier); if(ret) return ret;
        ret = subtest( 7, 8, "AndOr (Gsp, Gsp, Gsp)", "s1y", prover, verifier); if(ret) return ret;
        // SigmaExp Protocol is not working yet!!!		
        // ret = subtest( 9, 12, "OrAnd (Exp, Exp, Exp)", "s2x", prover, verifier); if(ret) return ret;
        // ret = subtest(11, 12, "AndOr (Exp, Exp, Exp)", "s2y", prover, verifier); if(ret) return ret;

        delete verifier;
        delete prover;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 13;
    }
    return 0;
}

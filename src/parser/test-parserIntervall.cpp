#include <iomanip>
#include <stdio.h>
#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"
#include "random/random.hpp"
#include "util/foursquares.hpp"

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
        Parser *p = Parser::fromFile(argv[1]);
        
        Element *w = p->getVar("w");
        Element *x = p->getVar("x");
        Element *wi = p->getElement("Gx9");
        CMV::bnz_t* pSecret;
        CMV_NEW_ARRAY(pSecret, bnz_t, 9);
        CMV(bnz_t tmp);
        CMI(bnz_init_set_str(pSecret[0], CMV_IN((zk_pcchar_t)"31337"), CMV_IN(0)));
        for(int i = 1; i < 9; ++i) CMI(bnz_init(pSecret[i]));
        CMI(bnz_init(tmp));

        p->getVar("a")->get(tmp);
        CMI(bnz_sub(tmp, pSecret[0], tmp));
        CMI(foursquares(pSecret[1], pSecret[2], pSecret[3], pSecret[4], tmp));
        
        p->getVar("b")->get(tmp);
        CMI(bnz_sub(tmp, tmp, pSecret[0]));
        CMI(foursquares(pSecret[5], pSecret[6], pSecret[7], pSecret[8], tmp));

        CMI(bnz_clear(tmp));

        wi->set(pSecret, 9);
        for(int i = 0; i < 9; ++i) CMI(bnz_clear(pSecret[i]));
        CMV_DELETE_ARRAY(pSecret, bnz_t, 9);
        wi->print(); printf("\n");

        p->map("gi","phi_H_inverse","g");

        p->getVar("gi")->print();

        w->map(p->getHom("phi_W"), wi);
        w->print();

        delete wi;
        x->map(p->getHom("phi_W_X"), w);
        x->print();
        Sigma *s = p->getSigma("sigma");

        s->P1();
        printf("Commitment:\n"); Message msg = s->getCommitment(); printHex(msg); delete[] msg.data;
        
        s->genChallenge();
        printf("Challenge: \n"); msg = s->getChallenge(); printHex(msg); delete[] msg.data;

        s->P2();
        printf("Response:\n"); msg = s->getResponse(); printHex(msg); delete[] msg.data;

        if(CMV_OUT(s->V())) {
            printf("true\n");
            ret = 0;
        } else {
            printf("false\n");
            ret = 2;
        }

        delete s;
        delete p;

        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 1;
    }
    return ret;
}

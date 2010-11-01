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
        Parser *p = Parser::fromFile(argv[1]);
        
        Element *W = p->getVar("W");
        Element *X = p->getVar("X");
        Element *wi = p->getElement("Gx2");
        CMV::zk_pcchar_t* pI;
        CMV_NEW_ARRAY(pI, zk_pcchar_t, 2);
        pI[0] = CMV_IN((zk_pcchar_t)"101");
        pI[1] = CMV_IN((zk_pcchar_t)"202");
        wi->set(pI, 2);
        CMV_DELETE_ARRAY(pI, zk_pcchar_t, 2);
        W->map(p->getHom("phi_W"), wi);
        delete wi;
        X->map(p->getHom("phi_W_X"), W);
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

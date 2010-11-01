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


int main(int argc, char *argv[])
{
    int ret = 0;

    if(argc != 2) {
        printf("I need the .zk file as parameter!\n");
        return 1;
    }
    try {
        Random::init();
        Parser *p = Parser::fromFile(argv[1]);
        Element *w = p->getVar("w");
        Sigma *s = p->getSigma("sigma");

        CMV::zk_pcchar_t* pI;
        CMV_NEW_ARRAY(pI, zk_pcchar_t, 2);
        pI[0] = CMV_IN((zk_pcchar_t)"37");
        pI[1] = CMV_IN((zk_pcchar_t)"214");
        w->set(pI, 2);
        CMV_DELETE_ARRAY(pI, zk_pcchar_t, 2);

        p->getVar("g")->set(CMV_IN((zk_pcchar_t)"276"));
        p->getVar("h")->set(CMV_IN((zk_pcchar_t)"579"));

        p->getVar("x")->map(p->getHom("phi"), w);
        Hash *h = new SHA1();
        Message sig = s->sign(h);
        printHex(sig);

        delete h;
        delete s;
        delete p;


        p = Parser::fromFile(argv[1]);
        s = p->getSigma("sigma");
        p->getVar("g")->set(CMV_IN((zk_pcchar_t)"276"));
        p->getVar("h")->set(CMV_IN((zk_pcchar_t)"579"));
        p->getVar("x")->set(CMV_IN((zk_pcchar_t)"296"));
        h = new SHA1();
        if(s->verify(h, sig)) {
            ret = 0;
        } else {
            ret = 2;
        }
        delete h;
        delete s;
        delete p;
        delete[] sig.data;

        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 1;
    }
    return ret;
}

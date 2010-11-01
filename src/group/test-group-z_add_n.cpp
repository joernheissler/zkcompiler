#include <stdio.h>

#include "group/group.hpp"
#include "random/random.hpp"

CM_INIT_CODE_MANAGER;

using namespace std;
using namespace ZKCompiler;


#define FAIL (printf("FAIL\n"), fail = true)
#define OK (printf("OK\n"), true)

int main()
{
    //CodeManagement::CodeCollector codeCollector;
    //CodeManagement::DefaultCodeManager::getManager().addCodeCollector(codeCollector);

    const char *params[] = { "31337" };
    const char *invalid0[] = { "Hello" };
    const char *invalid1[] = { "0" };
    bool fail = false;
    Group *g;

    Random::init();
    
    printf("Testing if Group::create throws up for invalid n: ");
    try {
        g = Group::create((Parser *)0, "Z_add_n", 0, params);
        delete g;
        FAIL;
    } catch(...) { OK; }
    
    printf("Testing if Group::create throws up for non-numbers: ");
    try {
        g = Group::create((Parser *)0, "Z_add_n", 1, invalid0);
        delete g;
        FAIL;
    } catch(...) { OK; }
    
    printf("Testing if Group::create throws up for n <= 0: ");
    try {
        g = Group::create((Parser *)0, "Z_add_n", 1, invalid1);
        delete g;
        FAIL;
    } catch(...) { OK; }
    
    g = Group::create((Parser *)0, "Z_add_n", 1, params);

    CMV(bnz_t a);
    CMV(bnz_t b);
    CMV(bnz_t c);
    CMI(bnz_init_set_ui(a, CMV_IN(42ul)));
    CMI(bnz_init(b));
    CMI(bnz_init(c));

    printf("identity: ");
    g->identity(&a);
    bnz_cmp_ui(CMV_OUT(a), 0) == 0 ? OK : FAIL;

    CMI(bnz_set_ui(a, CMV_IN(123ul)));
    printf("min: ");
    g->min(&a);
    bnz_cmp_si(CMV_OUT(a), 0) == 0 ? OK : FAIL;
    
    CMI(bnz_set_ui(b, CMV_IN(123ul)));
    printf("max: ");
    g->max(&b);
    bnz_cmp_si(CMV_OUT(b), 0) == 0 ? OK : FAIL;
    
    CMI(bnz_set_ui(a, CMV_IN(12345ul)));
    CMI(bnz_set_ui(b, CMV_IN(25252ul)));

    printf("inverse: ");
    g->inverse(&c, &a);
    bnz_cmp_si(CMV_OUT(c), 18992) == 0 ? OK : FAIL;
    
    printf("op: ");
    g->op(&c, &a, &b);
    bnz_cmp_si(CMV_OUT(c), 6260) == 0 ? OK : FAIL;
    
    printf("iop: ");
    g->iop(&c, &a, &b);
    bnz_cmp_si(CMV_OUT(c), 18430) == 0 ? OK : FAIL;

    printf("pow0: ");
    g->pow(&c, &a, b);
    bnz_cmp_si(CMV_OUT(c), 26801) == 0 ? OK : FAIL;
    
    printf("ipow: ");
    g->ipow(&c, &a, b);
    bnz_cmp_si(CMV_OUT(c), 4536) == 0 ? OK : FAIL;

    printf("pow1: ");
    g->pow(&c, &a, CMV_IN(-1234l));
    bnz_cmp_si(CMV_OUT(c), 27389) == 0 ? OK : FAIL;

    int i;

    printf("random0: ");
    for(i = 0; i < 1000; ++i) {
        g->random(&c);
        if(bnz_cmp_si(CMV_OUT(c), 0) < 0 || bnz_cmp_si(CMV_OUT(c), 31337) >= 0) { FAIL; break; }
    }
    if(i == 1000) OK;
    
    printf("random1: ");
    for(i = 0; i < 1000; ++i) {
        g->random(&c, b);
        if(bnz_cmp_si(CMV_OUT(c), 0) < 0 || bnz_cmp_si(CMV_OUT(c), 31337) >= 0) { FAIL; break; }
    }
    if(i == 1000) OK;

    printf("cmp0: ");
    CMV_OUT(g->cmp(&a, &b)) == R_UN ? OK : FAIL;
    
    printf("cmp1: ");
    CMV_OUT(g->cmp(&b, &b)) == R_ID ? OK : FAIL;

    CMI(bnz_clear(a));
    CMI(bnz_clear(b));
    CMI(bnz_clear(c));
    delete g;
    Random::free();
    return fail ? 1 : 0;
}

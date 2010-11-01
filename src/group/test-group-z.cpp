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

    const char *params[] = { "-377", "2735" };
    const char *invalid0[] = { "Hello", "World" };
    const char *invalid1[] = { "2000", "1000" };
    bool fail = false;
    Group *g;

    Random::init();
    
    printf("Testing if Group::create throws up for invalid n: ");
    try {
        g = Group::create((Parser *)0, "Z", 1, params);
        delete g;
        FAIL;
    } catch(...) { OK; }
    
    printf("Testing if Group::create throws up for non-numbers: ");
    try {
        g = Group::create((Parser *)0, "Z", 2, invalid0);
        delete g;
        FAIL;
    } catch(...) { OK; }
    
    printf("Testing if Group::create throws up for minimum > maximum: ");
    try {
        g = Group::create((Parser *)0, "Z", 2, invalid1);
        delete g;
        FAIL;
    } catch(...) { OK; }
    
    g = Group::create((Parser *)0, "Z", 2, params);

    CMV(bnz_t a);
    CMV(bnz_t b);
    CMV(bnz_t c);
    CMI(bnz_init_set_ui(a, CMV_IN(42ul)));
    CMI(bnz_init(b));
    CMI(bnz_init(c));

    printf("identity: ");
    g->identity(&a);
    bnz_cmp_ui(CMV_OUT(a), 0) == 0 ? OK : FAIL;

    printf("min: ");
    g->min(&a);
    bnz_cmp_si(CMV_OUT(a), -377) == 0 ? OK : FAIL;
    
    printf("max: ");
    g->max(&b);
    bnz_cmp_si(CMV_OUT(b), 2735) == 0 ? OK : FAIL;
    
    printf("inverse: ");
    g->inverse(&c, &a);
    bnz_cmp_si(CMV_OUT(c), 377) == 0 ? OK : FAIL;
    
    printf("op: ");
    g->op(&c, &a, &b);
    bnz_cmp_si(CMV_OUT(c), 2358) == 0 ? OK : FAIL;
    
    printf("iop: ");
    g->iop(&c, &a, &b);
    bnz_cmp_si(CMV_OUT(c), -3112) == 0 ? OK : FAIL;

    printf("pow0: ");
    g->pow(&c, &a, b);
    bnz_cmp_si(CMV_OUT(c), -1031095l) == 0 ? OK : FAIL;
    
    printf("ipow: ");
    g->ipow(&c, &a, b);
    bnz_cmp_si(CMV_OUT(c), 1031095l) == 0 ? OK : FAIL;

    printf("pow1: ");
    g->pow(&c, &a, CMV_IN(-1234l));
    bnz_cmp_si(CMV_OUT(c), 465218l) == 0 ? OK : FAIL;

    int i;

    printf("random0: ");
    for(i = 0; i < 1000; ++i) {
        g->random(&c);
        if(bnz_cmp_si(CMV_OUT(c), -377) < 0 || bnz_cmp_si(CMV_OUT(c), 2735) > 0) { FAIL; break; }
    }
    if(i == 1000) OK;
    
    printf("random1: ");
    for(i = 0; i < 1000; ++i) {
        g->random(&c, b);
        if(bnz_cmp_si(CMV_OUT(c), -1031095l) < 0 || bnz_cmp_si(CMV_OUT(c), 7480225l) > 0) { FAIL; break; }
    }
    if(i == 1000) OK;

    printf("cmp0: ");
    CMV_OUT(g->cmp(&a, &b)) == R_LT ? OK : FAIL;
    
    printf("cmp1: ");
    CMV_OUT(g->cmp(&b, &a)) == R_GT ? OK : FAIL;
    
    printf("cmp2: ");
    CMV_OUT(g->cmp(&b, &b)) == R_EQ ? OK : FAIL;

    CMI(bnz_clear(a));
    CMI(bnz_clear(b));
    CMI(bnz_clear(c));
    delete g;
    Random::free();
    return fail ? 1 : 0;
}

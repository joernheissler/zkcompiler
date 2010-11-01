/*   EXP test case
 *
 *   
 *
 *
 */

#include <cstdio>
#include "bignum/bignum.hpp"
#include "element/element.hpp"
#include "group/group.hpp"
#include "group/add_mod_n.hpp"
#include "group/add_z.hpp"
#include "group/mul_mod_n.hpp"
#include "group/cartprod.hpp"
#include "hom/hom.hpp"
#include "theta/theta.hpp"
#include "SigmaConfig/SigmaConfig.hpp"
#include "sigma/SigmaExp.hpp"
#include "random/random.hpp"
#include "util/zkprint.hpp"
#include <cstring>
#include <iomanip>

using namespace ZKCompiler::group;
using namespace ZKCompiler::hom;
using namespace std;


Varref *buildVarref(Varref_type type, unsigned size, bnz_t *v, unsigned off, unsigned n, Varref **lst)
{
    Varref *r = new Varref;
    r->type = type;
    r->size = size;
    r->v = v;
    r->off = off;
    r->n = n;
    r->lst = lst;
    return r;
}

void setExpr(Expr *e, Group *g, Varref *dst, Expr_type type, Varref *a, Varref *b, bnz_t c, Hom *h)
{
    e->g = g;
    e->dst = dst;
    e->type = type;
    e->a = a;
    e->b = b;
    if(c) bnz_init_set(e->c, c); else bnz_init(e->c);
    e->h = h;
}

Hom *buildHom()
{
	bnz_t min, max;
	bnz_init(min); bnz_init(max);
	bnz_set_ui(min, 0);
	bnz_set_ui(max, 100);
	Group *g0 = new Add_z(min, max);
    Group *srcgrps[] = { g0, g0 };
    Group *src = new CartProd(2, srcgrps);
    Group *dst = new Mul_mod_n(13, z_mul_n_randmode_qr);

    Element *g = dst->element();
    g->set("11");

    Element *h = dst->element();
    h->set("7");

    Element **tmp = new Element*[2];
    tmp[0] = dst->element();
    tmp[1] = dst->element();

    Expr *e = new Expr[3];
    setExpr(e + 0, dst, buildVarref(Varref_var, 1, tmp[0]->getZ(), 0, 0, 0), Expr_pow,
                   buildVarref(Varref_var, 1, g->getZ(), 0, 0, 0), buildVarref(Varref_src, 1, 0, 0, 0, 0), 0, 0);
    setExpr(e + 1, dst, buildVarref(Varref_var, 1, tmp[1]->getZ(), 0, 0, 0), Expr_pow,
                   buildVarref(Varref_var, 1, h->getZ(), 0, 0, 0), buildVarref(Varref_src, 1, 0, 1, 0, 0), 0, 0);
    setExpr(e + 2, dst, buildVarref(Varref_dst, 1, 0, 0, 0, 0), Expr_op,
                   buildVarref(Varref_var, 1, tmp[0]->getZ(), 0, 0, 0),
                   buildVarref(Varref_var, 1, tmp[1]->getZ(), 0, 0, 0), 0, 0);

    return new Hom(dst, src, 2u, tmp, 3u, e);
}

void set_tuple(Element *t, long v[])
{
    bnz_t *x = t->getZ();
    unsigned u = t->getSize();
    for(unsigned i = 0; i < u; ++i) bnz_set_si(x[i], v[i]);
	t->set();
}


int main(void)
{	

    // Init all variables 
	long w_i[] = { 11, 7, -53104, 3710, 1010, 83611 };
	long intervalL[] = {0, 0, -3000000, -3000000, -3000000, -3000000};
	long intervalR[] = {100, 100, 3000000, 3000000, 3000000, 3000000};
	int u = 2;


    Hom *phi;

	ZKCompiler::Random::init();

    // Build used homomorphism object
    phi = buildHom();

	Element *w = phi->getSrcGroup()->element();
    set_tuple(w, w_i);

	bnz_t cplusz;
	bnz_init(cplusz);
	bnz_ui_pow_ui(cplusz, 2, 6);

	Element *L = phi->getSrcGroup()->element();
	Element *R = phi->getSrcGroup()->element();
	set_tuple(L, intervalL);
	set_tuple(R, intervalR);	

	for (int i=0; i < u; i++)
	{
		zkprintf("L[%d] = %Zd < ", i, L->getZ()[i]);
		zkprintf("w[%d] = %Zd < ", i, w->getZ()[i]);
		zkprintf("R[%d] = %Zd\n", i, R->getZ()[i]);
	}

    Element *x;
	x = phi->getDstGroup()->element();
    x->map(phi, w); // x = phi(w)
	zkprintf("x = %Zd\n\n", x->getZ()[0]);
    	
	

	Theta *th = new Theta(u);
	SigmaConfig *proverCfg = new SigmaConfig();

	proverCfg->phi = phi;
	proverCfg->theta = th;
	proverCfg->x = x;
	proverCfg->w = w;
	proverCfg->u = u;
	proverCfg->l = 100;
	proverCfg->L = L;
	proverCfg->R = R;
	bnz_set(proverCfg->cplus, cplusz);


    // Run the interactive test
	printf("\n\n\n\n=== Sigma Exp protocol ===\n");	
	SigmaExp *sigma3 = new SigmaExp(proverCfg);	

	sigma3->P1();
	((Sigma*)sigma3)->genChallenge();
	sigma3->P2();	

	bool result1 = sigma3->V(true);
	printf("V = %s\n", (result1 ? "true" : "false"));	

	delete th;
	ZKCompiler::Random::free();

	return !(result1);



}


#include <iomanip>
#include "bignum/bignum.hpp"
#include "element/element.hpp"
#include "group/group.hpp"
#include "group/add_mod_n.hpp"
#include "group/add_z.hpp"
#include "group/mul_mod_n.hpp"
#include "group/cartprod.hpp"
#include "hom/hom.hpp"
#include "SigmaConfig/SigmaConfig.hpp"
#include "sigma/SigmaPhi.hpp"
#include "sigma/SigmaGsp.hpp"
#include "sigma/SigmaAND.hpp"
#include "random/random.hpp"
#include "util/zkprint.hpp"

#include "hash/sha1.hpp"


using namespace ZKCompiler::group;
using namespace ZKCompiler::hom;
using namespace std;

namespace {

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
    bnz_init_set_str(min, "-3000000", 0);
    bnz_init_set_str(max, "3000000", 0);
    Group *g0 = new Add_z(min, max);
    bnz_clear(min);
    bnz_clear(max);
    Group *srcgrps[] = { g0, g0 };
    Group *src = new CartProd(2, srcgrps);
    Group *dst = new Mul_mod_n(1019, z_mul_n_randmode_qr);

    Element *g = dst->element();
    g->set("749");

    Element *h = dst->element();
    h->set("821");

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
                t->set();
		bnz_t *x = t->getZ();
		unsigned u = t->getSize();
		for(unsigned i = 0; i < u; ++i) bnz_set_si(x[i], v[i]);
	}
}


int main(void)
{    

    int return_value = 0;

    long w_i[] = { 12, 232767, -53104, 3710, 1010, 83611 };
	long intervalL[] = {-3000000, -3000000, -3000000, -3000000, -3000000, -3000000};
	long intervalR[] = {3000000, 3000000, 3000000, 3000000, 3000000, 3000000};
	int u = 2;

	Random::init();

    Hom *phi = buildHom();

    Element *w = phi->getSrcGroup()->element();
    set_tuple(w, w_i);

	bnz_t cplus;
	bnz_init(cplus);
	bnz_ui_pow_ui(cplus, 2, 32);

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
    zkprintf("x = %d\n\n", x->getZ()[0]);
        

    SigmaConfig *proverCfg = new SigmaConfig();
	proverCfg->phi = phi;
	proverCfg->x = x;
	proverCfg->w = w;
	proverCfg->u = u;
	proverCfg->l = 100;
	proverCfg->L = L;
	proverCfg->R = R;
        bnz_init_set(proverCfg->cplus, cplus);
        bnz_clear(cplus);


    printf("\n\n\n\n=== Sigma AND-gsp protocol ===\n");

	
	const unsigned int n = 100;
	Sigma **sigmas = new Sigma*[n];
	for (unsigned int i = 0; i < n; i++)
	{
		sigmas[i] = (Sigma *)new SigmaGsp(proverCfg);
	}

	SigmaAND *sigmaand = new SigmaAND(sigmas, n);
    
    
	
	sigmaand->P1();
	printf("Commitment:\n");
    printHex(sigmaand->getCommitment());

	sigmaand->genChallenge();
//	sigmaand->setChallenge(sigmaand->getChallenge());
    printf("Challenge:\n");
    printHex(sigmaand->getChallenge());

	sigmaand->P2();
    printf("Response:\n");
    printHex(sigmaand->getResponse());

	bool result = sigmaand->V(true);
	printf("V = %s\n", (result ? "true" : "false"));

   if (!result)
    {
        return_value = 1;
    }
    else
    {	

        printf("\n\n\n\n=== Sigma AND-GSP protocol (non-interactive) ===\n");

	    SHA1 *hashfunction = new SHA1();

	    Message sig = sigmaand->sign(hashfunction);
	    printf("Signatur:\n");
	    printHex(sig);

    	
	    bool result3 = sigmaand->verify(hashfunction, sig);
        printf("V = %s\n", (result3 ? "true" : "false"));
      
        if (!result3)
        {
            // Non-Interactive test failed    
            return_value = 2;
        }

    }

    

    delete phi;

	delete sigmaand;
    ZKCompiler::Random::free();



    return return_value;
}

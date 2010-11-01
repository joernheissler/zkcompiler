#include <iomanip>
#include <cstdio>
#include "bignum/bignum.hpp"
#include "element/element.hpp"
#include "group/group.hpp"
#include "group/add_mod_n.hpp"
#include "group/add_z.hpp"
#include "group/mul_mod_n.hpp"
#include "group/cartprod.hpp"
#include "hom/hom.hpp"
#include "SigmaConfig/SigmaConfig.hpp"
#include "sigma/SigmaGsp.hpp"
#include "random/random.hpp"
#include "util/zkprint.hpp"

#include "hash/sha1.hpp"


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


int main(void)
{	

    // Init variables 
    int return_value = 0;


	long w_i[] = { 12, 232767, -53104, 3710, 1010, 83611 };
	long intervalL[] = {-3000000, -3000000, -3000000, -3000000, -3000000, -3000000};
	long intervalR[] = {3000000, 3000000, 3000000, 3000000, 3000000, 3000000};
	int u = 2;

    Hom *phi;
	ZKCompiler::Random::init();

    // build homomorphism object
    phi = buildHom();


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
    	
	Element *commitment, *response;
        bnz_t challenge;
        bnz_init(challenge);
	commitment = phi->getDstGroup()->element();
	response = phi->getSrcGroup()->element();

    // Set configuration object
	SigmaConfig *proverCfg = new SigmaConfig();
	SigmaConfig *verifierCfg = new SigmaConfig();

	proverCfg->phi = verifierCfg->phi = phi;
	proverCfg->x = verifierCfg->x = x;
	proverCfg->w = verifierCfg->w = w;
	proverCfg->u = u;
	proverCfg->l = verifierCfg->l = 100;
	proverCfg->L = verifierCfg->L = L;
	proverCfg->R = verifierCfg->R = R;
        bnz_init_set(proverCfg->cplus, cplus);
        bnz_init_set(verifierCfg->cplus, cplus);
        bnz_clear(cplus);


	printf("\n\n\n\n=== Sigma GSP protocol ===\n");
	SigmaGsp *prover2 = new SigmaGsp(proverCfg);
	SigmaGsp *verifier2 = new SigmaGsp(verifierCfg);


    // Run interactive test
    // Repeat 5 times 
	int gsp_failed = 0;
	for (int j = 0; j < 5; j++)
	{		
		prover2->P1();

		prover2->getCommitment(commitment);
		zkprintf("--> r = %Zd\n", commitment->getZ()[0]);
		verifier2->setCommitment(commitment);

		verifier2->genChallenge();

		verifier2->getChallenge(challenge);
		zkprintf("<-- c = %Zd\n", challenge);
		prover2->setChallenge(challenge);

		prover2->P2();

		prover2->getResponse(response);
		for (int i = 0; i < u; i++) zkprintf("--> s = %Zd\n", response->getZ()[i]);
		verifier2->setResponse(response);

		if (verifier2->V(true))
		{
			printf("V = true\n");	
		}
		else
		{
			printf("V = false\n");
			gsp_failed++;
		}
	}
	printf("failed: %i\n", gsp_failed);

    if (gsp_failed > 0)
    {
        return_value = 1;
    }
    else
    {	

        // Run non-interactive test
        printf("\n\n\n\n=== Sigma GSP protocol (non-interactive) ===\n");

        SigmaGsp *sigma1 = new SigmaGsp(proverCfg);
        

	    SHA1 *hashfunction = new SHA1();

	    Message sig = sigma1->sign(hashfunction);
	    printf("Signatur:\n");
	    printHex(sig);

    	
	    bool result3 = sigma1->verify(hashfunction, sig);
        printf("V = %s\n", (result3 ? "true" : "false"));    
      
        if (!result3)
        {
            // Non-Interactive test failed    
            return_value = 2;
        }

    }



    delete commitment;
        bnz_clear(challenge);
    delete response;



    /* RETURN VALUES:
     *
     * 0  both tests succeeded
     * 1  interactive test failed
     * 2  interactice test succeeded, non-interactive test failed
     *
     */
	return return_value;



}

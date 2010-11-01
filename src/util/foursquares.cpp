#include "bignum/bignum.hpp"
#include "util/errorhandling.hpp"
#include "util/foursquares.hpp"
#include "random/random.hpp"

using namespace ZKCompiler;

namespace {
    /* probabilistic algorithm to find square root of -1 modulo p
     *
     * p % 4 = 1, p >= 5
     *
     * if p is prime:
     * u^((p-1)/2) is 1 iff u is a quadratic residue modulo n, else -1. (Legendre symbol)
     * if u is QR (mod n), then u^((p-1)/4) is 1 or -1.
     * If u is QNR (mod n), u^((p-1)/4) is a square root of -1 modulo n and neither 1 nor -1.
     * so we need a quadratic nonresidue modulo n.
     * exactly half of Z^*_p are quadratic residues and x is a QR iff -x is a QR.
     * therefore we will find a QNR (i.e. the solution) in the lower half of Z^*_p, i.e. [1, (p-1)/2]
     * with probability 0.5 for each random number drawn.
     *
     * if p is not prime:
     * if gcd(u,p) != 1: u^i != 1,-1 (mod p).
     * if u^(p-1) != 1 (mod p) for one u, it's != 1 for at least 50% of all possible u, u^((p-1)/4) can't be 1,-1 in that case.
     * if u^(p-1) = 1 (mod p) for all u, u is a carmichael number. u^((p-1)/4) is +- 1 with probability 0.25
     *
     * the algorithm terminates for both p prime and p nonprime but will give incorrect results if p is not prime
     */

    void sqrtsub1(bnz_t& u, const bnz_t& p)
    {
        bnz_t one, psub1, pdiv2, pdiv4;

        bnz_init_set_ui(one, 1);
        bnz_init(psub1); bnz_sub_ui(psub1, p, 1);      /* psub1 = (p-1)   */
        bnz_init(pdiv2); bnz_tdiv_q_2exp(pdiv2, p, 1); /* pdiv2 = (p-1)/2 */
        bnz_init(pdiv4); bnz_tdiv_q_2exp(pdiv4, p, 2); /* pdiv4 = (p-1)/4 */

        do {
            Random::range0(u, pdiv2);
            bnz_add_ui(u, u, 1); /* u in [1,pdiv2] */
            bnz_powm(u, u, pdiv4, p);
        } while(bnz_cmp(u, one) == 0 || bnz_cmp(u, psub1) == 0);

        bnz_clear(one);
        bnz_clear(psub1);
        bnz_clear(pdiv2);
        bnz_clear(pdiv4);
    }

    /* apply the gcd algorithm to u, p; u < p; return first two remainders which are less than sqrt(p) as r1,r2 */
    void gcd(bnz_t& r1, bnz_t& r2, const bnz_t& u, const bnz_t& p)
    {
        bnz_t a,b,s;
        bnz_init_set(a, u);
        bnz_init_set(b, p);
        bnz_init(s);
        bnz_sqrt(s, p);
        int n = 0;

        while(bnz_sgn(b) != 0) {
            bnz_mod(a, a,  b);
            bnz_swap(a, b);
            if(bnz_cmp(b, s) <= 0) {
                if(n == 0) bnz_set(r1, b), ++n;
                else {     bnz_set(r2, b), ++n; break; }
            }
        }

        if(n == 0) bnz_set_ui(r1, 0), ++n;
        if(n == 1) bnz_set_ui(r2, 0);

        bnz_clear(a);
        bnz_clear(b);
        bnz_clear(s);
    }

    /* probabilistic algorithm:
     * if w % 4 = 2, return w1,w2,w3,w4 such that w1^2 + w2^2 + w3^2 + w4^2 = w */
    void foursquares2(bnz_t& w1, bnz_t& w2, bnz_t& w3, bnz_t& w4, const bnz_t& w)
    {
        bnz_t tmp1, tmp2, zero, sqrtw, p, u;

        bnz_init(tmp1);
        bnz_init(tmp2);
        bnz_init(zero);
        bnz_init(sqrtw);
        bnz_init(p);
        bnz_init(u);

        bnz_sqrt(sqrtw, w);
        bnz_sub_ui(sqrtw, sqrtw, 1);
        bnz_tdiv_q_2exp(sqrtw, sqrtw, 1);
        bnz_add_ui(sqrtw, sqrtw, 1);
        /* asserted: sqrtw in [1,(sqrt(w)-1)/2) */

        do {
            /* find odd number w1 with w1 <= sqrt(w) */
            Random::range0(w1, sqrtw);
            bnz_mul_2exp(w1, w1, 1);
            bnz_add_ui(w1, w1, 1);

            /* find even number w2 with w2 <= sqrt(w - w1^2) */
            bnz_pow_ui(w2, w1, 2);
            bnz_sub(w2, w, w2);
            bnz_sqrt(w2, w2);
            bnz_tdiv_q_2exp(w2, w2, 1);
            bnz_add_ui(w2, w2, 1); /* w2 = sqrt(w - w1^2)/2 + 1 */
            Random::range0(w2, w2); /* w2 in [0, sqrt(w - w1^2)/2] */
            bnz_mul_2exp(w2, w2, 1);

            /* p = w - w1^2 - w2^2 */
            bnz_pow_ui(tmp1, w1, 2);
            bnz_sub(p, w, tmp1);
            bnz_pow_ui(tmp1, w2, 2);
            bnz_sub(p, p, tmp1);

            /* w % 4 = 2
             * w1 % 4 = 1 or 3 -> w1^2 % 4 = 1
             * w2 % 4 = 0 or 2 -> w2^2 % 4 = 0
             * asserted: p = w - w1^2 - w2^2 % 4 = 1
             */

            /* p == 1 is a special case for which the remainder of the algorithm won't work; but the solution is obvious. */
            if(bnz_cmp_ui(p, 1) == 0) {
                bnz_set_ui(w3, 0);
                bnz_set_ui(w4, 1);
                break;
            }

            /* if p is not prime, find other numbers for w1, w2. But don't waste too much time on the primality test */
            if(bnz_probab_prime_p(p, 0) == 0) continue;

            /* find a square root of -1 mod p; can give wrong results if p is not prime */
            sqrtsub1(u, p);

            /* set w3,w4 to the first remainders of gcd algorithm (u, p) which are <= sqrt(p) */
            gcd(w3, w4, u, p);

            /* if w3^2 + w4^2 != p, p is not prime; we'll have to find another p */
            bnz_pow_ui(tmp1, w3, 2);
            bnz_pow_ui(tmp2, w4, 2);
            bnz_add(tmp1, tmp1, tmp2);
        } while(bnz_cmp(tmp1, p) != 0);

        bnz_clear(tmp1);
        bnz_clear(tmp2);
        bnz_clear(zero);
        bnz_clear(sqrtw);
        bnz_clear(p);
        bnz_clear(u);
    }
}

namespace ZKCompiler {
    /* get four numbers w1,w2,w3,w4 with w1^2 + w2^2 + w3^2 + w4^2 = w
     *
     * preprocess w, get w1,w2,w3,w4 with probabilistic algorithm foursquares2, postprocess w1,w2,w3,w4 */
    void foursquares(bnz_t& w1, bnz_t& w2, bnz_t& w3, bnz_t& w4, const bnz_t& w)
    {
        unsigned long t;
        bnz_t k;

        /* negative numbers cannot be represented as four squares */
        if(bnz_sgn(w) < 0) ZK_HANDLE_ERROR("negative number given");

        /* if w is 0, there is only one solution: (0,0,0,0) */
        if(bnz_sgn(w) == 0) {
            bnz_set_ui(w1, 0);
            bnz_set_ui(w2, 0);
            bnz_set_ui(w3, 0);
            bnz_set_ui(w4, 0);
            return;
        }

        /* asserted: w is positive */

        /* get t = number of 0 bits on the right
         * and k is w bit shifted such that k % 4 = 2
         */
        bnz_init(k);
        t = (unsigned long)bnz_scan1(w, 0);
        if(t > 1) {
            bnz_tdiv_q_2exp(k, w, t - 1); /* k = w / 2^(t-1) */
        } else if(t == 0) {
            bnz_mul_2exp(k, w, 1); /* k = 2*w */
        } else { /* t == 1, k = w */
            bnz_set(k, w);
        }
        /* asserted: k % 4 = 2 */

        /* get 4 numbers w1,w2,w3,w4 such that k = w1^2 + w2^2 + w3^2 + w4^2 */
        foursquares2(w1, w2, w3, w4, k);
        bnz_clear(k);

        /* asserted: exactly two out of w1,w2,w3,w4 are odd while the other two are even */

        if(t % 2 == 0) {
            /* make sure that w1 and w2 are both even or both odd; same for w3 and w4.
             * swap w2 with w3 or w4 to do this */
            int b2 = bnz_tstbit(w2, 0);
            if(b2 != bnz_tstbit(w1, 0)) bnz_swap(w2, b2 == bnz_tstbit(w3, 0) ? w4 : w3);

            /* (w1, w2) = (w1 + w2, |w1 - w2|) */
            /* (w3, w4) = (w3 + w4, |w3 - w4|) */
            bnz_add(w1, w1, w2); bnz_mul_2exp(w2, w2, 1); bnz_sub(w2, w1, w2); if(bnz_sgn(w2) < 0) bnz_neg(w2, w2);
            bnz_add(w3, w3, w4); bnz_mul_2exp(w4, w4, 1); bnz_sub(w4, w3, w4); if(bnz_sgn(w4) < 0) bnz_neg(w4, w4);

            /* asserted: w1,w2,w3,w4 are even
             * asserted: w1^2 + w2^2 + w3^2 + w4^2 = 2*k
             */
        }

        /* if t is 1, w = k
         * if t is 2, w1^2 + w2^2 + w3^2 + w4^2 = 2*k = 2 * w / 2^(2-1) = w.
         * the result is already correct.
         *
         * for t = 0 or t > 2, the result needs to be corrected
         */
        if(t == 0) {
            /* w1^2 + w2^2 + w3^2 + w4^2 = 2*k = 4*w and w1,w2,w3,w4 are even. divide each by 2 to get the correct result */
            bnz_tdiv_q_2exp(w1, w1, 1);
            bnz_tdiv_q_2exp(w2, w2, 1);
            bnz_tdiv_q_2exp(w3, w3, 1);
            bnz_tdiv_q_2exp(w4, w4, 1);
        } else if(t > 2) {
            if(t % 2 == 0) {
                /* if t is even, w1^2 + w2^2 + w3^2 + w4^2 = 2*k = 2*k = w / 2^(t-2).
                 * Hence multiply w1,w2,w3,w4 with 2^((t-2)/2) to get the correct result
                 */
                t = (t - 2) / 2;
            } else {
                /* if t is odd, w1^2 + w2^2 + w3^2 + w4^2 = k = w / 2^(t-1).
                 * Hence multiply w1,w2,w3,w4 with 2^((t-1)/2) to get the correct result
                 */
                t = (t - 1) / 2;
            }

            bnz_mul_2exp(w1, w1, t);
            bnz_mul_2exp(w2, w2, t);
            bnz_mul_2exp(w3, w3, t);
            bnz_mul_2exp(w4, w4, t);
        }
    }
}

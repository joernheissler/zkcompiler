#include <cstdlib>

#include "bignum/bignum.hpp"
#include "random/random.hpp"
#include "util/errorhandling.hpp"

extern "C" {
    #include "random/random_seed.h"
}

#define SEEDLEN 256

namespace ZKCompiler {
    int Random::initialized;
    bn_randstate_t Random::randstate;

    void Random::init(void)
    {
        if(initialized++) return;

        unsigned char s[SEEDLEN];
        bnz_t seed;

        if(getRandomSeed(s, SEEDLEN) != 0) ZK_HANDLE_ERROR("random seed failed");

        bnz_init(seed);
        bnz_import(seed, sizeof s, 1, 1, 1, 0, s);
        bn_randinit_default(randstate);
        bn_randseed(randstate, seed);
        bnz_clear(seed);
    }


    void Random::free(void)
    {
        if(!initialized) ZK_HANDLE_ERROR("not initialized");
        if(!--initialized) bn_randclear(randstate);
    }

    void Random::range(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        bnz_sub(d, max, min);
        urandomm(d, d);
        bnz_add(d, d, min);
    }

    void Random::range0(bnz_t& d, const bnz_t& max)
    {
        urandomm(d, max);
    }

    void Random::rangeinv(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        do
        {
            range(d, min, max);
        }
        while (!bnz_invert(d, d, max));
    }
    
    void Random::rangeinv0(bnz_t& d, const bnz_t& max)
    {
        do
        {
            range0(d, max);
        }
        while (!bnz_invert(d, d, max));
    }

    /* get random [0, max) */
    void Random::posrange(bnz_t& d, const bnz_t& max)
    {            
        urandomm(d, max);
    }

    /* get random [min, max] */
    void Random::irange(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        bnz_add_ui(d, max, 1);
        range(d, min, d);
    }

    /* get random [0, max] */
    void Random::irange0(bnz_t& d, const bnz_t& max)
    {
        bnz_add_ui(d, max, 1);
        range0(d, d);
    }

    /* get random [0..2^bits) */
    void Random::bits(bnz_t& d, unsigned b)
    {
        urandomb(d, b);
    }

    /* get random [2^(bits-1)..2^bits) */
    void Random::exactbits(bnz_t& d, unsigned b)
    {
        if(b == 0) {
            bnz_set_ui(d, 0);
            return;
        }

        bits(d, b - 1);
        bnz_setbit(d, b - 1);
    }

    int Random::is_prime(const bnz_t& p)
    {
        return probable_prime_p(p, 20, 0);
    }

    void Random::prange(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        do
        {
            range(d, min, max);
        }
        while (!is_prime(d));            
    }

    void Random::prange0(bnz_t& d, const bnz_t& max)
    {
        do
        {
            range0(d, max);
        }
        while (!is_prime(d));
    }

    /* get random prime [0, max) */
    void Random::pposrange(bnz_t& d, const bnz_t& max)
    {            
        do
        {
            posrange(d, max);
        }
        while (!is_prime(d));            
    }

    void Random::pirange(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        do
        {
            irange(d, min, max);
        }
        while (!is_prime(d));
    }

    void Random::pirange0(bnz_t& d, const bnz_t& max)
    {
        do
        {
            irange0(d, max);
        }
        while (!is_prime(d));
    }

    /* get random prime [0..2^bits) */
    void Random::pbits(bnz_t& d, unsigned b)
    {
        do
        {
            bits(d, b);
        }
        while (!is_prime(d));
    }

    /* get random prime [2^(bits-1)..2^bits) */
    void Random::pexactbits(bnz_t& d, unsigned b)
    {           
        do
        {
            exactbits(d, b);
        }
        while (!is_prime(d));
    }


    int Random::is_safeprime(const bnz_t& p)
    {
        // A safe prime is a prime number of the form 2p + 1, where p is also a prime.             
        const int repetitions = 20;

        if(probable_prime_p(p, repetitions, 0) == 0) return 0; // not even p is a prime

        int prob = 0;
        bnz_t safe;
        bnz_init(safe);

        // Check (p - 1) / 2
        // Since p is a prime, thus odd, p-1 is divisible by 2
        bnz_tdiv_q_2exp(safe, p, 1);
        prob = probable_prime_p(safe, repetitions, 0);

        bnz_clear(safe);
        return prob;
    }

  /* get random safe prime [min, max) */
    void Random::srange(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        do
        {
            range(d, min, max);
        }
        while (!is_safeprime(d));            
    }

    /* get random safe prime [0, max) */
      void Random::srange0(bnz_t& d, const bnz_t& max)
      {
          do
          {
              range0(d, max);
          }
          while (!is_safeprime(d));
      }

      /* get random safe prime [0, max) */
    void Random::sposrange(bnz_t& d, const bnz_t& max)
    {            
        do
        {
            posrange(d, max);
        }
        while (!is_safeprime(d));            
    }

    /* get random safe prime [min, max] */
    void Random::sirange(bnz_t& d, const bnz_t& min, const bnz_t& max)
    {
        do
        {
            irange(d, min, max);
        }
        while (!is_safeprime(d));
    }

    /* get random safe prime [0, max] */
    void Random::sirange0(bnz_t& d, const bnz_t& max)
    {
        do
        {
            irange0(d, max);
        }
        while (!is_safeprime(d));
    }

    /* get random safe prime [0..2^bits) */
    void Random::sbits(bnz_t& d, unsigned b)
    {
        do
        {
            bits(d, b);
        }
        while (!is_safeprime(d));
    }

    /* get random safe prime [2^(bits-1)..2^bits) */
    void Random::sexactbits(bnz_t& d, unsigned b)
    {           
        do
        {
            exactbits(d, b);
        }
        while (!is_safeprime(d));
    }

    void Random::urandomm(bnz_t& d, const bnz_t& max)
    {
        if(!initialized) ZK_HANDLE_ERROR("not initialized");
        if(!bnz_cmp_ui(max, 0)) {
            bnz_set_ui(d, 0);
            return;
        }
        if(bnz_cmp_ui(max, 0) < 0) ZK_HANDLE_ERROR("negative maximum given");

        bnz_urandomm(d, randstate, max);
    }

    void Random::urandomb(bnz_t& d, unsigned b)
    {
        if(!initialized) ZK_HANDLE_ERROR("not initialized");
        bnz_urandomb(d, randstate, b);
    }

    int Random::probable_prime_p(const bnz_t& p, int prob, unsigned long div)
    {
#if (defined __MPIR_VERSION) && (__MPIR_VERSION > 1 || (__MPIR_VERSION == 1 && __MPIR_VERSION_MINOR >= 3) )
        if(!initialized) ZK_HANDLE_ERROR("not initialized");
        return bnz_probable_prime_p(p, randstate, prob, div);
#else
        (void) div;
        return bnz_probab_prime_p(p, prob);
#endif
    }

}

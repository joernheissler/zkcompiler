#include <stdio.h>

#include "bignum/bignum.hpp"
#include "random/random.hpp"


using namespace std;

using namespace ZKCompiler;

int main()
{
    printf("Initializing random functions  ... ");
    Random::init();
    printf("done.\n");

    unsigned i;
    unsigned primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 509, 1019};
    unsigned nonprimes[] = { 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22 };

    bnz_t x, min, max;
    bnz_init(x);
    bnz_init_set_si(min, -20);
    bnz_init_set_si(max, 20);

    printf("testing range[-20..20)         ... ");
    for(i = 0; i < 100; ++i) {
        Random::range(x, min, max);

        if(bnz_cmp(x, min) < 0) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) >= 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    printf("testing range[NULL..20)        ... ");
    for(i = 0; i < 100; ++i) {
        Random::range0(x, max);

        if(bnz_sgn(x) == -1) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) >= 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");
    
    printf("testing posrange[0..20)        ... ");
    for(i = 0; i < 100; ++i) {
        Random::posrange(x, max);

        if(bnz_sgn(x) == -1) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) >= 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    printf("testing irange[-20..20]        ... ");
    for(i = 0; i < 100; ++i) {
        Random::irange(x, min, max);

        if(bnz_cmp(x, min) < 0) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) > 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    printf("testing irange[NULL..20]       ... ");
    for(i = 0; i < 100; ++i) {
        Random::irange0(x, max);

        if(bnz_sgn(x) == -1) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) > 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    printf("Initializing random functions a second time ... ");
    Random::init();
    printf("done.\n");

    printf("testing bits[32]               ... ");
    for(i = 0; i < 100; ++i) {
        Random::bits(x, 32);

        if(bnz_sgn(x) == -1) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp_ui(x, 0xfffffffflu) > 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");
    
    printf("testing exactbits[32]          ... ");
    for(i = 0; i < 100; ++i) {
        Random::exactbits(x, 32);

        if(bnz_cmp_ui(x, 0x80000000lu) < 0) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp_ui(x, 0xfffffffflu) > 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    printf("testing is_prime               ... ");
    for(i = 0; i < sizeof primes / sizeof *primes; ++i) {
        bnz_set_ui(x, primes[i]);
        if(!Random::is_prime(x)) {
            printf("err0\n");
            return 1;
        }
    }
    for(i = 0; i < sizeof nonprimes / sizeof *nonprimes; ++i) {
        bnz_set_ui(x, nonprimes[i]);
        if(Random::is_prime(x)) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    bnz_set_ui(min, 20);
    bnz_set_ui(max, 100);
    printf("testing prange[20, 100)        ... ");
    for(i = 0; i < 100; ++i) {
        Random::prange(x, min, max);
        if(bnz_cmp(x, min) < 0) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) >= 0) {
            printf("err1\n");
            return 1;
        }
        unsigned f = 0;
        for(unsigned j = 0; j < sizeof primes / sizeof *primes; ++j) {
            if(bnz_cmp_ui(x, primes[j]) == 0) f = 1;
        }
        if(f != 1) {
            printf("err2\n");
            return 1;
        }
    }
    printf("done.\n");
    
    printf("testing pposrange[0..100)      ... ");
    for(i = 0; i < 100; ++i) {
        Random::pposrange(x, max);
        if(bnz_sgn(x) == -1) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) >= 0) {
            printf("err1\n");
            return 1;
        }
        unsigned f = 0;
        for(unsigned j = 0; j < sizeof primes / sizeof *primes; ++j) {
            if(bnz_cmp_ui(x, primes[j]) == 0) f = 1;
        }
        if(f != 1) {
            printf("err2\n");
            return 1;
        }
    }
    printf("done.\n");
    
    bnz_set_ui(max, 101);
    printf("testing pirange[NULL, 101]     ... ");
    for(i = 0; i < 100; ++i) {
        Random::pirange0(x, max);
        if(bnz_sgn(x) <= 0) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp(x, max) > 0) {
            printf("err1\n");
            return 1;
        }
        unsigned f = 0;
        for(unsigned j = 0; j < sizeof primes / sizeof *primes; ++j) {
            if(bnz_cmp_ui(x, primes[j]) == 0) f = 1;
        }
        if(f != 1) {
            printf("err2\n");
            return 1;
        }
    }
    printf("done.\n");
    
    printf("uninitializing random functions the first time... ");
    Random::free();
    printf("done.\n");
    
    printf("testing pbits[32]              ... ");
    for(i = 0; i < 100; ++i) {
        Random::pbits(x, 32);

        if(bnz_sgn(x) == -1) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp_ui(x, 0xfffffffflu) > 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");
    
    printf("testing pexactbits[32]         ... ");
    for(i = 0; i < 100; ++i) {
        Random::pexactbits(x, 32);

        if(bnz_cmp_ui(x, 0x80000000lu) < 0) {
            printf("err0\n");
            return 1;
        }
        if(bnz_cmp_ui(x, 0xfffffffflu) > 0) {
            printf("err1\n");
            return 1;
        }
    }
    printf("done.\n");

    printf("uninitializing random functions... ");
    Random::free();
    printf("done.\n");
    bnz_clear(min);
    bnz_clear(max);
    bnz_clear(x);

    return 0;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "bignum/bignum.hpp"

#include <cassert>
#include <gmp.h>

namespace ZKCompiler {

#define TO_MPZ(bnz) ((bnz).ref<mpz_t>())
#define TO_RS(randstate) ((randstate).ref<gmp_randstate_t>())

bnz_t::bnz_t() : _pData(new __mpz_struct), _reference(false)
{
}

bnz_t::~bnz_t()
{
    assert(_pData != NULL);
    if (!isRef())
        delete (__mpz_struct*)_pData;
}

bn_randstate_t::bn_randstate_t() : _pData(new __gmp_randstate_struct), _reference(false)
{
}

bn_randstate_t::~bn_randstate_t()
{
    assert(_pData != NULL);
    if (!isRef())
        delete (__gmp_randstate_struct*)_pData;
}


// Custom Allocation
void bn_get_memory_functions(void*(**fpAlloc)(size_t), void*(**fpRealloc)(void*, size_t, size_t), void(**fpFree)(void *, size_t))
{
    mp_get_memory_functions(fpAlloc, fpRealloc, fpFree);
}

// Random State Initialization
void bn_randinit_default(bn_randstate_t& rState)
{
    gmp_randinit_default(TO_RS(rState));
}

void bn_randclear(bn_randstate_t& rState)
{
    gmp_randclear(TO_RS(rState));
}

// Random State Seeding
void bn_randseed(bn_randstate_t& rState, const bnz_t& rSeed)
{
    gmp_randseed(TO_RS(rState), TO_MPZ(rSeed));
}

// Integer Functions
// Initialization Functions
void bnz_init(bnz_t& rX)
{
    mpz_init(TO_MPZ(rX));
}

void bnz_clear(bnz_t& rX)
{
    mpz_clear(TO_MPZ(rX));
}

// Assignment Functions
void bnz_set(bnz_t& rROp, const bnz_t& rOp)
{
    mpz_set(TO_MPZ(rROp), TO_MPZ(rOp));
}

void bnz_set_ui(bnz_t& rROp, unsigned long int op)
{
    mpz_set_ui(TO_MPZ(rROp), op);
}

int bnz_set_str(bnz_t& rROp, const char* pStr, int base)
{
    return mpz_set_str(TO_MPZ(rROp), pStr, base);
}

void bnz_swap(bnz_t& rROp1, bnz_t& rROp2)
{
    mpz_swap(TO_MPZ(rROp1), TO_MPZ(rROp2));
}

// Combined Initialization and Assignment Functions
void bnz_init_set(bnz_t& rROp, const bnz_t& rOp)
{
    mpz_init_set(TO_MPZ(rROp), TO_MPZ(rOp));
}

void bnz_init_set_ui(bnz_t& rROp, unsigned long int op)
{
    mpz_init_set_ui(TO_MPZ(rROp), op);
}

void bnz_init_set_si(bnz_t& rROp, signed long int op)
{
    mpz_init_set_si(TO_MPZ(rROp), op);
}

int bnz_init_set_str(bnz_t& rROp, const char* pStr, int base)
{
    return mpz_init_set_str(TO_MPZ(rROp), pStr, base);
}

// Conversion Functions
unsigned long bnz_get_ui(const bnz_t& rOp)
{
    return mpz_get_ui(TO_MPZ(rOp));
}

char* bnz_get_str(char* pStr, int base, const bnz_t& rOp)
{
    return mpz_get_str(pStr, base, TO_MPZ(rOp));
}

// Arithmetic Functions
void bnz_add(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2)
{
    mpz_add(TO_MPZ(rROp), TO_MPZ(rOp1), TO_MPZ(rOp2));
}

void bnz_add_ui(bnz_t& rROp, const bnz_t& rOp1, unsigned long int op2)
{
    mpz_add_ui(TO_MPZ(rROp), TO_MPZ(rOp1), op2);
}

void bnz_sub(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2)
{
    mpz_sub(TO_MPZ(rROp), TO_MPZ(rOp1), TO_MPZ(rOp2));
}

void bnz_sub_ui(bnz_t& rROp, const bnz_t& rOp1, unsigned long int op2)
{
    mpz_sub_ui(TO_MPZ(rROp), TO_MPZ(rOp1), op2);
}

void bnz_mul(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2)
{
    mpz_mul(TO_MPZ(rROp), TO_MPZ(rOp1), TO_MPZ(rOp2));
}

void bnz_mul_si(bnz_t& rROp, const bnz_t& rOp1, long int op2)
{
    mpz_mul_si(TO_MPZ(rROp), TO_MPZ(rOp1), op2);
}

void bnz_mul_2exp(bnz_t& rROp, const bnz_t& rOp1, bn_bitcnt_t op2)
{
    mpz_mul_2exp(TO_MPZ(rROp), TO_MPZ(rOp1), op2);
}

void bnz_neg(bnz_t& rROp, const bnz_t& rOp)
{
    mpz_neg(TO_MPZ(rROp), TO_MPZ(rOp));
}

// Division Functions
void bnz_divexact(bnz_t& rQ, const bnz_t& rN, const bnz_t& rD)
{
    mpz_divexact(TO_MPZ(rQ), TO_MPZ(rN), TO_MPZ(rD));
}

void bnz_tdiv_q_2exp(bnz_t& rQ, const bnz_t& rN, bn_bitcnt_t b)
{
    mpz_tdiv_q_2exp(TO_MPZ(rQ), TO_MPZ(rN), b);
}

void bnz_tdiv_q(bnz_t& rQ, const bnz_t& rN, const bnz_t& rD)
{
    mpz_tdiv_q(TO_MPZ(rQ), TO_MPZ(rN), TO_MPZ(rD));
}

void bnz_mod(bnz_t& rR, const bnz_t& rN, const bnz_t& rD)
{
    mpz_mod(TO_MPZ(rR), TO_MPZ(rN), TO_MPZ(rD));
}

// Exponentiation Functions
void bnz_powm(bnz_t& rROp, const bnz_t& rBase, const bnz_t& rExp, const bnz_t& rMod)
{
    mpz_powm(TO_MPZ(rROp), TO_MPZ(rBase), TO_MPZ(rExp), TO_MPZ(rMod));
}

void bnz_powm_ui(bnz_t& rROp, const bnz_t& rBase, unsigned long int exp, const bnz_t& rMod)
{
    mpz_powm_ui(TO_MPZ(rROp), TO_MPZ(rBase), exp, TO_MPZ(rMod));
}

void bnz_pow_ui(bnz_t& rROp, const bnz_t& rBase, unsigned long int exp)
{
    mpz_pow_ui(TO_MPZ(rROp), TO_MPZ(rBase), exp);
}

void bnz_ui_pow_ui(bnz_t& rROp, unsigned long int base, unsigned long int exp)
{
    mpz_ui_pow_ui(TO_MPZ(rROp), base, exp);
}

// Root Extraction Functions
void bnz_sqrt(bnz_t& rROp, const bnz_t& rOp)
{
    mpz_sqrt(TO_MPZ(rROp), TO_MPZ(rOp));
}

// Number Theoretic Functions
int bnz_probab_prime_p(const bnz_t& rN, int reps)
{
    return mpz_probab_prime_p(TO_MPZ(rN), reps);
}

void bnz_gcd(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2)
{
    mpz_gcd(TO_MPZ(rROp), TO_MPZ(rOp1), TO_MPZ(rOp2));
}

unsigned long int bnz_gcd_ui(bnz_t* pROp, const bnz_t& rOp1, unsigned long int op2)
{
    return mpz_gcd_ui(pROp != NULL ? TO_MPZ(*pROp) : 0, TO_MPZ(rOp1), op2);
}

int bnz_invert(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2)
{
    return mpz_invert(TO_MPZ(rROp), TO_MPZ(rOp1), TO_MPZ(rOp2));
}

// Comparison Functions
int bnz_sgn(const bnz_t& rOp)
{
    return mpz_sgn(TO_MPZ(rOp));
}

int bnz_cmp(const bnz_t& rOp1, const bnz_t& rOp2)
{
    return mpz_cmp(TO_MPZ(rOp1), TO_MPZ(rOp2));
}

int bnz_cmp_ui(const bnz_t& rOp1, unsigned long int op2)
{
    return mpz_cmp_ui(TO_MPZ(rOp1), op2);
}

int bnz_cmp_si(const bnz_t& rOp1, signed long int op2)
{
    return mpz_cmp_si(TO_MPZ(rOp1), op2);
}

// Logical and Bit Manipulation Functions
size_t bnz_sizeinbase(const bnz_t& rOp, int base)
{
    return mpz_sizeinbase(TO_MPZ(rOp), base);
}

void bnz_setbit(bnz_t& rROp, bn_bitcnt_t bitIndex)
{
    mpz_setbit(TO_MPZ(rROp), bitIndex);
}

int bnz_tstbit(const bnz_t& rOp, bn_bitcnt_t bitIndex)
{
    return mpz_tstbit(TO_MPZ(rOp), bitIndex);
}

// Random Number Functions
void bnz_urandomb(bnz_t& rROp, bn_randstate_t& rState, bn_bitcnt_t n)
{
    mpz_urandomb(TO_MPZ(rROp), TO_RS(rState), n);
}

void bnz_urandomm(bnz_t& rROp, bn_randstate_t& rState, const bnz_t& rN)
{
    mpz_urandomm(TO_MPZ(rROp), TO_RS(rState), TO_MPZ(rN));
}

// Integer Import and Export
void bnz_import(bnz_t& rROp, size_t count, int order, size_t size, int endian, size_t nails, const void* pOp)
{
    mpz_import(TO_MPZ(rROp), count, order, size, endian, nails, pOp);
}

void* bnz_export(void* pROp, size_t* pCount, int order, size_t size, int endian, size_t nails, const bnz_t& rOp)
{
    return mpz_export(pROp, pCount, order, size, endian, nails, TO_MPZ(rOp));
}

// Miscellaneous Functions
bn_bitcnt_t bnz_scan1(const bnz_t& rOp, bn_bitcnt_t startingBit)
{
    return mpz_scan1(TO_MPZ(rOp), startingBit);
}


// Formatted Output
// Functions
/*
int bn_vasprintf(char** pp, const char* pFmt, va_list ap)
{
    // To complicate to get this working...
    return gmp_vasprintf(pp, pFmt, ap);
}
*/

}

#endif

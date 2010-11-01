#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_BIGNUM_HPP
#define ZK_BIGNUM_HPP

#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include "CodeManagement/ccw/impl/CopyableVariable.hpp"
#include "CodeManagement/ccw/impl/Function.hpp"
#include "CodeManagement/ccw/impl/Operator.hpp"
#include "CodeManagement/ccw/impl/Procedure.hpp"
#include "CodeManagement/core/impl/CodeManager.hpp"
#include "util/basictypes.hpp"

// TODO: change to a class with static members?

namespace ZKCompiler
{
    // Don't use with malloc/free, because of the missing constructor/destructor call!
    class bnz_t
    {
    public:
        bnz_t();
        ~bnz_t();
        // No type checking! Use with care!!!
        template<typename T> explicit bnz_t(T& rRef) : _pData(&rRef), _reference(true) {}
        // No type checking! const modifier is ignored for comfort... Use with care!!!
        template<typename T> explicit bnz_t(const T& rRef) : _pData(const_cast<T*>(&rRef)), _reference(true) {}
        // No type checking! Use with care!!!
        // For use with mpz_t call as follows: bnzVar.ref<mpz_t>(); .
        template<typename T> T& ref() { return *(T*)_pData; }
        // No type checking! Use with care!!!
        // For use with mpz_t call as follows: bnzVar.ref<mpz_t>(); .
        template<typename T> const T& ref() const { return *(T*)_pData; }
        bool isRef() const { return _reference; }

    private:
        // Forbid construction from a pointer/array. When using with arrays it leads to segmentation fault!
        // For use with mpz_t call the indirection operator: bnz_t bnzVar(*mpzVar); .
        template<typename T> bnz_t(T* pRef) : _pData(pRef), _reference(true) { assert(false); }
        // Forbid construction from a pointer/array. When using mpz_t this leads to segmentation fault!
        // For use with mpz_t call the indirection operator: bnz_t bnzVar(*mpzVar); .
        template<typename T> bnz_t(const T* pRef) : _pData(const_cast<T*>(pRef)), _reference(true) { assert(false); }
        // forbid call by name
        bnz_t(const bnz_t&) : _pData(NULL), _reference(false) { assert(false); }
        // forbid assignment
        bnz_t& operator=(const bnz_t&) { assert(false); return *this; }

    private:
        void* const _pData;
        const bool _reference;
    };

    // Don't use with malloc/free, because of the missing constructor/destructor call!
    class bn_randstate_t
    {
    public:
        bn_randstate_t();
        ~bn_randstate_t();
        template<typename T> explicit bn_randstate_t(T& rRef) : _pData(&rRef), _reference(true) {}
        template<typename T> explicit bn_randstate_t(const T& rRef) : _pData(const_cast<T*>(&rRef)), _reference(true) {}
        template<typename T> T& ref() { return *(T*)_pData; }
        template<typename T> const T& ref() const { return *(T*)_pData; }
        bool isRef() const { return _reference; }

    private:
        template<typename T> bn_randstate_t(T* pRef) : _pData(pRef), _reference(true) { assert(false); }
        template<typename T> bn_randstate_t(const T* pRef) : _pData(const_cast<T*>(pRef)), _reference(true) { assert(false); }
        bn_randstate_t(const bn_randstate_t&) : _pData(NULL), _reference(false) { assert(false); }
        bn_randstate_t& operator=(const bn_randstate_t&) { assert(false); return *this; }

    private:
        void* const _pData;
        const bool _reference;
    };

    typedef unsigned long int bn_bitcnt_t;

    // Custom Allocation
    void bn_get_memory_functions(void*(**fpAlloc)(size_t), void*(**fpRealloc)(void*, size_t, size_t), void(**fpFree)(void *, size_t));

    // Random State Initialization
    void bn_randinit_default(bn_randstate_t& rState);
    void bn_randclear(bn_randstate_t& rState);
    // Random State Seeding
    void bn_randseed(bn_randstate_t& rState, const bnz_t& rSeed);

    // Integer Functions
    // Initialization Functions
    void bnz_init(bnz_t& rX);
    void bnz_clear(bnz_t& rX);
    // Assignment Functions
    void bnz_set(bnz_t& rROp, const bnz_t& rOp);
    void bnz_set_ui(bnz_t& rROp, unsigned long int op);
    int bnz_set_str(bnz_t& rROp, const char* pStr, int base);
    void bnz_swap(bnz_t& rROp1, bnz_t& rROp2);
    // Combined Initialization and Assignment Functions
    void bnz_init_set(bnz_t& rROp, const bnz_t& rOp);
    void bnz_init_set_ui(bnz_t& rROp, unsigned long int op);
    void bnz_init_set_si(bnz_t& rROp, signed long int op);
    int bnz_init_set_str(bnz_t& rROp, const char* pStr, int base);
    // Conversion Functions
    unsigned long bnz_get_ui(const bnz_t& rOp);
    char* bnz_get_str(char* pStr, int base, const bnz_t& rOp);
    // Arithmetic Functions
    void bnz_add(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2);
    void bnz_add_ui(bnz_t& rROp, const bnz_t& rOp1, unsigned long int op2);
    void bnz_sub(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2);
    void bnz_sub_ui(bnz_t& rROp, const bnz_t& rOp1, unsigned long int op2);
    void bnz_mul(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2);
    void bnz_mul_si(bnz_t& rROp, const bnz_t& rOp1, long int op2);
    void bnz_mul_2exp(bnz_t& rROp, const bnz_t& rOp1, bn_bitcnt_t op2);
    void bnz_neg(bnz_t& rROp, const bnz_t& rOp);
    // Division Functions
    void bnz_divexact(bnz_t& rQ, const bnz_t& rN, const bnz_t& rD);
    void bnz_tdiv_q(bnz_t& rQ, const bnz_t& rN, const bnz_t& rD);
    void bnz_tdiv_q_2exp(bnz_t& rQ, const bnz_t& rN, bn_bitcnt_t b);
    void bnz_mod(bnz_t& rR, const bnz_t& rN, const bnz_t& rD);
    // Exponentiation Functions
    void bnz_powm(bnz_t& rROp, const bnz_t& rBase, const bnz_t& rExp, const bnz_t& rMod);
    void bnz_powm_ui(bnz_t& rROp, const bnz_t& rBase, unsigned long int exp, const bnz_t& rMod);
    void bnz_pow_ui(bnz_t& rROp, const bnz_t& rBase, unsigned long int exp);
    void bnz_ui_pow_ui(bnz_t& rROp, unsigned long int base, unsigned long int exp);
    // Root Extraction Functions
    void bnz_sqrt(bnz_t& rROp, const bnz_t& rOp);
    // Number Theoretic Functions
    int bnz_probab_prime_p(const bnz_t& rN, int reps);
    void bnz_gcd(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2);
    unsigned long int bnz_gcd_ui(bnz_t* pROp, const bnz_t& rOp1, unsigned long int op2);
    int bnz_invert(bnz_t& rROp, const bnz_t& rOp1, const bnz_t& rOp2);
    // Comparison Functions
    int bnz_sgn(const bnz_t& rOp);
    int bnz_cmp(const bnz_t& rOp1, const bnz_t& rOp2) ;
    int bnz_cmp_ui(const bnz_t& rOp1, unsigned long int op2);
    int bnz_cmp_si(const bnz_t& rOp1, signed long int op2);
    // Logical and Bit Manipulation Functions
    bn_bitcnt_t bnz_scan1(const bnz_t& rOp, bn_bitcnt_t startingBit);
    void bnz_setbit(bnz_t& rROp, bn_bitcnt_t bitIndex);
    int bnz_tstbit(const bnz_t& rOp, bn_bitcnt_t bitIndex);
    // Random Number Functions
    void bnz_urandomb(bnz_t& rROp, bn_randstate_t& rState, bn_bitcnt_t n);
    void bnz_urandomm(bnz_t& rROp, bn_randstate_t& rState, const bnz_t& rN);
    // Integer Import and Export
    void bnz_import(bnz_t& rROp, size_t count, int order, size_t size, int endian, size_t nails, const void* pOp);
    void* bnz_export(void* pROp, size_t* pCount, int order, size_t size, int endian, size_t nails, const bnz_t& rOp);
    // Miscellaneous Functions
    size_t bnz_sizeinbase(const bnz_t& rOp, int base);

    // Formatted Output
    // Functions
    /*
    int bn_vasprintf(char** pp, const char* pFmt, va_list ap);
    */

    /** \brief converts bignum to std::string
     * It can be easily and safely used with fprintf() because of the automatic memory management.
     *  \param rOp bignum to convert
     ** \param base base of the bignum
     **/
    std::string bnToStr(const bnz_t& rOp, int base = 10);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Definitions for code management.

    void bnz_getAsDynamicString(zk_pcchar_t& rStr, zk_int_t base, const bnz_t& rOp);
    bnz_t* bnz_constConstructor(const bnz_t& rInitConstant);
    void bnz_constDestructor(bnz_t* pThis);
}

CMD_CODE_DEFINITIONS_BLOCK_EX(ZKCompiler)
{
    //CMD_COPYABLE_TYPE(bn_bitcnt_t) // This is just a basic type already defined!
    CMD_TYPE(bnz_t)
    CMD_CONST_INSTANCES_HANDLING(bnz_t, ZKCompiler::bnz_constConstructor, ZKCompiler::bnz_constDestructor)

    // Custom Allocation
    //void bn_get_memory_functions(void*(**fpAlloc)(size_t), void*(**fpRealloc)(void*, size_t, size_t), void(**fpFree)(void *, size_t));
    //
    // Random State Initialization
    //void bn_randinit_default(bn_randstate_t& rState);
    //void bn_randclear(bn_randstate_t& rState);
    // Random State Seeding
    //void bn_randseed(bn_randstate_t& rState, const bnz_t& rSeed);
    //
    // Integer Functions
    // Initialization Functions
    CMD_PROCEDURE_o1(bnz_init, bnz_t)
    CMD_PROCEDURE_o1(bnz_clear, bnz_t)
    // Assignment Functions
    CMD_PROCEDURE_o1i1(bnz_set, bnz_t, bnz_t, const bnz_t&)
    CMD_PROCEDURE_o1i1(bnz_set_ui, bnz_t, zk_ulong_t, zk_ulong_t)
    CMD_FUNCTION_o1i2(zk_int_t, bnz_set_str, bnz_t, zk_pcchar_t, zk_int_t, zk_pcchar_t, zk_int_t)
    //void bnz_swap(bnz_t& rROp1, bnz_t& rROp2);
    // Combined Initialization and Assignment Functions
    CMD_PROCEDURE_o1i1(bnz_init_set, bnz_t, bnz_t, const bnz_t&)
    CMD_PROCEDURE_o1i1(bnz_init_set_ui, bnz_t, zk_ulong_t, zk_ulong_t)
    CMD_PROCEDURE_o1i1(bnz_init_set_si, bnz_t, zk_long_t, zk_long_t)
    CMD_FUNCTION_o1i2(zk_int_t, bnz_init_set_str, bnz_t, zk_pcchar_t, zk_int_t, zk_pcchar_t, zk_int_t)
    // Conversion Functions
    //unsigned long bnz_get_ui(const bnz_t& rOp);
    //char* bnz_get_str(char* pStr, int base, const bnz_t& rOp);
    // Arithmetic Functions
    CMD_PROCEDURE_o1i2(bnz_add, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_PROCEDURE_o1i2(bnz_add_ui, bnz_t, bnz_t, zk_ulong_t, const bnz_t&, zk_ulong_t)
    CMD_PROCEDURE_o1i2(bnz_sub, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_PROCEDURE_o1i2(bnz_sub_ui, bnz_t, bnz_t, zk_ulong_t, const bnz_t&, zk_ulong_t)
    CMD_PROCEDURE_o1i2(bnz_mul, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_PROCEDURE_o1i2(bnz_mul_si, bnz_t, bnz_t, zk_long_t, const bnz_t&, zk_long_t)
    CMD_PROCEDURE_o1i2(bnz_mul_2exp, bnz_t, bnz_t, bn_bitcnt_t, const bnz_t&, bn_bitcnt_t)
    CMD_PROCEDURE_o1i1(bnz_neg, bnz_t, bnz_t, const bnz_t&)
    // Division Functions
    CMD_PROCEDURE_o1i2(bnz_tdiv_q_2exp, bnz_t, bnz_t, bn_bitcnt_t, const bnz_t&, bn_bitcnt_t)
    CMD_PROCEDURE_o1i2(bnz_mod, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    // Exponentiation Functions
    CMD_PROCEDURE_o1i3(bnz_powm, bnz_t, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&, const bnz_t&)
    //void bnz_powm(bnz_t& rROp, const bnz_t& rBase, const bnz_t& rExp, const bnz_t& rMod);
    CMD_PROCEDURE_o1i3(bnz_powm_ui, bnz_t, bnz_t, zk_ulong_t, bnz_t, const bnz_t&, zk_ulong_t, const bnz_t&)
    //void bnz_powm_ui(bnz_t& rROp, const bnz_t& rBase, unsigned long int exp, const bnz_t& rMod);
    //void bnz_pow_ui(bnz_t& rROp, const bnz_t& rBase, unsigned long int exp);
    //void bnz_ui_pow_ui(bnz_t& rROp, unsigned long int base, unsigned long int exp);
    // Root Extraction Functions
    //void bnz_sqrt(bnz_t& rROp, const bnz_t& rOp);
    // Number Theoretic Functions
    //int bnz_probab_prime_p(const bnz_t& rN, int reps);
    CMD_PROCEDURE_o1i2(bnz_gcd, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    //unsigned long int bnz_gcd_ui(bnz_t* pROp, const bnz_t& rOp1, unsigned long int op2);
    CMD_FUNCTION_o1i2(zk_int_t, bnz_invert, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    // Comparison Functions
    //int bnz_sgn(const bnz_t& rOp);
    CMD_FUNCTION_i2(zk_int_t, bnz_cmp, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_FUNCTION_i2(zk_int_t, bnz_cmp_ui, bnz_t, zk_ulong_t, const bnz_t&, zk_ulong_t)
    //int bnz_cmp_si(const bnz_t& rOp1, signed long int op2);
    // Logical and Bit Manipulation Functions
    //bn_bitcnt_t bnz_scan1(const bnz_t& rOp, bn_bitcnt_t startingBit);
    //void bnz_setbit(bnz_t& rROp, bn_bitcnt_t bitIndex);
    //int bnz_tstbit(const bnz_t& rOp, bn_bitcnt_t bitIndex);
    // Random Number Functions
    //void bnz_urandomb(bnz_t& rROp, bn_randstate_t& rState, bn_bitcnt_t n);
    //void bnz_urandomm(bnz_t& rROp, bn_randstate_t& rState, const bnz_t& rN);
    // Integer Import and Export
    //void bnz_import(bnz_t& rROp, size_t count, int order, size_t size, int endian, size_t nails, const void* pOp);
    //void* bnz_export(void* pROp, size_t* pCount, int order, size_t size, int endian, size_t nails, const bnz_t& rOp);
    // Miscellaneous Functions
    //size_t bnz_sizeinbase(const bnz_t& rOp, int base);

    CMD_PROCEDURE_o1i2(bnz_getAsDynamicString, zk_pcchar_t, zk_int_t, bnz_t, zk_int_t, const bnz_t&)
    //CMD_PROCEDURE_o1(pcchar_freeDynamicString, zk_pcchar_t)
}

#endif

#endif

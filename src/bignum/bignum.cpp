#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "bignum/bignum.hpp"

using namespace ZKCompiler;

std::string ZKCompiler::bnToStr(const bnz_t& rOp, int base)
{
    zk_pcchar_t dynStr;
    bnz_getAsDynamicString(dynStr, base, rOp);
    std::string str = dynStr;
    pcchar_freeDynamicString(dynStr);
    return str;
}

void ZKCompiler::bnz_getAsDynamicString(zk_pcchar_t& rStr, zk_int_t base, const bnz_t& rOp)
{
    size_t size = bnz_sizeinbase(rOp, base) + 2;
    char* pStr = new char[size];
    bnz_get_str(pStr, base, rOp);
    rStr = pStr;
}

bnz_t* ZKCompiler::bnz_constConstructor(const bnz_t& rInitConstant)
{
    bnz_t* p = new bnz_t;
    bnz_init_set(*p, rInitConstant);
    return p;
}

void ZKCompiler::bnz_constDestructor(bnz_t* pThis)
{
    assert(pThis != NULL);
    bnz_clear(*pThis);
    delete pThis;
}

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include <cstring>
#include "util/basictypes.hpp"

using namespace ZKCompiler;

void ZKCompiler::pcchar_freeDynamicString(zk_pcchar_t& rString)
{
    assert(rString != NULL);
    delete[] rString;
    rString = NULL;
}

zk_pcchar_t* ZKCompiler::pcchar_constConstructor(const zk_pcchar_t& rInitConstant)
{
    zk_pchar_t* p = new zk_pchar_t;
    *p = new char[::strlen(rInitConstant) + 1];
    ::strcpy(*p, rInitConstant);
    return (zk_pcchar_t*)p;
}

void ZKCompiler::pcchar_constDestructor(zk_pcchar_t* pThis)
{
    assert(pThis != NULL);
    assert(*pThis != NULL);
    delete[] *pThis;
    delete pThis;
}

#endif

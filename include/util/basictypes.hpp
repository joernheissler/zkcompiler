#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_BASICTYPES_HPP
#define ZK_BASICTYPES_HPP

#include "CodeManagement/core/impl/CodeManager.hpp"
#include "CodeManagement/ccw/impl/CopyableVariable.hpp"

namespace ZKCompiler
{
    typedef bool zk_bool_t;
    typedef int zk_int_t;
    typedef unsigned int zk_uint_t;
    typedef long zk_long_t;
    typedef unsigned long zk_ulong_t;
    typedef char* zk_pchar_t;
    typedef const char* zk_pcchar_t;

    void pcchar_freeDynamicString(zk_pcchar_t& rString);

    zk_pcchar_t* pcchar_constConstructor(const zk_pcchar_t& rInitConstant);
    void pcchar_constDestructor(zk_pcchar_t* pThis);
}

CMD_CODE_DEFINITIONS_BLOCK_EX(ZKCompiler)
{
    CMD_COPYABLE_TYPE(zk_bool_t)
    CMD_COPYABLE_TYPE(zk_int_t)
    CMD_COPYABLE_TYPE(zk_uint_t)
    CMD_COPYABLE_TYPE(zk_long_t)
    CMD_COPYABLE_TYPE(zk_ulong_t)
    CMD_COPYABLE_TYPE(zk_pcchar_t)
    CMD_CONST_INSTANCES_HANDLING(zk_pcchar_t, ZKCompiler::pcchar_constConstructor, ZKCompiler::pcchar_constDestructor)
}

#endif

#endif

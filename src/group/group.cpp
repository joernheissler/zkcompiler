#include <cstring>
#include "group/group.hpp"
#include "group/z.hpp"
#include "group/z_add_n.hpp"
#include "group/z_mul_n.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    Group::Group(unsigned size_)
    {
        size = size_;
    }

    Group::~Group() { /* nothing to be done */ }
    
    /* Group factory */
    Group *Group::create(Parser *parser, const char *type, unsigned n, const char * const params[])
    {
        if(!strcmp(type, "Z"      )) return new group::Z      (parser, n, params);
        if(!strcmp(type, "Z_add_n")) return new group::Z_add_n(parser, n, params);
        if(!strcmp(type, "Z_mul_n")) return new group::Z_mul_n(parser, n, params);

        ZK_HANDLE_ERROR("unknown group name");
        return NULL;
    }

    unsigned Group::getSize()
    {
        return size;
    }
    
    void Group::set(CMV::bnz_t *dst, const CMV::bnz_t *src)
    {
        unsigned i;
        for(i = 0; i < size; ++i) CMI(bnz_set(dst[i], src[i]));
    }
}

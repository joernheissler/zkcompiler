#include "hash/hash.hpp"

namespace ZKCompiler {
    Hash::Hash(const char *name_, unsigned size_)
    {
        name = name_;
        size = size_;
    }

    Hash::~Hash()
    {
        /* nothing to be done */
    }

    const char *Hash::getName()
    {
        return name;
    }

    unsigned Hash::getSize()
    {
        return size;
    }
}

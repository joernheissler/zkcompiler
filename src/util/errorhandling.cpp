#include <cstdio>
#include "util/errorhandling.hpp"

namespace ZKCompiler {
    void handle_error(const char* pMessage, const char* pFileName, int line) /*throw (const char*)*/
    {
        printf("%s:%d: error: %s\n", pFileName, line, pMessage);
        throw(pMessage);
    }
}

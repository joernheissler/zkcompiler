#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include "bignum/bignum.hpp"
#include "util/zkprint.hpp"


namespace ZKCompiler {
    void printHex(Message msg)
    {
        for(unsigned long i = 0; i < msg.length; ++i) {
            printf("%02x", msg.data[i]);
            if(i % 36 == 35 || i + 1 == msg.length) printf("\n");
        }
        printf("\n");
    }

    void printHex(Message msg, const char *descr)
    {
        int l = (int)strlen(descr) + 3;
        printf("%s = ", descr);
        for(unsigned long i = 0; i < msg.length; ++i) {
            printf("%02x", msg.data[i]);
            if(i % 32 == 31 && i + 1 < msg.length) printf("\n%*s", l, ""); // print l spaces
            else if(i + 1 == msg.length) printf("\n");
            else if(i % 8 == 7) printf("  ");
            else printf(" ");
        }
    }

    /*
    std::ostream& operator<<(std::ostream& rOut, const bnz_t& rOp)
    {
        return rOut << bignumToStr(rOp);
    }
    */

    /*
    int zkprintf(const char *fmt, ...) {
        va_list ap;
        char *p = 0;
        int len;

        va_start(ap, fmt);
        len = bn_vasprintf(&p, fmt, ap);
        if(p) {
            void(*freefunc)(void *, size_t);
            printf("%s", p);
            bn_get_memory_functions(0, 0, &freefunc);
            freefunc(p, len + 1);
        }
        va_end(ap);
        return len;
        return 0;
    }
    */
}

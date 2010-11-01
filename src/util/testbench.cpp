#include <cstdio>
#include <cstring>
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
            if(i % 32 == 31 && i + 1 < msg.length) printf("\n%*s", l, "");
            else if(i + 1 == msg.length) printf("\n");
            else if(i % 8 == 7) printf("  ");
            else printf(" ");
        }
    }
}


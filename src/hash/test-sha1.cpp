#include <cstring>
#include <cstdio>

#include "hash/hash.hpp"
#include "hash/sha1.hpp"

using namespace ZKCompiler;
using namespace std;

int main(void)
{
    Hash *h;
    unsigned char *digest;
    unsigned i;
    const char *dig = "\x60\xfd\xe9\xc2\x31\x0b\x0d\x4c\xad\x4d\xab\x8d\x12\x6b\x04\x38\x7e\xfb\xa2\x89";
    
    h = new SHA1();

    h->update((void*)"Hello, World!\n", 14, 1);
    digest = h->final();

    if(h->getSize() != 20) {
        printf("wrong digest size\n");
        return 1;
    }
    if(memcmp(dig, digest, 20)) {
        printf("wrong digest\n");
        return 2;
    }

    for(i = 0; i < h->getSize(); ++i) {
        printf("%02x", (unsigned)digest[i]);
    }
    printf("\n");

    delete h;

    return 0;
}

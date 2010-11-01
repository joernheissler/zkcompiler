#include <stdio.h>
#include <errno.h>
#include "random/random_seed.h"

unsigned long getRandomSeed(unsigned char *randomdata, unsigned int bytes)
{
    FILE *fd;
    unsigned long ret;

    fd = fopen("/dev/urandom", "rb");
    if(!fd) { ret = (unsigned long)errno; goto out; }
    if(fread(randomdata, 1, bytes, fd) != bytes) { ret = EIO; goto out; }
    ret = 0;
    fclose(fd);
out:
    return ret;
}

#include <climits>

#if !defined(LITTLE_ENDIAN) && !defined(BIG_ENDIAN)
    /* #define BIG_ENDIAN */
    #define LITTLE_ENDIAN
#endif

#ifndef UINT32_T
    #if UINT_MAX == 4294967295ul
        #define UINT32_T unsigned int
    #elif ULONG_MAX == 4294967295ul
        #define UINT32_T unsigned long
    #else
        #error found no 32bit unsigned type.
    #endif
#endif


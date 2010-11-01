#ifndef ZKPRINT_HPP
#define ZKPRINT_HPP

#include <string>
#include <cstdio>
#include "util/convert.hpp"

namespace ZKCompiler {
    /** \brief print a message in a formatted way
     ** \param msg message to print
     **/
    void printHex(Message msg);
    
    /** \brief print a message in a more beautiful way
     ** \param msg message to print
     ** \param descr description of message, e.g. "s"
     **/
    void printHex(Message msg, const char *descr);

    /** \brief print bnz_t as decimal to a stream
     *  \param rOut stream for output
     ** \param rOp bnz_t to print
     **/
    // iostream not implemented in Android yet...
    // For workaround use bignumToStr() with fprintf().
    //std::ostream& operator<<(std::ostream& rOut, const bnz_t& rOp);

    /** \brief wrapper for gmp_printf which uses printf. (android workaround)
     ** \param fmt format string, see gmp_printf for details
     ** \return number of bytes printed
     **/
    // The abstracted implementation of gmp_printf to complicated...
    // For workaround use bignumToStr() with fprintf().
    // int zkprintf(const char *fmt, ...);
}

#endif

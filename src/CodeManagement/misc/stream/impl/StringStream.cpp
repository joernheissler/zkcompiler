#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "misc/stream/impl/StringStream.hpp"

#include <cassert>
#include <cstdio>
#include <climits>

// TODO: improve efficiency (write not immediately!)...

/* number of decimal digits an unsigned integer type can have at most, including terminating 0
 * One needs log_10(2) digits per bit, 28/93 is slightly above this value.
 * If bits * 28 is not divisible by 93, the result is truncated and one byte
 * short, hence add 1.
 *
 * E.g. one needs 32 * l(2)/l(10) ~ 9.6323 ~ 10 bytes for 32 bit unsigned int.
 * floor(32 * 28 / 93) + 1 = floor(9.6344) + 1 = 10
 */
#define UNSIGNED_DIGITS(v) (sizeof(v) * CHAR_BIT * 28 / 93 + 1 + 1)

/* same for signed types; one bit is used as sign bit and the sign needs one more byte */
#define SIGNED_DIGITS(v) ((sizeof(v) * CHAR_BIT * 28 - 1) / 93 + 1 + 1 + 1)

using namespace CodeManagement;

const char* StringStream::toCString() const
{
    return _string.c_str();
}

const std::string& StringStream::toString() const
{
    return _string;
}

AStream& StringStream::operator<<(bool b)
{
    return *this << (b ? "true" : "false");
}

AStream& StringStream::operator<<(char c)
{
    char vStr[2] = {c, '\0'};
    return *this << vStr;
}

AStream& StringStream::operator<<(int d)
{
    char vStr[SIGNED_DIGITS(d)];
    ::sprintf(vStr, "%d", d);
    return *this << vStr;
}

AStream& StringStream::operator<<(unsigned u)
{
    char vStr[UNSIGNED_DIGITS(u)];
    ::sprintf(vStr, "%u", u);
    return *this << vStr;
}

AStream& StringStream::operator<<(long ld)
{
    char vStr[SIGNED_DIGITS(ld)];
    ::sprintf(vStr, "%ld", ld);
    return *this << vStr;
}

AStream& StringStream::operator<<(unsigned long lu)
{
    char vStr[UNSIGNED_DIGITS(lu)];
    ::sprintf(vStr, "%lu", lu);
    return *this << vStr;
}

AStream& StringStream::operator<<(const char* pStr)
{
    assert(pStr != NULL);
    _string += pStr;
    return *this;
}

AStream& StringStream::operator<<(const std::string& rStr)
{
    _string += rStr;
    return *this;
}

#endif

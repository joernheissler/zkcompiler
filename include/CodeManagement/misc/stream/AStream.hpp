#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_STREAM_HPP
#define CM_A_STREAM_HPP

#include <string>

namespace CodeManagement
{
    // FIXME: Handling of non-C++98-standard 64bit signed/unsigned integer types: __int64, long long, ...
    // We need it, because size_t is not always defined as unsigned int! Else we get ambiguous calls of operator <<.

    class AStream
    {
    public:
        virtual ~AStream();

    public:
        virtual AStream& operator<<(bool b) = 0;
        virtual AStream& operator<<(char c) = 0;
        virtual AStream& operator<<(int d) = 0;
        virtual AStream& operator<<(unsigned u) = 0;
        virtual AStream& operator<<(long ld) = 0;
        virtual AStream& operator<<(unsigned long lu) = 0;
        virtual AStream& operator<<(const char* pStr) = 0;
        virtual AStream& operator<<(const std::string& rStr) = 0;
    };

}

#endif

#endif

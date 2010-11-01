#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_STRING_STREAM_HPP
#define CM_STRING_STREAM_HPP

#include "misc/stream/AStream.hpp"

namespace CodeManagement
{

    class StringStream : public AStream
    {
    public:
        const char* toCString() const;
        const std::string& toString() const;

    public:
        virtual AStream& operator<<(bool b);
        virtual AStream& operator<<(char c);
        virtual AStream& operator<<(int d);
        virtual AStream& operator<<(unsigned u);
        virtual AStream& operator<<(long ld);
        virtual AStream& operator<<(unsigned long lu);
        virtual AStream& operator<<(const char* pStr);
        virtual AStream& operator<<(const std::string& rStr);

    private:
        std::string _string;
    };

}

#endif

#endif

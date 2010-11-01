#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_NULL_STREAM_HPP
#define CM_NULL_STREAM_HPP

#include "misc/stream/AStream.hpp"

namespace CodeManagement
{

class NullStream : public AStream
{
public:
    NullStream()
    {
    }
    virtual ~NullStream()
    {
    }

public:
    virtual AStream& operator<<(bool b);
    virtual AStream& operator<<(char c);
    virtual AStream& operator<<(int d);
    virtual AStream& operator<<(unsigned u);
    virtual AStream& operator<<(long ld);
    virtual AStream& operator<<(unsigned long lu);
    virtual AStream& operator<<(const char* pStr);
    virtual AStream& operator<<(const std::string& rStr);

public:
    static NullStream log;

};

}

#endif

#endif

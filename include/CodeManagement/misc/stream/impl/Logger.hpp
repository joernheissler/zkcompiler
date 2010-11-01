#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_LOGGER_HPP
#define CM_LOGGER_HPP

#include "misc/stream/AStream.hpp"

namespace CodeManagement
{

class Logger : public AStream
{
public:
    Logger()
    {
    }
    virtual ~Logger()
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
    static Logger log;

};

}

#endif

#endif

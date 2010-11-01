#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "misc/stream/impl/Logger.hpp"

#include <cstdio>

using namespace CodeManagement;

Logger Logger::log;

AStream& Logger::operator<<(bool b)
{
    ::printf(b ? "true" : "false");
    return *this;
}

AStream& Logger::operator<<(char c)
{
    ::printf("%c", c);
    return *this;
}

AStream& Logger::operator<<(int d)
{
    ::printf("%d", d);
    return *this;
}

AStream& Logger::operator<<(unsigned u)
{
    ::printf("%u", u);
    return *this;
}

AStream& Logger::operator<<(long ld)
{
    ::printf("%ld", ld);
    return *this;
}

AStream& Logger::operator<<(unsigned long lu)
{
    ::printf("%lu", lu);
    return *this;
}

AStream& Logger::operator<<(const char* pStr)
{
    ::printf("%s", pStr);
    return *this;
}

AStream& Logger::operator<<(const std::string& rStr)
{
    ::printf("%s", rStr.c_str());
    return *this;
}

#endif

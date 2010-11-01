#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "misc/stream/impl/NullStream.hpp"

using namespace CodeManagement;

NullStream NullStream::log;

AStream& NullStream::operator<<(bool /*b*/)
{
    return *this;
}

AStream& NullStream::operator<<(char /*c*/)
{
    return *this;
}

AStream& NullStream::operator<<(int /*d*/)
{
    return *this;
}

AStream& NullStream::operator<<(unsigned /*u*/)
{
    return *this;
}

AStream& NullStream::operator<<(long /*ld*/)
{
    return *this;
}

AStream& NullStream::operator<<(unsigned long /*lu*/)
{
    return *this;
}

AStream& NullStream::operator<<(const char* /*pStr*/)
{
    return *this;
}

AStream& NullStream::operator<<(const std::string& /*rStr*/)
{
    return *this;
}

#endif

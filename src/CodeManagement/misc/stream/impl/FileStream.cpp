#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "misc/stream/impl/FileStream.hpp"

#include <cassert>
#include "misc/debug/impl/Exception.hpp"

using namespace CodeManagement;

FileStream::FileStream(const char* pFileName) : _pFile(NULL)
{
    if (pFileName != NULL)
        open(pFileName);
}

FileStream::~FileStream()
{
    if (isOpen())
        close();
}

void FileStream::open(const char* pFileName)
{
    assert(pFileName != NULL);
    if (isOpen())
        close();
    _pFile = ::fopen(pFileName, "w");
}

void FileStream::close()
{
    ::fclose(_pFile);
    _pFile = NULL;
}

bool FileStream::isOpen() const
{
    return _pFile != NULL;
}

AStream& FileStream::operator<<(bool b)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, b ? "true" : "false");
    return *this;
}

AStream& FileStream::operator<<(char c)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%c", c);
    return *this;
}

AStream& FileStream::operator<<(int d)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%d", d);
    return *this;
}

AStream& FileStream::operator<<(unsigned u)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%u", u);
    return *this;
}

AStream& FileStream::operator<<(long ld)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%ld", ld);
    return *this;
}

AStream& FileStream::operator<<(unsigned long lu)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%lu", lu);
    return *this;
}

AStream& FileStream::operator<<(const char* pStr)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%s", pStr);
    return *this;
}

AStream& FileStream::operator<<(const std::string& rStr)
{
    if (!isOpen())
        throw CM_CREATE_EXCEPTION("No file opened for stream!");
    ::fprintf(_pFile, "%s", rStr.c_str());
    return *this;
}

#endif

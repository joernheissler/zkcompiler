#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "misc/debug/impl/DebugInfo.hpp"

#include <cassert>
#include "misc/stream/impl/StringStream.hpp"

using namespace CodeManagement;

bool DebugInfo::_outStreamShowFileNameAndLine = true;
bool DebugInfo::_outStreamShortFileName = true;

DebugInfo::DebugInfo(const std::string& rMessage, const std::string& rFileName, int line) :
    _message(rMessage), _fileName(rFileName), _line(line)
{
}

DebugInfo::~DebugInfo()
{
}

const std::string& DebugInfo::getMessage() const
{
    return _message;
}

const std::string& DebugInfo::getFileName() const
{
    return _fileName;
}

int DebugInfo::getLine() const
{
    return _line;
}

AStream& DebugInfo::outStream(AStream& rStream) const
{
    if (_outStreamShowFileNameAndLine)
        rStream << (_outStreamShortFileName ? getShortFileName() : getFileName()) << ":" << getLine() << ": ";
    rStream << getMessage();
    return rStream;
}

std::string DebugInfo::toString() const
{
    StringStream str;
    str << *this;
    return str.toString();
}

const char* DebugInfo::getShortFileName() const
{
    const char* pShortFileName = _fileName.c_str();

    for (size_t len = _fileName.length() - 2; len > 0; --len)
    {
        pShortFileName = _fileName.c_str() + len;
        if (*(pShortFileName - 1) == '/' || *(pShortFileName - 1) == '\\' /* for windows? */)
            break;
    }

    return pShortFileName;
}

void DebugInfo::setOutStreamShowFileNameAndLine(bool show)
{
    _outStreamShowFileNameAndLine = show;
}

bool DebugInfo::isOutStreamShowFileNameAndLine()
{
    return _outStreamShowFileNameAndLine;
}

void DebugInfo::setOutStreamShortFileName(bool shortFileName)
{
    _outStreamShortFileName = shortFileName;
}

bool DebugInfo::isOutStreamShortFileName()
{
    return _outStreamShortFileName;
}

AStream& CodeManagement::operator<<(AStream& rStream, const DebugInfo& rDebugInfo)
{
    return rDebugInfo.outStream(rStream);
}

#endif

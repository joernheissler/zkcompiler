#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "misc/debug/impl/Exception.hpp"

#include "misc/stream/impl/Logger.hpp"

using namespace CodeManagement;

bool Exception::_logOnConstruction = true;

Exception::Exception(const std::string& rMessage, const std::string& rFileName, int line) :
    DebugInfo(rMessage, rFileName, line)
{
    if (_logOnConstruction)
        Logger::log << *this << "\n";
}

AStream& Exception::outStream(AStream& rStream) const
{
    // Ignore all out stream settings of DebugInfo!
    rStream << getFileName() << ":" << getLine() << ": [EXCEPTION] " << getMessage();
    return rStream;
}

#endif

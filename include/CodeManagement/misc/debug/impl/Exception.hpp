#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_EXCEPTION_HPP
#define CM_EXCEPTION_HPP

#include "misc/debug/impl/DebugInfo.hpp"

#define CM_CREATE_EXCEPTION(message) CodeManagement::Exception(message, __FILE__, __LINE__)

namespace CodeManagement
{

    class Exception : public DebugInfo
    {
    public:
        Exception(const std::string& rMessage, const std::string& rFileName, int line);

    public:
        virtual AStream& outStream(AStream& rStream) const;

    public:
        static bool _logOnConstruction;
    };

}

#endif

#endif

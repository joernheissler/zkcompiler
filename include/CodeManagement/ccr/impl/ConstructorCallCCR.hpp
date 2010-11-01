#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_CONSTRUCTOR_CALL_CCR_HPP
#define CM_CONSTRUCTOR_CALL_CCR_HPP

#include "ccr/AConstructorCallCCR.hpp"

namespace CodeManagement
{

    template<class TSourceType>
    class ConstructorCallCCR : public AConstructorCallCCR
    {
    public:
        typedef TSourceType Source_t;

    public:
        ConstructorCallCCR(const DebugInfo& rDebugInfo) : AConstructorCallCCR(rDebugInfo)
        {
        }
    };

}

#endif

#endif

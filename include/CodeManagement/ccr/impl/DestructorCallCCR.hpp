#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_DESTRUCTOR_CALL_CCR_HPP
#define CM_DESTRUCTOR_CALL_CCR_HPP

#include "ccr/ADestructorCallCCR.hpp"

namespace CodeManagement
{

    template<class TSourceType>
    class DestructorCallCCR : public ADestructorCallCCR
    {
    public:
        typedef TSourceType Source_t;

    public:
        DestructorCallCCR(const DebugInfo& rDebugInfo) : ADestructorCallCCR(rDebugInfo)
        {
        }
    };

}

#endif

#endif

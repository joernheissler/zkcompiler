#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_COPY_ASSIGNMENT_CALL_CCR_HPP
#define CM_COPY_ASSIGNMENT_CALL_CCR_HPP

#include "ccr/ACopyAssignmentCallCCR.hpp"

namespace CodeManagement
{

    template<class TSourceType>
    class CopyAssignmentCallCCR : public ACopyAssignmentCallCCR
    {
    public:
        typedef TSourceType Source_t;

    public:
        CopyAssignmentCallCCR(const DebugInfo& rDebugInfo, const ASourceInstanceCaster* pRHSSrcInstCaster) :
            ACopyAssignmentCallCCR(rDebugInfo, pRHSSrcInstCaster)
        {
        }
    };

}

#endif

#endif

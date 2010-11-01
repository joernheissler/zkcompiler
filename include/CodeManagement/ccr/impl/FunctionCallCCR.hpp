#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_FUNCTION_CALL_CRR_HPP
#define CM_A_FUNCTION_CALL_CRR_HPP

#include "ccr/AFunctionCallCCR.hpp"

namespace CodeManagement
{

    template<class TFunction>
    class FunctionCallCCR : public AFunctionCallCCR
    {
    public:
        typedef AFunctionCallCCR::ExecuteFunc_t ExecuteFunc_t;

    public:
        FunctionCallCCR(ExecuteFunc_t executeFunc, const ASourceInstanceCaster* pReturnSrcInstCaster, bool hasReturnVar, const DebugInfo& rDebugInfo) :
            AFunctionCallCCR(executeFunc, pReturnSrcInstCaster, hasReturnVar, rDebugInfo)
        {
            assert(getInstructionIdentifier() != NULL && getInstructionIdentifier()[0] != '\0');
        }

    public:
        virtual const char* getInstructionIdentifier() const
        {
            return spec_getInstructionIdentifier();
        }

    public:
        static const char* spec_getInstructionIdentifier();
    };

}

#endif

#endif

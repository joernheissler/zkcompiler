#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_PROCEDURE_CALL_CRR_HPP
#define CM_PROCEDURE_CALL_CRR_HPP

#include "ccr/AProcedureCallCCR.hpp"

namespace CodeManagement
{

    template<class TProcedure>
    class ProcedureCallCCR : public AProcedureCallCCR
    {
    public:
        typedef AProcedureCallCCR::ExecuteFunc_t ExecuteFunc_t;

    public:
        ProcedureCallCCR(ExecuteFunc_t executeFunc, const DebugInfo& rDebugInfo) :
            AProcedureCallCCR(executeFunc, rDebugInfo)
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

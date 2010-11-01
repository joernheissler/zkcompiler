#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_PROCEDURE_CALL_CCR_HPP
#define CM_A_PROCEDURE_CALL_CCR_HPP

#include "ccr/AInstructionCallCCR.hpp"

namespace CodeManagement
{

    class AProcedureCallCCR : public AInstructionCallCCR
    {
    public:
        typedef AInstructionCallCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;
        typedef void(*ExecuteFunc_t)(const AProcedureCallCCR&, AExecutableCCR::InstancesTable_t&);
        typedef Base_t::Variables_t Variables_t;
        typedef Base_t::VariablesIter_t VariablesIter_t;
        typedef Base_t::VariablesConstIter_t VariablesConstIter_t;

    protected:
        AProcedureCallCCR(ExecuteFunc_t executeFunc, const DebugInfo& rDebugInfo);

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
    };

}

#endif

#endif

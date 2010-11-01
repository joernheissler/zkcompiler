#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_INSTRUCTION_CALL_CCR_HPP
#define CM_A_INSTRUCTION_CALL_CCR_HPP

#include "ccr/AExecutableCCR.hpp"

namespace CodeManagement
{

    class AInstructionCallCCR : public AExecutableCCR
    {
    public:
        typedef AExecutableCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;
        typedef void(*ExecuteFunc_t)(const AInstructionCallCCR&, AExecutableCCR::InstancesTable_t&, void*);
        typedef Base_t::Variables_t Variables_t;
        typedef Base_t::VariablesIter_t VariablesIter_t;
        typedef Base_t::VariablesConstIter_t VariablesConstIter_t;

    public:
        AInstructionCallCCR(ExecuteFunc_t executeFunc, const DebugInfo& rDebugInfo);
        AVariableInstance& getOutputInstance(InstancesTable_t& rInstancesTable, size_t index) const;
        AVariableInstance& getInputInstance(InstancesTable_t& rInstancesTable, size_t index) const;

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes);
        virtual const char* getInstructionIdentifier() const = 0;

    private:
        const ExecuteFunc_t _executeFunc;

#ifndef CM_ENABLE_CODE_COLLECTING
    public:
        static const char* spec_getInstructionIdentifier() { return ""; }
#endif
    };

}

#endif

#endif

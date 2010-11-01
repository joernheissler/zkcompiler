#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AInstructionCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"

using namespace CodeManagement;

AInstructionCallCCR::AInstructionCallCCR(ExecuteFunc_t executeFunc, const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _executeFunc(executeFunc)
{
}

AVariableInstance& AInstructionCallCCR::getOutputInstance(InstancesTable_t& rInstancesTable, size_t index) const
{
    AVariableInstance* p = rInstancesTable.getVariable(getOutputVariable(index).getVariableId());
    assert(p != NULL);
    return *p;
}

AVariableInstance& AInstructionCallCCR::getInputInstance(InstancesTable_t& rInstancesTable, size_t index) const
{
    AVariableInstance* p = rInstancesTable.getVariable(getInputVariable(index).getVariableId());
    assert(p != NULL);
    return *p;
}

void AInstructionCallCCR::execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy) const
{
    _executeFunc(*this, rInstancesTable, pRetSrcInstCopy);
}

void AInstructionCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AInstructionCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool AInstructionCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes)
{
    return Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, expandVarsScopes);
}

#endif

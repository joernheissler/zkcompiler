#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/ACopyAssignmentCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"
#include "exec/AVariableInstance.hpp"
#include "exec/ASourceInstanceCaster.hpp"

using namespace CodeManagement;

ACopyAssignmentCallCCR::ACopyAssignmentCallCCR(const DebugInfo& rDebugInfo, const ASourceInstanceCaster* pRHSSrcInstCaster) :
    AVarSpecialCallCCR(rDebugInfo), _pRHSVariable(NULL),
    _pRHSSrcInstCaster(pRHSSrcInstCaster != NULL ? pRHSSrcInstCaster->createNewCopy() : NULL)
{
}

ACopyAssignmentCallCCR::~ACopyAssignmentCallCCR()
{
    if (_pRHSSrcInstCaster != NULL)
        delete _pRHSSrcInstCaster;
}

void ACopyAssignmentCallCCR::execute(InstancesTable_t& rInstancesTable, void* /*pRetSrcInstCopy*/) const
{
    const AVariableCCR& rThisVar = getThisVariable();
    const AVariableCCR& rRHS = getRHSVariable();

    AVariableInstance* pInstance = rInstancesTable.getVariable(rThisVar.getVariableId());
    assert(pInstance != NULL);
    const AVariableInstance* pInstanceRHS = rInstancesTable.getVariable(rRHS.getVariableId());
    assert(pInstanceRHS != NULL);
    pInstance->executeCopyAssignment(pInstanceRHS->getConstSourceInstance(), _pRHSSrcInstCaster);
}

void ACopyAssignmentCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void ACopyAssignmentCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool ACopyAssignmentCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables,
    bool expandVarsScopes)
{
    assert(pOutputVariables != NULL);
    assert((*pOutputVariables)[0] != NULL);
    assert(_pThisVariable == NULL);
    _pThisVariable = (*pOutputVariables)[0];
    assert(pInputVariables != NULL);
    assert((*pInputVariables)[0] != NULL);
    assert(_pRHSVariable == NULL);
    _pRHSVariable = (*pInputVariables)[0];

    return Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, expandVarsScopes);
}

bool ACopyAssignmentCallCCR::bindVariables(AVariableCCR& rThis, AVariableCCR& rRHS, bool expandVarsScopes)
{
    return bindVariablesGeneric(new Variables_t(1, &rThis), new Variables_t(1, &rRHS), expandVarsScopes);
}

const AVariableCCR& ACopyAssignmentCallCCR::getRHSVariable() const
{
    assert(_pRHSVariable != NULL);
    return *_pRHSVariable;
}

const ASourceInstanceCaster* ACopyAssignmentCallCCR::getRHSSrcInstCaster() const
{
    return _pRHSSrcInstCaster;
}

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AConstructorCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"
#include "exec/AVariableInstance.hpp"

using namespace CodeManagement;

AConstructorCallCCR::AConstructorCallCCR(const DebugInfo& rDebugInfo) :
    AVarSpecialCallCCR(rDebugInfo)
{
}

AConstructorCallCCR::~AConstructorCallCCR()
{
    if (_pThisVariable != NULL)
    {
        assert(_pThisVariable->getConstructorCRR() == this);
        _pThisVariable->setConstructorCRR(NULL);
    }
}

void AConstructorCallCCR::execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy) const
{
    // TODO: handle pRetSrcInstCopy
    (void)pRetSrcInstCopy;

    const AVariableCCR& rThisVar = getThisVariable();

    AVariableInstance* pInstance = rThisVar.createNewInstance();
    assert(pInstance != NULL);
    rInstancesTable.addNewVariable(rThisVar.getVariableId(), *pInstance);
    assert(pInstance != NULL);
    if (!pInstance->isConstant())
        pInstance->executeConstructor();
}

void AConstructorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AConstructorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool AConstructorCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes)
{
    assert(pOutputVariables != NULL);
    assert((*pOutputVariables)[0] != NULL);
    assert(_pThisVariable == NULL);
    _pThisVariable = (*pOutputVariables)[0];

    bool res = Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, false);

    assert(_pThisVariable->getConstructorCRR() == NULL);
    _pThisVariable->setConstructorCRR(this);

    return expandVarsScopes ? expandAllVarsScopesTillVisible() : res;
}

bool AConstructorCallCCR::bindVariables(AVariableCCR& rThis, bool expandVarScope)
{
    Variables_t* pOutputVariables = new Variables_t(1);
    (*pOutputVariables)[0] = &rThis;
    return bindVariablesGeneric(pOutputVariables, NULL, expandVarScope);
}

#endif

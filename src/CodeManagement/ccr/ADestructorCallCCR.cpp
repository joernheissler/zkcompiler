#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/ADestructorCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"
#include "exec/AVariableInstance.hpp"

using namespace CodeManagement;

ADestructorCallCCR::ADestructorCallCCR(const DebugInfo& rDebugInfo) :
    AVarSpecialCallCCR(rDebugInfo)
{
}

ADestructorCallCCR::~ADestructorCallCCR()
{
    if (_pThisVariable != NULL)
    {
        assert(_pThisVariable->getDestructorCRR() == this);
        _pThisVariable->setDestructorCRR(NULL);
    }
}

void ADestructorCallCCR::execute(InstancesTable_t& rInstancesTable, void* /*pRetSrcInstCopy*/) const
{
    const AVariableCCR& rThisVar = getThisVariable();

    AVariableInstance* pInstance = rInstancesTable.removeVariable(rThisVar.getVariableId(), false);
    assert(pInstance != NULL);
    if (!pInstance->isConstant())
        pInstance->executeDestructor();
    delete pInstance;
}

void ADestructorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void ADestructorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool ADestructorCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes)
{
    assert(pOutputVariables != NULL);
    assert((*pOutputVariables)[0] != NULL);
    assert(_pThisVariable == NULL);
    _pThisVariable = (*pOutputVariables)[0];

    bool res = Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, false);

    assert(_pThisVariable->getDestructorCRR() == NULL);
    _pThisVariable->setDestructorCRR(this);

    return expandVarsScopes ? expandAllVarsScopesTillVisible() : res;
}

bool ADestructorCallCCR::bindVariables(AVariableCCR& rThis, bool expandVarScope)
{
    Variables_t* pOutputVariables = new Variables_t(1);
    (*pOutputVariables)[0] = &rThis;
    return bindVariablesGeneric(pOutputVariables, NULL, expandVarScope);
}

#endif

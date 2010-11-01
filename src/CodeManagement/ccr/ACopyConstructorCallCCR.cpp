#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/ACopyConstructorCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"
#include "exec/AVariableInstance.hpp"
#include "exec/ASourceInstanceCaster.hpp"

using namespace CodeManagement;

ACopyConstructorCallCCR::ACopyConstructorCallCCR(const DebugInfo& rDebugInfo, const ASourceInstanceCaster* pToCopySrcInstCaster) :
    AConstructorCallCCR(rDebugInfo), _pToCopyVariable(NULL),
    _pToCopySrcInstCaster(pToCopySrcInstCaster != NULL ? pToCopySrcInstCaster->createNewCopy() : NULL)
{
}

ACopyConstructorCallCCR::~ACopyConstructorCallCCR()
{
    if (_pToCopySrcInstCaster != NULL)
        delete _pToCopySrcInstCaster;
}

void ACopyConstructorCallCCR::execute(InstancesTable_t& rInstancesTable, void* /*pRetSrcInstCopy*/) const
{
    const AVariableCCR& rThisVar = getThisVariable();
    const AVariableCCR& rToCopy = getToCopyVariable();

    AVariableInstance* pInstance = rThisVar.createNewInstance();
    assert(pInstance != NULL);
    rInstancesTable.addNewVariable(rThisVar.getVariableId(), *pInstance);
    const AVariableInstance* pToCopy = rInstancesTable.getVariable(rToCopy.getVariableId());
    assert(pToCopy != NULL);
    pInstance->executeCopyConstructor(pToCopy->getConstSourceInstance(), _pToCopySrcInstCaster);
}

void ACopyConstructorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void ACopyConstructorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool ACopyConstructorCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes)
{
    assert(pInputVariables != NULL);
    assert((*pInputVariables)[0] != NULL);
    assert(_pToCopyVariable == NULL);
    _pToCopyVariable = (*pInputVariables)[0];

    return Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, expandVarsScopes);
}

bool ACopyConstructorCallCCR::bindVariables(AVariableCCR& rThis, AVariableCCR& rToCopy, bool expandVarsScopes)
{
    return bindVariablesGeneric(new Variables_t(1, &rThis), new Variables_t(1, &rToCopy), expandVarsScopes);
}

const AVariableCCR& ACopyConstructorCallCCR::getToCopyVariable() const
{
    assert(_pToCopyVariable != NULL);
    return *_pToCopyVariable;
}

const ASourceInstanceCaster* ACopyConstructorCallCCR::getToCopySrcInstCaster() const
{
    return _pToCopySrcInstCaster;
}

#endif

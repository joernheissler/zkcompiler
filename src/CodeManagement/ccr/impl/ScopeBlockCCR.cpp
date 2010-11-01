#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/impl/ScopeBlockCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AExecutableCCR.hpp"
#include "ccr/impl/ProgramCCR.hpp"

using namespace CodeManagement;

ScopeBlockCCR::ScopeBlockCCR(const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _pFirstInScopeCCR(NULL), _pLastInScopeCCR(NULL)
{
}

ScopeBlockCCR::~ScopeBlockCCR()
{
    const AExecutableCCR* pNext = _pFirstInScopeCCR;
    while (pNext != NULL)
    {
        const AExecutableCCR* pNextNext = pNext->getNextCCR();
        delete pNext;
        pNext = pNextNext;
    }

    std::vector<AVariableCCR*> vars;
    vars.reserve(_variablesTable.getVariablesNumber());
    _variablesTable.getAllVariables(vars);

    for (std::vector<AVariableCCR*>::iterator iter = vars.begin(); iter != vars.end(); ++iter)
    {
        assert(*iter != NULL);
        removeVariable(**iter);
        delete *iter;
    }
}

void ScopeBlockCCR::execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy) const
{
    for (const AExecutableCCR* pNext = getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
    {
        pNext->execute(rInstancesTable, pRetSrcInstCopy);
    }
}

void ScopeBlockCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void ScopeBlockCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

void ScopeBlockCCR::insertFirstInScopeCCR(AExecutableCCR& rCCR)
{
    assert(rCCR.isBulk());
    if (_pFirstInScopeCCR == NULL)
    {
        assert(_pLastInScopeCCR == NULL);
        rCCR._pParentScopeBlockCCR = this;
        _pLastInScopeCCR = &rCCR;
    }
    else
        _pFirstInScopeCCR->insertPrevCCR(rCCR);
    _pFirstInScopeCCR = &rCCR;
    assert(_pFirstInScopeCCR->_pParentScopeBlockCCR == this);
}

void ScopeBlockCCR::insertLastInScopeCCR(AExecutableCCR& rCCR)
{
    assert(rCCR.isBulk());
    if (_pLastInScopeCCR == NULL)
    {
        assert(_pFirstInScopeCCR == NULL);
        rCCR._pParentScopeBlockCCR = this;
        _pFirstInScopeCCR = &rCCR;
    }
    else
        _pLastInScopeCCR->insertNextCCR(rCCR);
    _pLastInScopeCCR = &rCCR;
    assert(_pLastInScopeCCR->_pParentScopeBlockCCR == this);
}

const AExecutableCCR* ScopeBlockCCR::getFirstCallCCR() const
{
    return _pFirstInScopeCCR;
}

const AExecutableCCR* ScopeBlockCCR::getLastCallCCR() const
{
    return _pLastInScopeCCR;
}

bool ScopeBlockCCR::isVariableVisible(const AVariableCCR& rVariable) const
{
    if (_variablesTable.getVariable(rVariable.getVariableId()) != NULL)
        return true;

    if (_pParentScopeBlockCCR == NULL)
        return false;

    return _pParentScopeBlockCCR->isVariableVisible(rVariable);
}

size_t ScopeBlockCCR::getOwnVarsNumber() const
{
    return _variablesTable.getVariablesNumber();
}

const ProgramCCR* ScopeBlockCCR::getProgram(const std::string& rIdentifier) const
{
    // TODO: implement more efficiently... for our purposes this solution is the most uncomplicated...

    const ProgramCCR* pProgram = NULL;
    for (const AExecutableCCR* pNext = getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
    {
        pProgram = dynamic_cast<const ProgramCCR*>(pNext);
        if (pProgram != NULL && pProgram->getIdentifier() == rIdentifier)
            break;
        else
            pProgram = NULL;
    }

    return pProgram;
}

void ScopeBlockCCR::addVariable(AVariableCCR& rVariable)
{
    if (rVariable.getParentScopeBlockCCR() != NULL)
    {
        assert(rVariable.getParentScopeBlockCCR()->isVariableVisible(rVariable));
        rVariable.getParentScopeBlockCCR()->removeVariable(rVariable);
    }
    assert(rVariable.getParentScopeBlockCCR() == NULL);

    _variablesTable.addNewVariable(rVariable.getVariableId(), rVariable);
    rVariable.setParentScopeBlockCCR(this);

    assert(isVariableVisible(rVariable));
}

void ScopeBlockCCR::removeVariable(AVariableCCR& rVariable)
{
    assert(rVariable.getParentScopeBlockCCR() == this);
    assert(isVariableVisible(rVariable));

    rVariable.setParentScopeBlockCCR(NULL);
    _variablesTable.removeVariable(rVariable.getVariableId(), false);
}

#endif

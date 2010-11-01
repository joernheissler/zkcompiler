#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/impl/IfBranchCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AConstructorCallCCR.hpp"
#include "ccr/ACopyAssignmentCallCCR.hpp"
#include "ccr/ACopyConstructorCallCCR.hpp"
#include "ccr/ADestructorCallCCR.hpp"
#include "exec/AVariableInstance.hpp"
#include "misc/debug/impl/Exception.hpp"

using namespace CodeManagement;

IfBranchCallCCR::IfBranchCallCCR(const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _pConditionVar(NULL),
    _pPreConditionBlock(NULL), _pPostConditionBlock(NULL), _pTrueBlock(NULL), _pFalseBlock(NULL)
{
}

IfBranchCallCCR::~IfBranchCallCCR()
{
}

void IfBranchCallCCR::execute(InstancesTable_t& rInstancesTable, void* /*pRetSrcInstCopy*/) const
{
    // Execute the initialization of the condition variable.
    getPreConditionBlock().execute(rInstancesTable, NULL);

    // Evaluate the condition variable.
    AVariableInstance* condVarInst = rInstancesTable.getVariable(getConditionVariable().getVariableId());
    if (condVarInst == NULL)
        throw CM_CREATE_EXCEPTION("The condition variable of the if-brach has no instance at execution!");
    bool executeTrueBlock = condVarInst->getSourceInstanceBool();

    // Execute the freeing of the condition variable.
    getPostConditionBlock().execute(rInstancesTable, NULL);

    // Choose the branch and execute it.
    if (executeTrueBlock)
        getTrueBlock().execute(rInstancesTable, NULL);
    else if (getFalseBlock() != NULL)
        getFalseBlock()->execute(rInstancesTable, NULL);
}

void IfBranchCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void IfBranchCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool IfBranchCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes)
{
    assert(pOutputVariables == NULL);
    assert(pInputVariables != NULL);
    assert((*pInputVariables)[0] != NULL);
    assert(_pConditionVar == NULL);
    _pConditionVar = (*pInputVariables)[0];

    return Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, expandVarsScopes);
}

bool IfBranchCallCCR::bindConditionVariable(AVariableCCR& rCondVar, bool expandVarScope)
{
    Variables_t* pInputVariables = new Variables_t(1);
    (*pInputVariables)[0] = &rCondVar;
    return bindVariablesGeneric(NULL, pInputVariables, expandVarScope);
}

const AVariableCCR& IfBranchCallCCR::getConditionVariable() const
{
    getPreConditionBlock();     // Check integrity.
    getPostConditionBlock();    // Check integrity.

    assert(_pConditionVar != NULL);
    return *_pConditionVar;
}

void IfBranchCallCCR::bindPreConditionBlock(ScopeBlockCCR& rScopeBlock)
{
    // Binding of blocks has to be called in a determinate order: pre, post, true, false.
    assert(_pPreConditionBlock == NULL);
    assert(_pPostConditionBlock == NULL);
    assert(_pTrueBlock == NULL);
    assert(_pFalseBlock == NULL);
    assert(_pConditionVar == NULL);
    _pPreConditionBlock = &rScopeBlock;
    insertLastInScopeCCR(*_pPreConditionBlock);
}

void IfBranchCallCCR::bindPostConditionBlock(ScopeBlockCCR& rScopeBlock)
{
    // Binding of blocks has to be called in a determinate order: pre, post, true, false.
    assert(_pPreConditionBlock != NULL);
    assert(_pPostConditionBlock == NULL);
    assert(_pTrueBlock == NULL);
    assert(_pFalseBlock == NULL);
    assert(_pConditionVar != NULL);
    _pPostConditionBlock = &rScopeBlock;
    insertLastInScopeCCR(*_pPostConditionBlock);

    // The very last instruction of the pre-block has always to be the constructor of the conditional
    // variable. At time of binding the post-block, the pre-block has to be completed, so we check now the integrity.
    assert(_pPreConditionBlock->getLastCallCCR() != NULL);
    assert(_pPreConditionBlock->getLastCallCCR() == _pConditionVar->getConstructorCRR());
}

void IfBranchCallCCR::bindTrueBlock(ScopeBlockCCR& rScopeBlock)
{
    // Binding of blocks has to be called in a determinate order: pre, post, true, false.
    assert(_pPreConditionBlock != NULL);
    assert(_pPostConditionBlock != NULL);
    assert(_pTrueBlock == NULL);
    assert(_pFalseBlock == NULL);
    assert(_pConditionVar != NULL);
    _pTrueBlock = &rScopeBlock;
    insertLastInScopeCCR(*_pTrueBlock);

    // The very first instruction of the post-block has always to be the destructor of the conditional
    // variable. At time of binding the true-block, the post-block has to be completed, so we check now the integrity.
    assert(_pPostConditionBlock->getFirstCallCCR() != NULL);
    assert(_pPostConditionBlock->getFirstCallCCR() == _pConditionVar->getDestructorCRR());
}

void IfBranchCallCCR::bindFalseBlock(ScopeBlockCCR& rScopeBlock)
{
    // Binding of blocks has to be called in a determinate order: pre, post, true, false.
    assert(_pPreConditionBlock != NULL);
    assert(_pPostConditionBlock != NULL);
    assert(_pTrueBlock != NULL);
    assert(_pFalseBlock == NULL);
    assert(_pConditionVar != NULL);
    _pFalseBlock = &rScopeBlock;
    insertLastInScopeCCR(*_pFalseBlock);
}

const ScopeBlockCCR& IfBranchCallCCR::getPreConditionBlock() const
{
    if (_pPreConditionBlock == NULL || _pConditionVar == NULL ||
        _pPreConditionBlock->getLastCallCCR() == NULL ||
        _pPreConditionBlock->getLastCallCCR() != _pConditionVar->getConstructorCRR())
        throw CM_CREATE_EXCEPTION("Invalid pre-condition-block! "
            "The very last instruction of the pre-condition-block of the if-branch has always to be the constructor of the condition variable.");
    return *_pPreConditionBlock;
}

const ScopeBlockCCR& IfBranchCallCCR::getPostConditionBlock() const
{
    if (_pPostConditionBlock == NULL || _pConditionVar == NULL ||
        _pPostConditionBlock->getFirstCallCCR() == NULL ||
        _pPostConditionBlock->getFirstCallCCR() != _pConditionVar->getDestructorCRR())
        throw CM_CREATE_EXCEPTION("Invalid post-condition-block! "
            "The very first instruction of the post-condition-block of the if-branch has always to be the destructor of the condition variable.");
    return *_pPostConditionBlock;
}

const ScopeBlockCCR& IfBranchCallCCR::getTrueBlock() const
{
    assert(_pTrueBlock != NULL);
    return *_pTrueBlock;
}

const ScopeBlockCCR* IfBranchCallCCR::getFalseBlock() const
{
    return _pFalseBlock;
}

#endif

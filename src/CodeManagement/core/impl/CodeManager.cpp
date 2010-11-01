#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "core/impl/CodeManager.hpp"

#include <algorithm>
#include <cassert>
#include "exec/AVariableInstance.hpp"
#include "ccr/impl/ProgramCCR.hpp"
#include "ccw/AVariable.hpp"
#include "core/impl/CodeCollector.hpp"
#include "misc/debug/impl/Exception.hpp"
#
using namespace CodeManagement;

bool CodeManager::_inited = false;

CodeManager::CodeManager() :
    _pGlobalCodeCollector(new CodeCollector("CodeManager")),
    _pLastExecutedGlobalCCR(NULL)
{
    assert(!_inited);
    addCodeCollector(*_pGlobalCodeCollector);
    _pGlobalCodeCollector->beginSubProgram("global code");
    _inited = true;
}

CodeManager::~CodeManager()
{
    assert(_pGlobalCodeCollector != NULL);
    _pGlobalCodeCollector->endSubProgram("global code");
    delete _pGlobalCodeCollector;
    assert(_codeCollectors.empty());

    if (!_ifBranchInfoStack.empty())
        throw CM_CREATE_EXCEPTION("There are not properly closed if-branches in code!");
}

void CodeManager::addCodeCollector(CodeCollector& rCodeCollector)
{
    _codeCollectors.push_back(&rCodeCollector);
}

void CodeManager::removeCodeCollector(CodeCollector& rCodeCollector)
{
    CodeCollectorsIter_t iter = std::find(_codeCollectors.begin(), _codeCollectors.end(), &rCodeCollector);
    assert(iter != _codeCollectors.end());
    _codeCollectors.erase(iter);
}

bool CodeManager::isInExecutingCodeRegion()
{
    if (_ifBranchInfoStack.empty())
        // No open if branches.
        return true;

    IfBranchInfo curIfBranch = _ifBranchInfoStack.top();
    if ((curIfBranch._conditionResult == ibcr_true && curIfBranch._inBlock == true) ||
        (curIfBranch._conditionResult == ibcr_false && curIfBranch._inBlock == false))
        // We are in the right-if-branch-block.
        return true;

    // We are in the wrong if-branch-block.
    return false;
}

const void* CodeManager::getVariableSourceInstance(const AVariable& rVariable) const
{
    assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());
    const AVariableInstance* pInstance = _globalVariablesTable.getVariable(rVariable.getVariableId());
    if (pInstance != NULL)
        return pInstance->getConstSourceInstance();
    return NULL;
}

void CodeManager::executeLastGlobalAtomicCCR(void* pRetSrcInstCopy)
{
    if (isInExecutingCodeRegion())
    {   // Execute code.
        assert(_pLastExecutedGlobalCCR != _pGlobalCodeCollector->getLastInsertedAtomicCCR());
        _pLastExecutedGlobalCCR = _pGlobalCodeCollector->getLastInsertedAtomicCCR();
        assert(_pLastExecutedGlobalCCR != NULL);
        _pLastExecutedGlobalCCR->execute(_globalVariablesTable, pRetSrcInstCopy);
    }
    else
    {   // Ignore code.
        if (pRetSrcInstCopy != NULL)
        {
            DebugInfo debugInfo = _pLastExecutedGlobalCCR != NULL ?
                debugInfo = _pLastExecutedGlobalCCR->getDebugInfo() : CM_CREATE_DEBUG_INFO("unknown instruction call");
            throw CM_CREATE_EXCEPTION("Tried to access a not existing instance of a function call result! "
                "Maybe you are in a not executed if-branch. Use CM_ON_EXECUTION to check it! [" + debugInfo.toString() + "]");
        }
        _pLastExecutedGlobalCCR = _pGlobalCodeCollector->getLastInsertedAtomicCCR();
    }
}

void CodeManager::onCallVariableConstructor(const AVariable& rVariable)
{
    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallVariableConstructor(rVariable);
    }
    executeLastGlobalAtomicCCR();
}

void CodeManager::onCallVariableDestructor(const AVariable& rVariable)
{
    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallVariableDestructor(rVariable);
    }
    executeLastGlobalAtomicCCR();
}

void CodeManager::onCallVariableCopyConstructor(const AVariable& rVariable, const AVariable& rToCopy,
    const ASourceInstanceCaster* pToCopySrcInstCaster)
{
    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallVariableCopyConstructor(rVariable, rToCopy, pToCopySrcInstCaster);
    }
    executeLastGlobalAtomicCCR();
}

void CodeManager::onCallVariableCopyAssignment(const AVariable& rVariable, const AVariable& rRHS,
    const ASourceInstanceCaster* pRHSSrcInstCaster)
{
    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallVariableCopyAssignment(rVariable, rRHS, pRHSSrcInstCaster);
    }
    executeLastGlobalAtomicCCR();
}

void CodeManager::onCallInstruction(const AInstruction& rInstruction)
{
    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallInstruction(rInstruction);
    }
    executeLastGlobalAtomicCCR();
}

void CodeManager::onCallIfBranchBegin(bool endPrevOnNextEnd, const DebugInfo& rDebugInfo)
{
    _nextIfBranchInfoStack.push(IfBranchInfo());
    _nextIfBranchInfoStack.top()._endPrevOnEnd = endPrevOnNextEnd;

    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallIfBranchBegin(false, rDebugInfo);
    }
    assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());
}

void CodeManager::onCallIfBranchCondition(const AVariable& rCondVarTempCopy)
{
    if (isInExecutingCodeRegion())
    {   // Check the condition for the next if-branch.
        assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());
        const AVariableInstance* pCondInst = _globalVariablesTable.getVariable(rCondVarTempCopy.getVariableId());
        assert(pCondInst != NULL);
        assert(!_nextIfBranchInfoStack.empty());
        _nextIfBranchInfoStack.top()._conditionResult = pCondInst->getSourceInstanceBool() ? ibcr_true : ibcr_false;
    }
    else
    {   // Next if-branch is in another not executing if-branch-block.
        assert(!_nextIfBranchInfoStack.empty());
        _nextIfBranchInfoStack.top()._conditionResult = ibcr_nothing;
    }

    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallIfBranchCondition(rCondVarTempCopy);
    }
    assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());
}

void CodeManager::onCallIfBranchTrueBlock(const DebugInfo& rDebugInfo)
{
    // Starting from now we are in the next if-brach-true-block.
    assert(!_nextIfBranchInfoStack.empty());
    _nextIfBranchInfoStack.top()._inBlock = true;
    _ifBranchInfoStack.push(_nextIfBranchInfoStack.top());
    _nextIfBranchInfoStack.pop();

    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallIfBranchTrueBlock(rDebugInfo);
    }
    assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());
}

void CodeManager::onCallIfBranchFalseBlock(const DebugInfo& rDebugInfo)
{
    // Starting from now we are in the if-brach-false-block after a -true-block.
    if (_ifBranchInfoStack.empty() || _ifBranchInfoStack.top()._inBlock != true)
        throw CM_CREATE_EXCEPTION("There are bulk else-branches in code!");
    _ifBranchInfoStack.top()._inBlock = false;

    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onCallIfBranchFalseBlock(rDebugInfo);
    }
    assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());
}

void CodeManager::onCallIfBranchEnd(const DebugInfo& rDebugInfo)
{
    bool endPrevOnNextEnd;
    do
    {
        // Starting from now we are back out of the last if-brach-block.
        if (_ifBranchInfoStack.empty())
            throw CM_CREATE_EXCEPTION("There are not properly opened if-branches in code!");
        endPrevOnNextEnd = _ifBranchInfoStack.top()._endPrevOnEnd;
        _ifBranchInfoStack.pop();

        for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
        {
            assert(*iter != NULL);
            (*iter)->onCallIfBranchEnd(rDebugInfo);
        }
        assert(_pLastExecutedGlobalCCR == _pGlobalCodeCollector->getLastInsertedAtomicCCR());

        // Repeat calling end-if for the last else-if-branches.
    } while (endPrevOnNextEnd);
}

void CodeManager::onComment(const std::string& rText, const DebugInfo& rDebugInfo)
{
    for (CodeCollectorsIter_t iter = _codeCollectors.begin(); iter != _codeCollectors.end(); ++iter)
    {
        assert(*iter != NULL);
        (*iter)->onComment(rText, rDebugInfo);
    }
    executeLastGlobalAtomicCCR();
}

CodeManager& CodeManager::getManager()
{
    assert(isInited());
    return *_managerPtr;
}

bool CodeManager::isInited()
{
    return _inited;
}

#endif

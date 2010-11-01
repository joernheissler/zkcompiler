#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "core/impl/CodeCollector.hpp"

#include "ccr/AConstructorCallCCR.hpp"
#include "ccr/ACopyAssignmentCallCCR.hpp"
#include "ccr/ACopyConstructorCallCCR.hpp"
#include "ccr/ADestructorCallCCR.hpp"
#include "ccr/AInstructionCallCCR.hpp"
#include "ccr/AVariableCCR.hpp"
#include "ccr/impl/IfBranchCallCCR.hpp"
#include "ccr/impl/ProgramCCR.hpp"
#include "ccr/impl/CommentCCR.hpp"
#include "ccw/AInstruction.hpp"
#include "ccw/AVariable.hpp"
#include "core/impl/CodeManager.hpp"
#include "exec/AVariableInstance.hpp"
#include "misc/debug/impl/Exception.hpp"
#include "misc/stream/impl/Logger.hpp"

using namespace CodeManagement;

CodeCollector::CodeCollector(const std::string& rIdentifier) :
    _pProgram(new ProgramCCR(rIdentifier, CM_CREATE_DEBUG_INFO(rIdentifier + ": global program"))),
    _pLastInsertedAtomicCCR(NULL)
{
    setDestroyProgramOnDestruction();
    _scopeBlockStack.push(_pProgram);
    _programStack.push(_pProgram);

    if (CodeManager::isInited())
        CodeManager::getManager().addCodeCollector(*this);
}

CodeCollector::~CodeCollector()
{
    CodeManager::getManager().removeCodeCollector(*this);
    assert(_pProgram != NULL);

    if (isCollecting())
        throwException("Destroying CodeCollector while collecting code!");

    // All variables of _variablesTable are owned by _pProgram.
    _variablesTable.clear(false);

    if (_destroyProgramOnDestruction)
        delete _pProgram;
}

bool CodeCollector::isCollecting() const
{
    assert(_scopeBlockStack.size() > 2 || dynamic_cast<ProgramCCR*>(_scopeBlockStack.top()) != NULL);
    return _scopeBlockStack.size() > 1; // One element is always the global program.
}

ProgramCCR& CodeCollector::getProgram()
{
    // TODO: check for integrity (begin/end)...
    assert(_pProgram != NULL);
    return *_pProgram;
}

ProgramCCR& CodeCollector::beginSubProgram(const std::string& rIdentifier)
{
    assert(_pProgram != NULL);
    assert(!_programStack.empty());
    assert(_programStack.top() != NULL);
    assert(!_scopeBlockStack.empty());
    assert(_scopeBlockStack.top() != NULL);

    ProgramCCR* pNewSubProgram = new ProgramCCR(rIdentifier, CM_CREATE_DEBUG_INFO(rIdentifier + ": sub program"));
    _scopeBlockStack.top()->insertLastInScopeCCR(*pNewSubProgram);
    _scopeBlockStack.push(pNewSubProgram);
    _programStack.push(pNewSubProgram);

    return *pNewSubProgram;
}

ProgramCCR& CodeCollector::endSubProgram(const std::string& rIdentifier)
{
    assert(_pProgram != NULL);
    assert(!_programStack.empty());
    assert(_programStack.top() != NULL);
    assert(!_scopeBlockStack.empty());
    ProgramCCR* pSubProgram = dynamic_cast<ProgramCCR*>(_scopeBlockStack.top());
    if (pSubProgram == NULL)
        throwException("There are not properly closed if-branches in collected code!");
    assert(pSubProgram == _programStack.top());

    if (rIdentifier != pSubProgram->getIdentifier())
        throw CM_CREATE_EXCEPTION("Identifiers mismatch of beginSubProgram()/endSubProgram() calls pair!");

    _programStack.pop();
    _scopeBlockStack.pop();

    if (_scopeBlockStack.empty())
        throw CM_CREATE_EXCEPTION("ScopeBlocks stackunderflow!");
    assert(!_programStack.empty());

    return *pSubProgram;
}

void CodeCollector::addOutputVariable(AVariable& rVariable, const std::string& rIdentifier)
{
    assert(!_programStack.empty());
    assert(_programStack.top() != NULL);

    // TODO: check weather already added, and for no constructor/destructor calls!
    AVariableCCR* pVarRep = rVariable.createNewCCR();
    assert(pVarRep != NULL);

    pVarRep->setVariableIdentifier(rIdentifier);
    _variablesTable.addNewVariable(pVarRep->getVariableId(), *pVarRep);
    _programStack.top()->getOutputVariables().push_back(pVarRep);
}

void CodeCollector::addInputVariable(AVariable& rVariable, const std::string& rIdentifier)
{
    assert(!_programStack.empty());
    assert(_programStack.top() != NULL);

    // TODO: check weather already added, and for no constructor/destructor calls!
    AVariableCCR* pVarRep = rVariable.createNewCCR();
    assert(pVarRep != NULL);

    pVarRep->setVariableIdentifier(rIdentifier);
    _variablesTable.addNewVariable(pVarRep->getVariableId(), *pVarRep);
    _programStack.top()->getInputVariables().push_back(pVarRep);
}

const AExecutableCCR* CodeCollector::getLastInsertedAtomicCCR() const
{
    return _pLastInsertedAtomicCCR;
}

void CodeCollector::onCallVariableConstructor(const AVariable& rVariable)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: Var-Construct [id" << rVariable.getVariableId() << "]: " << rVariable.getDebugInfo().getMessage() << "\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    AVariableCCR* pVarRep = rVariable.createNewCCR();
    _variablesTable.addNewVariable(pVarRep->getVariableId(), *pVarRep);
    assert(pVarRep != NULL);

    AConstructorCallCCR* pCCR = pVarRep->createNewConstructorCallCCR(CM_CREATE_DEBUG_INFO(
        "construct [" + rVariable.getDebugInfo().toString() + "]"));
    pScopeBlock->insertLastInScopeCCR(*pCCR);
    if (!pCCR->bindVariables(*pVarRep, true))
        checkVarsScopesExpanding(*pCCR);

    _pLastInsertedAtomicCCR = pCCR;
}

void CodeCollector::onCallVariableDestructor(const AVariable& rVariable)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: Var-Destruct [id" << rVariable.getVariableId() << "]\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    AVariableCCR* pVarRep = _variablesTable.getVariable(rVariable.getVariableId());
    assert(pVarRep != NULL);

    ADestructorCallCCR* pCCR = pVarRep->createNewDestructorCallCCR(CM_CREATE_DEBUG_INFO(
        "destruct [" + rVariable.getDebugInfo().toString() + "]"));
    pScopeBlock->insertLastInScopeCCR(*pCCR);
    if (!pCCR->bindVariables(*pVarRep, true))
        checkVarsScopesExpanding(*pCCR);
    // TODO: Check weather constructor was called.

    _pLastInsertedAtomicCCR = pCCR;
}

void CodeCollector::onCallVariableCopyConstructor(const AVariable& rVariable, const AVariable& rToCopy,
    const ASourceInstanceCaster* pToCopySrcInstCaster)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: Var-Copy-Contruct [id" << rVariable.getVariableId() << " = id" << rToCopy.getVariableId() << "]\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    AVariableCCR* pVarRep = rVariable.createNewCCR();
    _variablesTable.addNewVariable(pVarRep->getVariableId(), *pVarRep);
    assert(pVarRep != NULL);

    AVariableCCR* pVarRepToCopy = _variablesTable.getVariable(rToCopy.getVariableId());
    assert(pVarRepToCopy != NULL);

    ACopyConstructorCallCCR* pCCR = pVarRep->createNewCopyConstructorCallCCR(CM_CREATE_DEBUG_INFO("copy-construct [" +
        rVariable.getDebugInfo().toString() + "] = [" + rToCopy.getDebugInfo().toString() + "]"), pToCopySrcInstCaster);
    pScopeBlock->insertLastInScopeCCR(*pCCR);
    if (!pCCR->bindVariables(*pVarRep, *pVarRepToCopy, true))
        checkVarsScopesExpanding(*pCCR);

    _pLastInsertedAtomicCCR = pCCR;
}

void CodeCollector::onCallVariableCopyAssignment(const AVariable& rVariable, const AVariable& rRHS,
    const ASourceInstanceCaster* pRHSSrcInstCaster)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: Var-Copy-Assign [id" << rVariable.getVariableId() << " = id" << rRHS.getVariableId() << "]\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    AVariableCCR* pVarRep = _variablesTable.getVariable(rVariable.getVariableId());
    assert(pVarRep != NULL);

    AVariableCCR* pVarRepRHS = _variablesTable.getVariable(rRHS.getVariableId());
    assert(pVarRepRHS != NULL);

    ACopyAssignmentCallCCR* pCCR = pVarRep->createNewCopyAssignmentCallCCR(CM_CREATE_DEBUG_INFO("copy-assign [" +
        rVariable.getDebugInfo().toString() + "] = [" + rRHS.getDebugInfo().toString() + "]"), pRHSSrcInstCaster);
    pScopeBlock->insertLastInScopeCCR(*pCCR);
    if (!pCCR->bindVariables(*pVarRep, *pVarRepRHS, true))
        checkVarsScopesExpanding(*pCCR);

    _pLastInsertedAtomicCCR = pCCR;
}

void CodeCollector::onCallInstruction(const AInstruction& rInstruction)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: Instruction-Call out[";
//    for (std::vector<AVariable*>::const_iterator iter = rInstruction.getOutputVariables().begin();
//        iter != rInstruction.getOutputVariables().end(); ++iter)
//    {
//        if (iter != rInstruction.getOutputVariables().begin())
//            Logger::log << ",";
//        Logger::log << "id" << (*iter)->getVariableId();
//    }
//    Logger::log << "] in[";
//    for (std::vector<const AVariable*>::const_iterator iter = rInstruction.getInputVariables().begin();
//        iter != rInstruction.getInputVariables().end(); ++iter)
//    {
//        if (iter != rInstruction.getInputVariables().begin())
//            Logger::log << ",";
//        Logger::log << "id" << (*iter)->getVariableId();
//    }
//    Logger::log << "]: " << rInstruction.getDebugInfo().getMessage() << "\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    AInstructionCallCCR::Variables_t* pOutputVariables = new AInstructionCallCCR::Variables_t();
    _variablesTable.getVariables(*pOutputVariables,
        rInstruction.getOutputVariables().begin(), rInstruction.getOutputVariables().end());

    AInstructionCallCCR::Variables_t* pInputVariables = new AInstructionCallCCR::Variables_t();

    _variablesTable.getVariables(*pInputVariables,
        rInstruction.getInputVariables().begin(), rInstruction.getInputVariables().end());

    AInstructionCallCCR* pCCR = rInstruction.createNewCCR(rInstruction.getDebugInfo());
    assert(pCCR != NULL);

    pScopeBlock->insertLastInScopeCCR(*pCCR);
    if (!pCCR->bindVariablesGeneric(pOutputVariables, pInputVariables, true))
        checkVarsScopesExpanding(*pCCR);

    _pLastInsertedAtomicCCR = pCCR;
}

void CodeCollector::onCallIfBranchBegin(bool endPrevOnNextEnd, const DebugInfo& rDebugInfo)
{
    // endPrevOnNextEnd has to be managed by CodeManager!
    (void)endPrevOnNextEnd;
    assert(!endPrevOnNextEnd);

    if (!isCollecting())
        return;

//    Logger::log << "CM: if-branch-begin [" + rDebugInfo.toString() + "]\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    IfBranchCallCCR* pIfBranchCall = new IfBranchCallCCR(rDebugInfo);
    pScopeBlock->insertLastInScopeCCR(*pIfBranchCall);
    _scopeBlockStack.push(pIfBranchCall);

    ScopeBlockCCR* pPreBlock =
        new ScopeBlockCCR(CM_CREATE_DEBUG_INFO("if-branch-pre-cond-block of [" + rDebugInfo.toString() + "]"));
    pIfBranchCall->bindPreConditionBlock(*pPreBlock);
    // From now on collect code to the pre-cond-block.
    _scopeBlockStack.push(pPreBlock);

    // Don't change _pLastInsertedAtomicCCR, because if-branch is not atomic!
}

void CodeCollector::onCallIfBranchCondition(const AVariable& rCondVarTempCopy)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: if-branch-condition [" << rCondVarTempCopy.getDebugInfo() << "]\n";

    assert(!_scopeBlockStack.empty());
    _scopeBlockStack.pop(); // Remove the pre-cond-block from stack.

    assert(!_scopeBlockStack.empty());
    IfBranchCallCCR* pIfBranchCall = dynamic_cast<IfBranchCallCCR*>(_scopeBlockStack.top());
    if (pIfBranchCall == NULL)
        throwException("Corrupted if-branch!");

    AVariableCCR* pCondVar = _variablesTable.getVariable(rCondVarTempCopy.getVariableId());
    assert(pCondVar != NULL);

    if (!pIfBranchCall->bindConditionVariable(*pCondVar, true))
        checkVarsScopesExpanding(*pIfBranchCall);

    ScopeBlockCCR* pPostBlock =
        new ScopeBlockCCR(CM_CREATE_DEBUG_INFO("if-branch-post-cond-block of [" + pIfBranchCall->getDebugInfo().toString() + "]"));
    pIfBranchCall->bindPostConditionBlock(*pPostBlock);
    // From now on collect code to the post-cond-block.
    _scopeBlockStack.push(pPostBlock);
    // Next instructions there are mainly destructor calls of temporally variables from the conditional
    // expression. But also other instructions can be called here, i.e. from destructors of higher classes!!!
    // But the very first instruction is always the destructor of the conditional variable.

    // Don't change _pLastInsertedAtomicCCR, because if-branch is not atomic!
}

void CodeCollector::onCallIfBranchTrueBlock(const DebugInfo& rDebugInfo)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: if-branch-true-block [" + rDebugInfo.toString() + "]\n";

    assert(!_scopeBlockStack.empty());
    _scopeBlockStack.pop(); // Remove the post-cond-block from stack.

    assert(!_scopeBlockStack.empty());
    IfBranchCallCCR* pIfBranchCall = dynamic_cast<IfBranchCallCCR*>(_scopeBlockStack.top());
    if (pIfBranchCall == NULL)
        throwException("Corrupted if-branch!");

    ScopeBlockCCR* pTrueBlock = new ScopeBlockCCR(rDebugInfo);
    pIfBranchCall->bindTrueBlock(*pTrueBlock);
    // From now on collect code to the true-block.
    _scopeBlockStack.push(pTrueBlock);

    // Don't change _pLastInsertedAtomicCCR, because if-branch is not atomic!
}

void CodeCollector::onCallIfBranchFalseBlock(const DebugInfo& rDebugInfo)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: if-branch-false-block [" + rDebugInfo.toString() + "]\n";

    assert(!_scopeBlockStack.empty());
    _scopeBlockStack.pop(); // Remove the true-block from stack.

    assert(!_scopeBlockStack.empty());
    IfBranchCallCCR* pIfBranchCall = dynamic_cast<IfBranchCallCCR*>(_scopeBlockStack.top());
    if (pIfBranchCall == NULL)
        throwException("Corrupted if-branch!");

    ScopeBlockCCR* pFalseBlock = new ScopeBlockCCR(rDebugInfo);
    pIfBranchCall->bindFalseBlock(*pFalseBlock);
    // From now on collect code to the false-block.
    _scopeBlockStack.push(pFalseBlock);

    // Don't change _pLastInsertedAtomicCCR, because if-branch is not atomic!
}

void CodeCollector::onCallIfBranchEnd(const DebugInfo& rDebugInfo)
{
    if (!isCollecting())
        return;

    (void)rDebugInfo;
//    Logger::log << "CM: if-branch-end [" + rDebugInfo.toString() + "]\n";

    assert(!_scopeBlockStack.empty());
    _scopeBlockStack.pop(); // Remove the true/false-block from stack.

    assert(!_scopeBlockStack.empty());
    IfBranchCallCCR* pIfBranchCall = dynamic_cast<IfBranchCallCCR*>(_scopeBlockStack.top());
    if (pIfBranchCall == NULL)
        throwException("Corrupted if-branch!");

    _scopeBlockStack.pop(); // Remove the if-branch-call from stack.

    // Don't change _pLastInsertedAtomicCCR, because if-branch is not atomic!
}

void CodeCollector::onComment(const std::string& rText, const DebugInfo& rDebugInfo)
{
    if (!isCollecting())
        return;

//    Logger::log << "CM: comment [" << rText << "]\n";

    assert(!_scopeBlockStack.empty());
    ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
    assert(pScopeBlock != NULL);

    CommentCCR* pCCR = new CommentCCR(rText, rDebugInfo);
    pScopeBlock->insertLastInScopeCCR(*pCCR);

    _pLastInsertedAtomicCCR = pCCR;
}

void CodeCollector::throwException(std::string msg)
{
    assert(!_scopeBlockStack.empty());
    msg += "\n_scopeBlockStack = [";

    do
    {
        ScopeBlockCCR* pScopeBlock = _scopeBlockStack.top();
        assert(pScopeBlock != NULL);
        msg += "\n  [" + pScopeBlock->getDebugInfo().toString() + "]";
        _scopeBlockStack.pop();
    }
    while (!_scopeBlockStack.empty());

    msg += " ]";

    throw CM_CREATE_EXCEPTION(msg);
}

void CodeCollector::checkVarsScopesExpanding(AExecutableCCR& rCCR) const
{
    // TODO: exception...
    assert(false);
    (void)rCCR;
}

#endif

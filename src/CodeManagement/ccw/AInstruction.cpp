#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccw/AInstruction.hpp"

#include <cassert>
#include "ccr/AInstructionCallCCR.hpp"

using namespace CodeManagement;

AInstruction::AInstruction(size_t outputVariables, size_t inputVariables) :
    _outputVariables(outputVariables), _inputVariables(inputVariables),
    _debugInfo(CM_CREATE_DEBUG_INFO("unknown instruction"))
{
}

AInstruction::~AInstruction()
{
}

const std::vector<AVariable*>& AInstruction::getOutputVariables() const
{
    return _outputVariables;
}

const std::vector<const AVariable*>& AInstruction::getInputVariables() const
{
    return _inputVariables;
}

const DebugInfo& AInstruction::getDebugInfo() const
{
    return _debugInfo;
}

void AInstruction::bindOutputVariable(size_t index, AVariable& rVariable)
{
    assert(index < _outputVariables.size());
    assert(_outputVariables[index] == NULL);
    _outputVariables[index] = &rVariable;
}

void AInstruction::bindInputVariable(size_t index, const AVariable& rVariable)
{
    assert(index < _inputVariables.size());
    assert(_inputVariables[index] == NULL);
    _inputVariables[index] = &rVariable;
}

void AInstruction::setDebugInfo(const DebugInfo& rDebugInfo)
{
    _debugInfo = rDebugInfo;
}

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccw/AFunction.hpp"

#include <cassert>
#include "core/impl/CodeManager.hpp"

using namespace CodeManagement;

AFunction::AFunction(size_t outputVariables, size_t inputVariables) :
    AInstruction(outputVariables, inputVariables), _hasReturnVariable(false), _pReturnSrcInstCaster(NULL)
{
    setDebugInfo(CM_CREATE_DEBUG_INFO("unknown function"));
}

bool AFunction::hasReturnVariable() const
{
    return _hasReturnVariable;
}

const ASourceInstanceCaster* AFunction::getReturnSrcInstCaster() const
{
    return _pReturnSrcInstCaster;
}

void AFunction::call(AVariable* pReturnVar, const ASourceInstanceCaster* pReturnSrcInstCaster)
{
    if (pReturnVar != NULL)
    {
        _outputVariables.push_back(pReturnVar);
        _hasReturnVariable = true;
        _pReturnSrcInstCaster = pReturnSrcInstCaster;
    }
    assert(_hasReturnVariable == (pReturnVar != NULL));
    assert(_pReturnSrcInstCaster == NULL || _hasReturnVariable);
    CodeManager::getManager().onCallInstruction(*this);
}

#endif

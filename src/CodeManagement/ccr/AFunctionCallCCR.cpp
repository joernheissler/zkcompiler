#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AFunctionCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "exec/ASourceInstanceCaster.hpp"

using namespace CodeManagement;

AFunctionCallCCR::AFunctionCallCCR(ExecuteFunc_t executeFunc, const ASourceInstanceCaster* pReturnSrcInstCaster, bool hasReturnVar, const DebugInfo& rDebugInfo) :
    Base_t((Base_t::ExecuteFunc_t)executeFunc, rDebugInfo), _hasReturnVariable(hasReturnVar), _pReturnSrcInstCaster(pReturnSrcInstCaster)
{
}

AFunctionCallCCR::~AFunctionCallCCR()
{
    if (_pReturnSrcInstCaster != NULL)
        delete _pReturnSrcInstCaster;
}

void AFunctionCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AFunctionCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

size_t AFunctionCallCCR::getReturnVariableIndex() const
{
    if (_hasReturnVariable)
        return getOutputVariablesNumber() - 1;
    return getOutputVariablesNumber();
}

bool AFunctionCallCCR::hasReturnVariable() const
{
    return _hasReturnVariable;
}

const ASourceInstanceCaster* AFunctionCallCCR::getReturnSrcInstCaster() const
{
    return _pReturnSrcInstCaster;
}

#endif

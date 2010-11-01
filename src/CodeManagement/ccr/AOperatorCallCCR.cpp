#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AOperatorCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"

using namespace CodeManagement;

AOperatorCallCCR::AOperatorCallCCR(ExecuteFunc_t executeFunc, const ASourceInstanceCaster* pReturnSrcInstCaster, bool hasReturnVar,
    const DebugInfo& rDebugInfo) : Base_t((Base_t::ExecuteFunc_t)executeFunc, pReturnSrcInstCaster, hasReturnVar, rDebugInfo)
{
}

void AOperatorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AOperatorCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

#endif

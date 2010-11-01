#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AProcedureCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"

using namespace CodeManagement;

AProcedureCallCCR::AProcedureCallCCR(ExecuteFunc_t executeFunc, const DebugInfo& rDebugInfo) :
    Base_t((Base_t::ExecuteFunc_t)executeFunc, rDebugInfo)
{
}

void AProcedureCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}
void AProcedureCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

#endif

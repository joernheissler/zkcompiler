#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AVarSpecialCallCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"
#include "exec/AVariableInstance.hpp"

using namespace CodeManagement;

AVarSpecialCallCCR::AVarSpecialCallCCR(const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _pThisVariable(NULL)
{
}

void AVarSpecialCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AVarSpecialCallCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool AVarSpecialCallCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables,
    bool expandVarsScopes)
{
    assert(_pThisVariable != NULL); // Must have been set in derived class!
    return Base_t::bindVariablesGeneric(pOutputVariables, pInputVariables, expandVarsScopes);
}

const AVariableCCR& AVarSpecialCallCCR::getThisVariable() const
{
    assert(_pThisVariable != NULL);
    return *_pThisVariable;
}

#endif

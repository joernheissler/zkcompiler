#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AVariableCCR.hpp"

#include <algorithm>
#include <cassert>
#include "ccr/ACCRVisitor.hpp"
#include "ccr/AConstructorCallCCR.hpp"
#include "ccr/ACopyAssignmentCallCCR.hpp"
#include "ccr/ACopyConstructorCallCCR.hpp"
#include "ccr/ADestructorCallCCR.hpp"
#include "ccr/impl/ScopeBlockCCR.hpp"
#include "misc/stream/impl/StringStream.hpp"

using namespace CodeManagement;

AVariableCCR::AVariableCCR(variableId_t id, const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _variableId(id), _variableIdentifier(getDefaultVarIdent()), _pConstructorCRR(NULL), _pDestructorCRR(NULL)
{
}

AVariableCCR::~AVariableCCR()
{
    assert(_pConstructorCRR == NULL);   // AConstructorCallCCR takes care.
    assert(_pDestructorCRR == NULL);    // ADestructorCallCCR takes care.
    assert(_outputExecutableCallCCRs.empty());    // AExecutableCCR takes care.
    assert(_inputExecutableCallCCRs.empty());    // AExecutableCCR takes care.
}

AVariableCCR::variableId_t AVariableCCR::getVariableId() const
{
    return _variableId;
}

void AVariableCCR::setVariableIdentifier(const std::string& rIdentifier)
{
    _variableIdentifier = rIdentifier;
}

const std::string& AVariableCCR::getVariableIdentifier() const
{
    return _variableIdentifier;
}

std::string AVariableCCR::getDefaultVarIdent() const
{
    StringStream ident;
    ident << "var" << _variableId;
    return ident.toString();
}

bool AVariableCCR::isDefaultVarIdent() const
{
    return getVariableIdentifier() == getDefaultVarIdent();
}

AConstructorCallCCR* AVariableCCR::getConstructorCRR()
{
    return _pConstructorCRR;
}

const AConstructorCallCCR* AVariableCCR::getConstructorCRR() const
{
    return _pConstructorCRR;
}

ADestructorCallCCR* AVariableCCR::getDestructorCRR()
{
    return _pDestructorCRR;
}

const ADestructorCallCCR* AVariableCCR::getDestructorCRR() const
{
    return _pDestructorCRR;
}

const AVariableCCR::ExecutableCallCCRs_t& AVariableCCR::getOutputExecutableCallCCRs() const
{
    return _outputExecutableCallCCRs;
}

const AVariableCCR::ExecutableCallCCRs_t& AVariableCCR::getInputExecutableCallCCRs() const
{
    return _inputExecutableCallCCRs;
}

bool AVariableCCR::expandScopeTillVisibleIn(ScopeBlockCCR& rScope)
{
    // TODO: Can be implemented much more efficient... but there is no need for it yet :-)

    ScopeBlockCCR* pVarScope = getParentScopeBlockCCR();

    if (pVarScope == NULL)
    {   // This variable is not associated with any scope yet.
        rScope.addVariable(*this);
        assert(getParentScopeBlockCCR() == &rScope);
        return true;
    }

    ScopeBlockCCR& rOriginalScope = *pVarScope;

    while (!rScope.isVariableVisible(*this))
    {
        pVarScope = pVarScope->getParentScopeBlockCCR();
        if (pVarScope == NULL)
        {   // There is no scope connection!
            if (getParentScopeBlockCCR() != &rOriginalScope)
                rOriginalScope.addVariable(*this);
            return false;
        }
        pVarScope->addVariable(*this);
    }

    return true;
}

void AVariableCCR::setConstructorCRR(AConstructorCallCCR* pConstructor)
{
    setStructorCRR(_pConstructorCRR, pConstructor);
}

void AVariableCCR::setDestructorCRR(ADestructorCallCCR* pDestructor)
{
    setStructorCRR(_pDestructorCRR, pDestructor);
}

template<class TStructorCallCCR>
void AVariableCCR::setStructorCRR(TStructorCallCCR*& rpDst, TStructorCallCCR* pSrc)
{
    if (rpDst == NULL)
    {   // Remove structor call from the list of variable dependent calls.
        assert(pSrc != NULL);
        ExecutableCallCCRsIter_t inExecutableCallCCRs =
            std::find(_outputExecutableCallCCRs.begin(), _outputExecutableCallCCRs.end(), pSrc);
        assert(inExecutableCallCCRs != _outputExecutableCallCCRs.end());
        _outputExecutableCallCCRs.erase(inExecutableCallCCRs);
    }
    else
    {   // Add structor call back to the list of variable dependent calls.
        assert(pSrc == NULL);
        assert(std::find(_outputExecutableCallCCRs.begin(), _outputExecutableCallCCRs.end(), rpDst) == _outputExecutableCallCCRs.end());
        _outputExecutableCallCCRs.push_back(rpDst);
    }

    rpDst = pSrc;
}

AVariableCCR::ExecutableCallCCRs_t& AVariableCCR::getOutputExecutableCallCCRs()
{
    return _outputExecutableCallCCRs;
}

AVariableCCR::ExecutableCallCCRs_t& AVariableCCR::getInputExecutableCallCCRs()
{
    return _inputExecutableCallCCRs;
}

void AVariableCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AVariableCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

bool AVariableCCR::isBulk() const
{
    return getParentScopeBlockCCR() == NULL;
}

#endif

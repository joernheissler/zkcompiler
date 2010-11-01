#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/AExecutableCCR.hpp"

#include <algorithm>
#include "ccr/ACCRVisitor.hpp"
#include "ccr/AVariableCCR.hpp"
#include "ccr/impl/ScopeBlockCCR.hpp"

using namespace CodeManagement;

AExecutableCCR::AExecutableCCR(const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _pPrevCCR(NULL), _pNextCCR(NULL), _pOutputVariables(NULL), _pInputVariables(NULL)
{
}

AExecutableCCR::~AExecutableCCR()
{
    if (_pOutputVariables != NULL)
    {
        for (VariablesIter_t iter = _pOutputVariables->begin(); iter != _pOutputVariables->end(); ++iter)
        {
            assert(*iter != NULL);
            AVariableCCR& rVarRep = **iter;

            AVariableCCR::ExecutableCallCCRsIter_t thisIter =
                std::find(rVarRep.getOutputExecutableCallCCRs().begin(), rVarRep.getOutputExecutableCallCCRs().end(), this);
            assert(thisIter != rVarRep.getOutputExecutableCallCCRs().end());
            rVarRep.getOutputExecutableCallCCRs().erase(thisIter);

            // There must not be multiple references of variable dependent calls in variable CCRs!
            assert(std::find(rVarRep.getOutputExecutableCallCCRs().begin(),
                rVarRep.getOutputExecutableCallCCRs().end(), this) == rVarRep.getOutputExecutableCallCCRs().end());
        }
        delete _pOutputVariables;
    }

    if (_pInputVariables != NULL)
    {
        for (VariablesIter_t iter = _pInputVariables->begin(); iter != _pInputVariables->end(); ++iter)
        {
            assert(*iter != NULL);
            AVariableCCR& rVarRep = **iter;

            AVariableCCR::ExecutableCallCCRsIter_t thisIter =
                std::find(rVarRep.getInputExecutableCallCCRs().begin(), rVarRep.getInputExecutableCallCCRs().end(), this);
            assert(thisIter != rVarRep.getInputExecutableCallCCRs().end());
            rVarRep.getInputExecutableCallCCRs().erase(thisIter);

            // Multiple references of variable dependent calls in variable CCRs are allowed!
            // It could happen when, the same variable is passed more then once as argument to an instruction...
        }
        delete _pInputVariables;
    }

    // Needed for destructor of the base class.
    _pParentScopeBlockCCR = NULL;
}

void AExecutableCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void AExecutableCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

void AExecutableCCR::insertPrevCCR(AExecutableCCR& rCCR)
{
    assert(rCCR.isBulk());
    assert(_pParentScopeBlockCCR != NULL);
    assert(_pPrevCCR == NULL || _pPrevCCR->_pNextCCR == this);
    _pPrevCCR = &rCCR;
    _pPrevCCR->_pNextCCR = this;
    _pPrevCCR->_pParentScopeBlockCCR = _pParentScopeBlockCCR;
}

void AExecutableCCR::insertNextCCR(AExecutableCCR& rCCR)
{
    assert(rCCR.isBulk());
    assert(_pParentScopeBlockCCR != NULL);
    assert(_pNextCCR == NULL || _pNextCCR->_pPrevCCR == this);
    _pNextCCR = &rCCR;
    _pNextCCR->_pPrevCCR = this;
    _pNextCCR->_pParentScopeBlockCCR = _pParentScopeBlockCCR;
}

bool AExecutableCCR::isBulk() const
{
    return _pParentScopeBlockCCR == NULL && _pPrevCCR == NULL && _pNextCCR == NULL;
}

const AExecutableCCR* AExecutableCCR::getPrevCCR() const
{
    return _pPrevCCR;
}

AExecutableCCR* AExecutableCCR::getPrevCCR()
{
    return _pPrevCCR;
}

const AExecutableCCR* AExecutableCCR::getNextCCR() const
{
    return _pNextCCR;
}

AExecutableCCR* AExecutableCCR::getNextCCR()
{
    return _pNextCCR;
}

const ScopeBlockCCR* AExecutableCCR::getParentScopeBlockCCR() const
{
    return _pParentScopeBlockCCR;
}

ScopeBlockCCR* AExecutableCCR::getParentScopeBlockCCR()
{
    return _pParentScopeBlockCCR;
}

const AExecutableCCR* AExecutableCCR::getScopeOverallPrevCCR() const
{
    return const_cast<AExecutableCCR*>(this)->getScopeOverallPrevCCR();
}

AExecutableCCR* AExecutableCCR::getScopeOverallPrevCCR()
{
    if (getPrevCCR() != NULL)
        return getPrevCCR();

    if (getParentScopeBlockCCR() == NULL)
        return NULL;

    return getParentScopeBlockCCR()->getScopeOverallPrevCCR();
}

const AExecutableCCR* AExecutableCCR::getScopeOverallNextCCR() const
{
    return const_cast<AExecutableCCR*>(this)->getScopeOverallNextCCR();
}

AExecutableCCR* AExecutableCCR::getScopeOverallNextCCR()
{
    if (getNextCCR() != NULL)
        return getNextCCR();

    if (getParentScopeBlockCCR() == NULL)
        return NULL;

    return getParentScopeBlockCCR()->getScopeOverallNextCCR();
}

bool AExecutableCCR::expandAllVarsScopesTillVisible()
{
    assert(getParentScopeBlockCCR() != NULL);

    bool result = true;
    for (VariablesIter_t iter = _pOutputVariables->begin(); iter != _pOutputVariables->end(); ++iter)
    {
        assert(*iter != NULL);
        if (!(*iter)->expandScopeTillVisibleIn(*getParentScopeBlockCCR()))
            result = false;
    }

    for (VariablesIter_t iter = _pInputVariables->begin(); iter != _pInputVariables->end(); ++iter)
    {
        assert(*iter != NULL);
        if (!(*iter)->expandScopeTillVisibleIn(*getParentScopeBlockCCR()))
            result = false;
    }

    return result;
}

size_t AExecutableCCR::getOutputVariablesNumber() const
{
    return _pOutputVariables != NULL ? _pOutputVariables->size() : 0;
}

size_t AExecutableCCR::getInputVariablesNumber() const
{
    return _pInputVariables != NULL ? _pInputVariables->size() : 0;
}

const AVariableCCR& AExecutableCCR::getOutputVariable(size_t index) const
{
    return const_cast<AExecutableCCR*>(this)->getOutputVariable(index);
}

AVariableCCR& AExecutableCCR::getOutputVariable(size_t index)
{
    assert(_pOutputVariables != NULL);
    assert(index < _pOutputVariables->size());
    assert((*_pOutputVariables)[index] != NULL);
    return *(*_pOutputVariables)[index];
}

const AVariableCCR& AExecutableCCR::getInputVariable(size_t index) const
{
    return const_cast<AExecutableCCR*>(this)->getInputVariable(index);
}

AVariableCCR& AExecutableCCR::getInputVariable(size_t index)
{
    assert(_pInputVariables != NULL);
    assert(index < _pInputVariables->size());
    assert((*_pInputVariables)[index] != NULL);
    return *(*_pInputVariables)[index];
}

bool AExecutableCCR::isVarUsedAsOutOrInput(const AVariableCCR& rVar) const
{
    return (_pOutputVariables != NULL &&
        std::find(_pOutputVariables->begin(), _pOutputVariables->end(), &rVar) != _pOutputVariables->end()) ||
        (_pOutputVariables != NULL &&
        std::find(_pInputVariables->begin(), _pInputVariables->end(), &rVar) != _pInputVariables->end());
}

bool AExecutableCCR::bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes)
{
    assert(_pOutputVariables == NULL);
    _pOutputVariables = pOutputVariables != NULL ? pOutputVariables : new Variables_t(0);
    assert(_pInputVariables == NULL);
    _pInputVariables = pInputVariables != NULL ? pInputVariables : new Variables_t(0);

    for (VariablesIter_t iter = _pOutputVariables->begin(); iter != _pOutputVariables->end(); ++iter)
    {
        assert(*iter != NULL);
        AVariableCCR& rVarRep = **iter;
        // Multiple references of variable dependent calls in variable CCRs are allowed!
        // It could happen when, the same variable is passed more then once as argument to an instruction...
        rVarRep.getOutputExecutableCallCCRs().push_back(this);
    }

    for (VariablesIter_t iter = _pInputVariables->begin(); iter != _pInputVariables->end(); ++iter)
    {
        assert(*iter != NULL);
        AVariableCCR& rVarRep = **iter;
        // Multiple references of variable dependent calls in variable CCRs are allowed!
        // It could happen when, the same variable is passed more then once as argument to an instruction...
        rVarRep.getInputExecutableCallCCRs().push_back(this);
    }

    return expandVarsScopes ? expandAllVarsScopesTillVisible() : true;
}

#endif

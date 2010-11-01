#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/ACollectedCodeRepr.hpp"

#include <cassert>
#include "ccr/ACCRVisitor.hpp"
#include "ccr/impl/ScopeBlockCCR.hpp"

using namespace CodeManagement;

ACollectedCodeRepr::ACollectedCodeRepr(const DebugInfo& rDebugInfo) :
    _debugInfo(rDebugInfo), _pParentScopeBlockCCR(NULL)
{
}

ACollectedCodeRepr::~ACollectedCodeRepr()
{
    assert(_pParentScopeBlockCCR == NULL);
}

void ACollectedCodeRepr::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void ACollectedCodeRepr::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

const DebugInfo& ACollectedCodeRepr::getDebugInfo() const
{
    return _debugInfo;
}

const ScopeBlockCCR* ACollectedCodeRepr::getParentScopeBlockCCR() const
{
    return _pParentScopeBlockCCR;
}

ScopeBlockCCR* ACollectedCodeRepr::getParentScopeBlockCCR()
{
    return _pParentScopeBlockCCR;
}

void ACollectedCodeRepr::setParentScopeBlockCCR(ScopeBlockCCR* pScopeBlock)
{
    _pParentScopeBlockCCR = pScopeBlock;
}

#endif

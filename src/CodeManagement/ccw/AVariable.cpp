#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccw/AVariable.hpp"

#include <cassert>
#include "misc/debug/impl/Exception.hpp"

using namespace CodeManagement;

AVariable::variableId_t AVariable::_lastId = 0;

AVariable::AVariable(const DebugInfo& rDebugInfo) :
    _wasCopied(false), _id(generateNewId()), _debugInfo(rDebugInfo)
{
}

AVariable::~AVariable()
{
}

AVariable::AVariable(const AVariable& rToCopy) :
    _wasCopied(false), _id(rToCopy._id), _debugInfo(rToCopy._debugInfo)
{
    // Let this copy be the original and "forget" the true original.
    rToCopy._wasCopied = true;
}

AVariable& AVariable::operator=(const AVariable&)
{
    throw CM_CREATE_EXCEPTION("Illegal call to copy-assignment!");
    return *this;
}

AVariable::variableId_t AVariable::getVariableId() const
{
    return _id;
}

const DebugInfo& AVariable::getDebugInfo() const
{
    return _debugInfo;
}

bool AVariable::wasCopied() const
{
    return _wasCopied;
}

void AVariable::setDebugInfo(const DebugInfo& rDebugInfo)
{
    _debugInfo = rDebugInfo;
}

AVariable::variableId_t AVariable::generateNewId()
{
    if (_lastId == (variableId_t)-1)
        throw CM_CREATE_EXCEPTION("Variable ids overflow!");
    return ++_lastId;
}

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "exec/AVariableInstance.hpp"

#include <cassert>

using namespace CodeManagement;

AVariableInstance::AVariableInstance(const DebugInfo& rDebugInfo) : _debugInfo(rDebugInfo)
{
}

AVariableInstance::~AVariableInstance()
{
}

AVariableInstance::AVariableInstance(const AVariableInstance& rToCopy) : _debugInfo(rToCopy._debugInfo)
{
    assert(false);
}

AVariableInstance& AVariableInstance::operator=(const AVariableInstance&)
{
    assert(false);
    return *this;
}

const DebugInfo& AVariableInstance::getDebugInfo() const
{
    return _debugInfo;
}

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccw/AProcedure.hpp"

using namespace CodeManagement;

AProcedure::AProcedure(size_t outputVariables, size_t inputVariables) :
    AInstruction(outputVariables, inputVariables)
{
    setDebugInfo(CM_CREATE_DEBUG_INFO("unknown procedure"));
}

#endif

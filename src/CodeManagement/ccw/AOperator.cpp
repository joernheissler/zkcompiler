#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccw/AOperator.hpp"

using namespace CodeManagement;

AOperator::AOperator(size_t outputVariables, size_t inputVariables) :
    AFunction(outputVariables, inputVariables)
{
    setDebugInfo(CM_CREATE_DEBUG_INFO("unknown operator"));
}

#endif

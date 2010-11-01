#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_OPERATOR_HPP
#define CM_A_OPERATOR_HPP

#include "ccr/AOperatorCallCCR.hpp"
#include "ccw/AFunction.hpp"

namespace CodeManagement
{

    class AOperator : public AFunction
    {
    protected:
        AOperator(size_t outputVariables, size_t inputVariables);

    public:
        virtual AOperatorCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const = 0;
    };

}

#endif

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_PROCEDURE_HPP
#define CM_A_PROCEDURE_HPP

#include "ccr/AProcedureCallCCR.hpp"
#include "ccw/AInstruction.hpp"

namespace CodeManagement
{

    class AProcedure : public AInstruction
    {
    protected:
        AProcedure(size_t outputVariables, size_t inputVariables);

    public:
        virtual AProcedureCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const = 0;
    };

}

#endif

#endif

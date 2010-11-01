#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_CONSTRUCTOR_CALL_CCR_HPP
#define CM_A_CONSTRUCTOR_CALL_CCR_HPP

#include "ccr/AVarSpecialCallCCR.hpp"

namespace CodeManagement
{

    class AConstructorCallCCR : public AVarSpecialCallCCR
    {
    public:
        typedef AVarSpecialCallCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;

    public:
        AConstructorCallCCR(const DebugInfo& rDebugInfo);
        ~AConstructorCallCCR();

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes);
        bool bindVariables(AVariableCCR& rThis, bool expandVarScope);
    };

}

#endif

#endif

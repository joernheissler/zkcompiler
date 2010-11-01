#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_COPY_ASSIGNMENT_CALL_CCR_HPP
#define CM_A_COPY_ASSIGNMENT_CALL_CCR_HPP

#include "ccr/AVarSpecialCallCCR.hpp"

namespace CodeManagement
{
    class ASourceInstanceCaster;

    class ACopyAssignmentCallCCR : public AVarSpecialCallCCR
    {
    public:
        typedef AVarSpecialCallCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;

    public:
        ACopyAssignmentCallCCR(const DebugInfo& rDebugInfo, const ASourceInstanceCaster* pRHSSrcInstCaster);
        virtual ~ACopyAssignmentCallCCR();

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes);
        bool bindVariables(AVariableCCR& rThis, AVariableCCR& rRHS, bool expandVarsScopes);
        const AVariableCCR& getRHSVariable() const;
        const ASourceInstanceCaster* getRHSSrcInstCaster() const;

    private:
        const AVariableCCR* _pRHSVariable;
        const ASourceInstanceCaster* _pRHSSrcInstCaster;
    };

}

#endif

#endif

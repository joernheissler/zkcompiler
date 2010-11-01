#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_COPY_CONSTRUCTOR_CALL_CCR_HPP
#define CM_A_COPY_CONSTRUCTOR_CALL_CCR_HPP

#include "ccr/AConstructorCallCCR.hpp"

namespace CodeManagement
{
    class ASourceInstanceCaster;

    class ACopyConstructorCallCCR : public AConstructorCallCCR
    {
    public:
        typedef AConstructorCallCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;

    public:
        ACopyConstructorCallCCR(const DebugInfo& rDebugInfo, const ASourceInstanceCaster* pToCopySrcInstCaster);
        virtual ~ACopyConstructorCallCCR();

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes);
        bool bindVariables(AVariableCCR& rThis, AVariableCCR& rToCopy, bool expandVarsScopes);
        const AVariableCCR& getToCopyVariable() const;
        const ASourceInstanceCaster* getToCopySrcInstCaster() const;

    private:
        const AVariableCCR* _pToCopyVariable;
        const ASourceInstanceCaster* _pToCopySrcInstCaster;
    };

}

#endif

#endif

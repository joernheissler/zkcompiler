#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_FUNCTION_CALL_CCR_HPP
#define CM_A_FUNCTION_CALL_CCR_HPP

#include "ccr/AInstructionCallCCR.hpp"

namespace CodeManagement
{
    class ASourceInstanceCaster;

    class AFunctionCallCCR : public AInstructionCallCCR
    {
    public:
        typedef AInstructionCallCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;
        typedef void(*ExecuteFunc_t)(const AFunctionCallCCR&, AExecutableCCR::InstancesTable_t&, void*);
        typedef Base_t::Variables_t Variables_t;
        typedef Base_t::VariablesIter_t VariablesIter_t;
        typedef Base_t::VariablesConstIter_t VariablesConstIter_t;

    protected:
        AFunctionCallCCR(ExecuteFunc_t executeFunc, const ASourceInstanceCaster* pReturnSrcInstCaster, bool hasReturnVar, const DebugInfo& rDebugInfo);
        virtual ~AFunctionCallCCR();

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        size_t getReturnVariableIndex() const;
        bool hasReturnVariable() const;
        const ASourceInstanceCaster* getReturnSrcInstCaster() const;

    private:
        const bool _hasReturnVariable;
        const ASourceInstanceCaster* _pReturnSrcInstCaster;
    };

}

#endif

#endif

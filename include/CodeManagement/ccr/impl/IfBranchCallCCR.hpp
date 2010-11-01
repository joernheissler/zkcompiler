#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CMM_IF_BRANCH_CALL_CCR_HPP
#define CMM_IF_BRANCH_CALL_CCR_HPP

#include "ccr/impl/ScopeBlockCCR.hpp"

namespace CodeManagement
{
    class AVariableCCR;

    class IfBranchCallCCR : public ScopeBlockCCR
    {
    public:
        typedef ScopeBlockCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;
        typedef Base_t::Variables_t Variables_t;
        typedef Base_t::VariablesIter_t VariablesIter_t;
        typedef Base_t::VariablesConstIter_t VariablesConstIter_t;

    public:
        IfBranchCallCCR(const DebugInfo& rDebugInfo);
        virtual ~IfBranchCallCCR();

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);

    public:
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes);
        bool bindConditionVariable(AVariableCCR& rCondVar, bool expandVarScope);
        const AVariableCCR& getConditionVariable() const;
        void bindPreConditionBlock(ScopeBlockCCR& rScopeBlock);
        void bindPostConditionBlock(ScopeBlockCCR& rScopeBlock);
        void bindTrueBlock(ScopeBlockCCR& rScopeBlock);
        void bindFalseBlock(ScopeBlockCCR& rScopeBlock);
        const ScopeBlockCCR& getPreConditionBlock() const;
        const ScopeBlockCCR& getPostConditionBlock() const;
        const ScopeBlockCCR& getTrueBlock() const;
        const ScopeBlockCCR* getFalseBlock() const;

    private:
        AVariableCCR* _pConditionVar;
        ScopeBlockCCR* _pPreConditionBlock;
        ScopeBlockCCR* _pPostConditionBlock;
        ScopeBlockCCR* _pTrueBlock;
        ScopeBlockCCR* _pFalseBlock;
    };

}

#endif

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_EXECUTABLE_CCR_HPP
#define CM_A_EXECUTABLE_CCR_HPP

#include <vector>
#include "ccr/ACollectedCodeRepr.hpp"
#include "exec/impl/VariablesTable.hpp"

namespace CodeManagement
{

    class ACCRVisitor;
    class AVariableCCR;
    class AVariableInstance;

    class AExecutableCCR : public ACollectedCodeRepr
    {
    public:
        typedef ACollectedCodeRepr Base_t;
        typedef VariablesTable<AVariableInstance> InstancesTable_t;
        typedef std::vector<AVariableCCR*> Variables_t;
        typedef Variables_t::iterator VariablesIter_t;
        typedef Variables_t::const_iterator VariablesConstIter_t;

    public:
        AExecutableCCR(const DebugInfo& rDebugInfo);
        virtual ~AExecutableCCR();

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool isBulk() const;
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const = 0;
        virtual bool expandAllVarsScopesTillVisible();
        virtual void insertPrevCCR(AExecutableCCR& rCCR);
        virtual void insertNextCCR(AExecutableCCR& rCCR);
        const AExecutableCCR* getPrevCCR() const;
        AExecutableCCR* getPrevCCR();
        const AExecutableCCR* getNextCCR() const;
        AExecutableCCR* getNextCCR();
        const ScopeBlockCCR* getParentScopeBlockCCR() const;
        ScopeBlockCCR* getParentScopeBlockCCR();
        const AExecutableCCR* getScopeOverallPrevCCR() const;
        AExecutableCCR* getScopeOverallPrevCCR();
        const AExecutableCCR* getScopeOverallNextCCR() const;
        AExecutableCCR* getScopeOverallNextCCR();
        size_t getOutputVariablesNumber() const;
        size_t getInputVariablesNumber() const;
        const AVariableCCR& getOutputVariable(size_t index) const;
        AVariableCCR& getOutputVariable(size_t index);
        const AVariableCCR& getInputVariable(size_t index) const;
        AVariableCCR& getInputVariable(size_t index);
        bool isVarUsedAsOutOrInput(const AVariableCCR& rVar) const;

    protected:
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes);

    protected:
        AExecutableCCR* _pPrevCCR;
        AExecutableCCR* _pNextCCR;
        Variables_t* _pOutputVariables;
        Variables_t* _pInputVariables;
    };

}

#endif

#endif

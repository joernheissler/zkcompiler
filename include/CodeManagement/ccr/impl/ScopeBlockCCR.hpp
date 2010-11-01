#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_SCOPE_BLOCK_CCR_HPP
#define CM_SCOPE_BLOCK_CCR_HPP

#include <map>
#include "ccr/AExecutableCCR.hpp"
#include "ccr/AVariableCCR.hpp"
#include "exec/impl/VariablesTable.hpp"

namespace CodeManagement
{
    class ACCRVisitor;
    class ProgramCCR;

    class ScopeBlockCCR : public AExecutableCCR
    {
    public:
        typedef AExecutableCCR Base_t;
        typedef VariablesTable<AVariableInstance> InstancesTable_t;
        typedef VariablesTable<AVariableCCR> VariablesTable_t;

    public:
        ScopeBlockCCR(const DebugInfo& rDebugInfo);
        virtual ~ScopeBlockCCR();

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);

    public:
        void insertFirstInScopeCCR(AExecutableCCR& rCCR);
        void insertLastInScopeCCR(AExecutableCCR& rCCR);

    public:
        const AExecutableCCR* getFirstCallCCR() const;
        const AExecutableCCR* getLastCallCCR() const;
        bool isVariableVisible(const AVariableCCR& rVariable) const;
        size_t getOwnVarsNumber() const;
        template<class TVarsContainer> void getOwnVariables(TVarsContainer& rVars) const
        {
            _variablesTable.getAllVariables(rVars);
        }
        template<class TVarsContainer> void getOwnVariables(TVarsContainer& rVars)
        {
            _variablesTable.getAllVariables(rVars);
        }
        const ProgramCCR* getProgram(const std::string& rIdentifier) const;

    private:
        void addVariable(AVariableCCR& rVariable);
        void removeVariable(AVariableCCR& rVariable);

    private:
        VariablesTable_t _variablesTable;
        AExecutableCCR* _pFirstInScopeCCR;
        AExecutableCCR* _pLastInScopeCCR;

        friend class AVariableCCR;  // Needed for adding/removing to scope block.
    };

}

#endif

#endif

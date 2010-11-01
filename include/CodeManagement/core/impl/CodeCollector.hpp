#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_CODE_COLLECTOR_HPP
#define CM_CODE_COLLECTOR_HPP

#include <stack>
#include <string>
#include "ccr/AVariableCCR.hpp"
#include "core/ACodeObserver.hpp"
#include "exec/impl/VariablesTable.hpp"

namespace CodeManagement
{
    class AExecutableCCR;
    class AInstruction;
    class ProgramCCR;
    class ScopeBlockCCR;

    class CodeCollector : ACodeObserver
    {
    public:
        typedef VariablesTable<AVariableCCR> VariablesTable_t;
        typedef VariablesTable_t::variableId_t variableId_t;

    public:
        CodeCollector(const std::string& rIdentifier);
        virtual ~CodeCollector();

    public:
        bool isCollecting() const;
        void setDestroyProgramOnDestruction(bool destroy = true);
        bool isDestroyProgramOnDestruction() const;
        ProgramCCR& getProgram();
        ProgramCCR& beginSubProgram(const std::string& rIdentifier);
        ProgramCCR& endSubProgram(const std::string& rIdentifier);
        const AExecutableCCR* getLastInsertedAtomicCCR() const;

    public:
        void addOutputVariable(AVariable& rVariable, const std::string& rIdentifier);
        void addInputVariable(AVariable& rVariable, const std::string& rIdentifier);
#ifndef CM_ENABLE_CODE_COLLECTING
        template<typename TSourceType>
        void addOutputVariable(TSourceType& /*rVariable*/, const std::string& /*rIdentifier*/)
        {
            // Nothing to do...
        }
        template<typename TSourceType>
        void addInputVariable(TSourceType& /*rVariable*/, const std::string& /*rIdentifier*/)
        {
            // Nothing to do...
        }
#endif

    public:
        virtual void onCallVariableConstructor(const AVariable& rVariable);
        virtual void onCallVariableDestructor(const AVariable& rVariable);
        virtual void onCallVariableCopyConstructor(const AVariable& rVariable, const AVariable& rToCopy,
            const ASourceInstanceCaster* pToCopySrcInstCaster);
        virtual void onCallVariableCopyAssignment(const AVariable& rVariable, const AVariable& rRHS,
            const ASourceInstanceCaster* pRHSSrcInstCaster);
        virtual void onCallInstruction(const AInstruction& rInstruction);
        virtual void onCallIfBranchBegin(bool endPrevOnNextEnd, const DebugInfo& rDebugInfo);
        virtual void onCallIfBranchCondition(const AVariable& rCondVarTempCopy);
        virtual void onCallIfBranchTrueBlock(const DebugInfo& rDebugInfo);
        virtual void onCallIfBranchFalseBlock(const DebugInfo& rDebugInfo);
        virtual void onCallIfBranchEnd(const DebugInfo& rDebugInfo);
        virtual void onComment(const std::string& rText, const DebugInfo& rDebugInfo);

    private:
        void throwException(std::string msg);
        void checkVarsScopesExpanding(AExecutableCCR& rCCR) const;

    private:
        bool _destroyProgramOnDestruction;
        ProgramCCR* const _pProgram;
        std::stack<ProgramCCR*> _programStack;
        std::stack<ScopeBlockCCR*> _scopeBlockStack;
        VariablesTable_t _variablesTable;
        AExecutableCCR* _pLastInsertedAtomicCCR;
    };


    void inline CodeCollector::setDestroyProgramOnDestruction(bool destroy)
    {
        _destroyProgramOnDestruction = destroy;
    }

    bool inline CodeCollector::isDestroyProgramOnDestruction() const
    {
        return _destroyProgramOnDestruction;
    }

}

#endif

#endif

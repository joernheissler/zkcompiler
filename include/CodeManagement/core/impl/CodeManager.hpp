#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_CODE_MANAGER_HPP
#define CM_CODE_MANAGER_HPP

#include <list>
#include <memory>
#include <stack>
#include "core/ACodeObserver.hpp"
#include "exec/impl/VariablesTable.hpp"

#define CM_INIT_CODE_MANAGER_EX(codeManagerContructor) \
    std::auto_ptr<CodeManagement::CodeManager> CodeManagement::CodeManager::_managerPtr(new codeManagerContructor)
#define CM_INIT_CODE_MANAGER CM_INIT_CODE_MANAGER_EX(CodeManagement::CodeManager)

#ifdef CM_ENABLE_CODE_COLLECTING
    #define CMM_IF(condition) {\
        CodeManagement::CodeManager::getManager().onCallIfBranchBegin(false, CM_CREATE_DEBUG_INFO("CMM_IF(" #condition ")"));\
        CodeManagement::CodeManager::getManager().onCallIfBranchCondition(\
            /* We need a temporally copy of the condition variable! */\
            CodeManagement::CopyableVariable<bool>((condition), CM_CREATE_DEBUG_INFO("CMM_IF(" #condition ")")));\
        CodeManagement::CodeManager::getManager().onCallIfBranchTrueBlock(CM_CREATE_DEBUG_INFO("CMM_IF(" #condition ")")); {
    #define CMM_ELSE \
        } CodeManagement::CodeManager::getManager().onCallIfBranchFalseBlock(CM_CREATE_DEBUG_INFO("CMM_ELSE")); {
    #define CMM_ELIF(condition) }\
        CodeManagement::CodeManager::getManager().onCallIfBranchFalseBlock(CM_CREATE_DEBUG_INFO("CMM_ELIF(" #condition ")"));\
        CodeManagement::CodeManager::getManager().onCallIfBranchBegin(true, CM_CREATE_DEBUG_INFO("CMM_ELIF(" #condition ")"));\
        CodeManagement::CodeManager::getManager().onCallIfBranchCondition(\
            /* We need a temporally copy of the condition variable! */\
            CodeManagement::CopyableVariable<bool>((condition), CM_CREATE_DEBUG_INFO("CMM_ELIF(" #condition ")")));\
        CodeManagement::CodeManager::getManager().onCallIfBranchTrueBlock(CM_CREATE_DEBUG_INFO("CMM_ELIF(" #condition ")")); {
    #define CMM_ENDIF }\
        CodeManagement::CodeManager::getManager().onCallIfBranchEnd(CM_CREATE_DEBUG_INFO("CMM_ENDIF")); }

    #define CMM_IS_EXECUTING (CodeManagement::CodeManager::getManager().isInExecutingCodeRegion())

    #define CMM_COMMENT(text) CodeManagement::CodeManager::getManager().onComment(text, CM_CREATE_DEBUG_INFO("comment"))
#else
    #define CMM_IF(condition) { if (condition) {
    #define CMM_ELSE } else {
    #define CMM_ELIF(condition) } else if (condition) {
    #define CMM_ENDIF } }

    #define CMM_IS_EXECUTING (true)

    #define CMM_COMMENT(text)
#endif

namespace CodeManagement
{
    class AExecutableCCR;
    class AVariableInstance;
    class CodeCollector;
    class ProgramCCR;

    class CodeManager : public ACodeObserver
    {
    protected:
        typedef std::list<CodeCollector*> CodeCollectors_t;
        typedef CodeCollectors_t::iterator CodeCollectorsIter_t;
        typedef CodeCollectors_t::const_iterator CodeCollectorsConstIter_t;
        typedef VariablesTable<AVariableInstance> VariablesTable_t;

    protected:
        enum EIfBranchCondRes
        {
            ibcr_nothing,
            ibcr_true,
            ibcr_false
        };
        struct IfBranchInfo
        {
            EIfBranchCondRes _conditionResult;
            bool _inBlock;
            bool _endPrevOnEnd;
        };

    public:
        CodeManager();
        virtual ~CodeManager();

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

    public:
        bool isInExecutingCodeRegion();
        virtual const void* getVariableSourceInstance(const AVariable& rVariable) const;

    protected:
        void executeLastGlobalAtomicCCR(void* pRetSrcInstCopy = NULL);

    private:
        void addCodeCollector(CodeCollector& rCodeCollector);
        void removeCodeCollector(CodeCollector& rCodeCollector);

    public:
        static CodeManager& getManager();

    private:
        static bool isInited();

    private:
        CodeCollectors_t _codeCollectors;
        VariablesTable_t _globalVariablesTable;
        CodeCollector* _pGlobalCodeCollector;
        const AExecutableCCR* _pLastExecutedGlobalCCR;
        std::stack<IfBranchInfo> _ifBranchInfoStack;
        std::stack<IfBranchInfo> _nextIfBranchInfoStack;

    private:
        static std::auto_ptr<CodeManagement::CodeManager> _managerPtr;
        static bool _inited;

        friend class CodeCollector; // For adding to CodeManager on construction of CodeCollector.
    };

}

#endif

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_CODE_OBSERVER_HPP
#define CM_A_CODE_OBSERVER_HPP

#include <string>

namespace CodeManagement
{
    class AInstruction;
    class AVariable;
    class DebugInfo;
    class ASourceInstanceCaster;

    class ACodeObserver
    {
    public:
        virtual ~ACodeObserver();

    public:
        virtual void onCallVariableConstructor(const AVariable& rVariable) = 0;
        virtual void onCallVariableDestructor(const AVariable& rVariable) = 0;
        virtual void onCallVariableCopyConstructor(const AVariable& rVariable, const AVariable& rToCopy,
            const ASourceInstanceCaster* pToCopySrcInstCaster) = 0;
        virtual void onCallVariableCopyAssignment(const AVariable& rVariable, const AVariable& rRHS,
            const ASourceInstanceCaster* pRHSSrcInstCaster) = 0;
        virtual void onCallInstruction(const AInstruction& rInstruction) = 0;
        virtual void onCallIfBranchBegin(bool endPrevOnNextEnd, const DebugInfo& rDebugInfo) = 0;
        virtual void onCallIfBranchCondition(const AVariable& rCondVarTempCopy) = 0;
        virtual void onCallIfBranchTrueBlock(const DebugInfo& rDebugInfo) = 0;
        virtual void onCallIfBranchFalseBlock(const DebugInfo& rDebugInfo) = 0;
        virtual void onCallIfBranchEnd(const DebugInfo& rDebugInfo) = 0;
        virtual void onComment(const std::string& rText, const DebugInfo& rDebugInfo) = 0;
    };

}

#endif

#endif

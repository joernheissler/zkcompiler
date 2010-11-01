#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_INSTRUCTION_HPP
#define CM_A_INSTRUCTION_HPP

#include <vector>
#include "misc/debug/impl/DebugInfo.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    #define CMI(instructionCall) (CMI::instructionCall).call(CM_CREATE_DEBUG_INFO(#instructionCall))
#else
    #define CMI(instructionCall) instructionCall
#endif

namespace CodeManagement
{
    class AInstructionCall;
    class AInstructionCallCCR;
    class AVariable;

    // Note: call() has to be implemented in the final derived class! call() can differ in return type and is not allowed
    // to be called from AInstruction, that's why it is not declared here, but the CMI-macros use it!
    class AInstruction
    {
    protected:
        AInstruction(size_t outputVariables, size_t inputVariables);

    public:
        virtual ~AInstruction();

    public:
        virtual AInstructionCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const = 0;
        const std::vector<AVariable*>& getOutputVariables() const;
        const std::vector<const AVariable*>& getInputVariables() const;
        const DebugInfo& getDebugInfo() const;

    protected:
        void bindOutputVariable(size_t index, AVariable& rVariable);
        void bindInputVariable(size_t index, const AVariable& rVariable);
        void setDebugInfo(const DebugInfo& rDebugInfo);

    protected:
        std::vector<AVariable*> _outputVariables;
        std::vector<const AVariable*> _inputVariables;
        DebugInfo _debugInfo;
    };

}

#endif

#endif

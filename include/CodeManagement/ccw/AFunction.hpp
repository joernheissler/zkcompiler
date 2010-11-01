#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_FUNCTION_HPP
#define CM_A_FUNCTION_HPP

#include "ccr/AFunctionCallCCR.hpp"
#include "ccw/AInstruction.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    #define CMI_OUT(instructionCall) (((CMI::instructionCall).call(CM_CREATE_DEBUG_INFO(#instructionCall))).getSourceInstance(CM_CREATE_DEBUG_INFO("CMI_OUT(" #instructionCall ")")))
    #define CMI_CCAST(type, instructionCall) ((CMI::instructionCall).call(CM_CREATE_DEBUG_INFO(#instructionCall)).explicitCCast< type >(CM_CREATE_DEBUG_INFO("CMV_CCAST(" #type ", " #instructionCall ")")))
#else
    #define CMI_OUT(instructionCall) (instructionCall)
    #define CMI_CCAST(type, instructionCall) ((type)(instructionCall))
#endif

namespace CodeManagement
{
    class ASourceInstanceCaster;

    class AFunction : public AInstruction
    {
    protected:
        AFunction(size_t outputVariables, size_t inputVariables);

    public:
        virtual AFunctionCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const = 0;
        bool hasReturnVariable() const;
        const ASourceInstanceCaster* getReturnSrcInstCaster() const;
        void call(AVariable* pReturnVar, const ASourceInstanceCaster* pReturnSrcInstCaster);

    private:
        bool _hasReturnVariable;
        const ASourceInstanceCaster* _pReturnSrcInstCaster;
    };

}

#endif

#endif

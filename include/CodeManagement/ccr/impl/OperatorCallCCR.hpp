#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_OPERATOR_CALL_CRR_HPP
#define CM_OPERATOR_CALL_CRR_HPP

#include "ccr/AOperatorCallCCR.hpp"

namespace CodeManagement
{

    template<class TOperator>
    class OperatorCallCCR : public AOperatorCallCCR
    {
    public:
        typedef AOperatorCallCCR::ExecuteFunc_t ExecuteFunc_t;

    public:
        OperatorCallCCR(ExecuteFunc_t executeFunc, const ASourceInstanceCaster* pReturnSrcInstCaster, bool hasReturnVar,
            const std::string& rInstrIdent, const std::string& rOperIdent, EOperator operEnum, const DebugInfo& rDebugInfo) :
            AOperatorCallCCR(executeFunc, pReturnSrcInstCaster, hasReturnVar, rDebugInfo),
            _instructionIdentifier(rInstrIdent), _operatorIdentifier(rOperIdent), _enum(operEnum)
        {
            assert(getOperatorIdentifier() != NULL && getOperatorIdentifier()[0] != '\0');
            // Logical operators && and || are not allowed, because of changing the control flow!
            assert(getOperatorIdentifier()[0] != '&' || getOperatorIdentifier()[1] != '&');
            assert(getOperatorIdentifier()[0] != '|' || getOperatorIdentifier()[1] != '|');
        }

    public:
        virtual const char* getInstructionIdentifier() const
        {
            return _instructionIdentifier.c_str();
        }
        virtual const char* getOperatorIdentifier() const
        {
            return _operatorIdentifier.c_str();
        }
        virtual EOperator getOperatorEnum() const
        {
            return _enum;
        }

    private:
        const std::string _instructionIdentifier;
        const std::string _operatorIdentifier;
        const EOperator _enum;
    };

}

#endif

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_OPERATOR_HPP
#define CM_OPERATOR_HPP

#include "ccr/impl/OperatorCallCCR.hpp"
#include "ccw/AOperator.hpp"
#include "ccw/impl/CopyableVariable.hpp"

namespace CodeManagement
{

    template<typename TSrcTypeReturn>
    class AOperatorTemplateBase : public AOperator
    {
    public:
        typedef TSrcTypeReturn Return_t;
        typedef CopyableVariable<Return_t> ReturnVariable_t;
        typedef AOperatorCallCCR::ExecuteFunc_t ExecuteFunc_t;

    protected:
        AOperatorTemplateBase(const std::string& rInstrIdent, const std::string& rOperIdent, EOperator operEnum,
            size_t outputVariables, size_t inputVariables) : AOperator(outputVariables, inputVariables),
            _instructionIdentifier(rInstrIdent), _operatorIdentifier(rOperIdent), _enum(operEnum)
        {
        }

    public:
        ReturnVariable_t call(const DebugInfo& rDebugInfo)
        {
            setDebugInfo(rDebugInfo);
            ReturnVariable_t returnVariable(CM_CREATE_DEBUG_INFO("return of operator [" + rDebugInfo.toString() + "]"));
            AOperator::call(&returnVariable, NULL);
            return returnVariable;
        }

    protected:
        static void finishExecution(const Return_t& rRet, const AOperatorCallCCR& rCCR,
            AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            if (rCCR.hasReturnVariable())
            {
                assert(rCCR.getOutputInstance(rInstancesTable, rCCR.getReturnVariableIndex()).getSourceInstance() != NULL);
                AVariableInstance& rRetInst = rCCR.getOutputInstance(rInstancesTable, rCCR.getReturnVariableIndex());
                rRetInst.executeCopyAssignment(&rRet, rCCR.getReturnSrcInstCaster());
            }
            if (pRetSrcInstCopy != NULL)
                *(Return_t*)pRetSrcInstCopy = rRet;
        }

    protected:
        const std::string _instructionIdentifier;
        const std::string _operatorIdentifier;
        const EOperator _enum;
    };

#define _CM_PREPARE_OUTPUT_VARIABLE(varInd) \
        assert(rCCR.getOutputInstance(rInstancesTable, varInd).getSourceInstance() != NULL);\
        TSrcTypeOut##varInd& rOut##varInd = *(TSrcTypeOut##varInd*)rCCR.getOutputInstance(rInstancesTable, varInd).getSourceInstance()
#define _CM_PREPARE_INPUT_VARIABLE(varInd) \
        assert(rCCR.getInputInstance(rInstancesTable, varInd).getConstSourceInstance() != NULL);\
        TSrcTypeIn##varInd& rIn##varInd = *(TSrcTypeIn##varInd*)rCCR.getInputInstance(rInstancesTable, varInd).getConstSourceInstance()
#define _CM_IMPL_OPERATOR_CREATE_NEW_CCR \
    public:\
        typedef OperatorCallCCR<This_t> CallCCR_t;\
        virtual AOperatorCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const\
        {\
            return new CallCCR_t(execute, this->getReturnSrcInstCaster(), this->hasReturnVariable(),\
                this->_instructionIdentifier, this->_operatorIdentifier, this->_enum, rDebugInfo);\
        }

    template<typename TSrcTypeReturn, typename TSrcTypeIn0,
        TSrcTypeReturn(*TSrcInstruction)(const TSrcTypeIn0&)>
    class Operator_i1 : public AOperatorTemplateBase<TSrcTypeReturn>
    {
    public:
        typedef Operator_i1 This_t;
        typedef AOperatorTemplateBase<TSrcTypeReturn> Base_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;

        _CM_IMPL_OPERATOR_CREATE_NEW_CCR

    public:
        Operator_i1(const std::string& rInstrIdent, const std::string& rOperIdent, EOperator operEnum, const InputVariable0_t& rIn0) :
            Base_t(rInstrIdent, rOperIdent, operEnum, 0, 1)
        {
            bindInputVariable(0, rIn0);
        }

    private:
        static void execute(const AOperatorCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            _CM_PREPARE_INPUT_VARIABLE(0);
            finishExecution(TSrcInstruction(rIn0), rCCR, rInstancesTable, pRetSrcInstCopy);
        }
    };

    template<typename TSrcTypeReturn, typename TSrcTypeOut0,
        TSrcTypeReturn(*TSrcInstruction)(TSrcTypeOut0&)>
    class Operator_o1 : public AOperatorTemplateBase<TSrcTypeReturn>
    {
    public:
        typedef Operator_o1 This_t;
        typedef AOperatorTemplateBase<TSrcTypeReturn> Base_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;

        _CM_IMPL_OPERATOR_CREATE_NEW_CCR

    public:
        Operator_o1(const std::string& rInstrIdent, const std::string& rOperIdent, EOperator operEnum, OutputVariable0_t& rOut0) :
            Base_t(rInstrIdent, rOperIdent, operEnum, 1, 0)
        {
            bindOutputVariable(0, rOut0);
        }

    private:
        static void execute(const AOperatorCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            finishExecution(TSrcInstruction(rOut0), rCCR, rInstancesTable, pRetSrcInstCopy);
        }
    };

    template<typename TSrcTypeReturn, typename TSrcTypeIn0, typename TSrcTypeIn1,
        TSrcTypeReturn(*TSrcInstruction)(const TSrcTypeIn0&, const TSrcTypeIn1&)>
    class Operator_i2 : public AOperatorTemplateBase<TSrcTypeReturn>
    {
    public:
        typedef Operator_i2 This_t;
        typedef AOperatorTemplateBase<TSrcTypeReturn> Base_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;
        typedef Variable<TSrcTypeIn1> InputVariable1_t;

        _CM_IMPL_OPERATOR_CREATE_NEW_CCR

    public:
        Operator_i2(const std::string& rInstrIdent, const std::string& rOperIdent, EOperator operEnum,
            const InputVariable0_t& rIn0, const InputVariable1_t& rIn1) : Base_t(rInstrIdent, rOperIdent, operEnum, 0, 2)
        {
            bindInputVariable(0, rIn0);
            bindInputVariable(1, rIn1);
        }

    private:
        static void execute(const AOperatorCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            _CM_PREPARE_INPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(1);
            finishExecution(TSrcInstruction(rIn0, rIn1), rCCR, rInstancesTable, pRetSrcInstCopy);
        }
    };

    template<typename TSrcTypeReturn, typename TSrcTypeOut0, typename TSrcTypeIn0,
        TSrcTypeReturn(*TSrcInstruction)(TSrcTypeOut0&, const TSrcTypeIn0&)>
    class Operator_o1i1 : public AOperatorTemplateBase<TSrcTypeReturn>
    {
    public:
        typedef Operator_o1i1 This_t;
        typedef AOperatorTemplateBase<TSrcTypeReturn> Base_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;

        _CM_IMPL_OPERATOR_CREATE_NEW_CCR

    public:
        Operator_o1i1(const std::string& rInstrIdent, const std::string& rOperIdent, EOperator operEnum,
            OutputVariable0_t& rOut0, const InputVariable0_t& rIn0) : Base_t(rInstrIdent, rOperIdent, operEnum, 1, 1)
        {
            bindOutputVariable(0, rOut0);
            bindInputVariable(0, rIn0);
        }

    private:
        static void execute(const AOperatorCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(0);
            finishExecution(TSrcInstruction(rOut0, rIn0), rCCR, rInstancesTable, pRetSrcInstCopy);
        }
    };

#undef _CM_IMPL_OPERATOR_CREATE_NEW_CCR
#undef _CM_PREPARE_INPUT_VARIABLE
#undef _CM_PREPARE_OUTPUT_VARIABLE

#define _CM_IMPL_OPERATOR_BINARY(operatorName, operatorIdent) \
    namespace Operators\
    {\
        template<typename TSrcType>\
        TSrcType operatorName(const TSrcType& rIn0, const TSrcType& rIn1)\
        {\
            return rIn0 operatorIdent rIn1;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcType>\
            CopyableVariable<TSrcType> operator operatorIdent(const CopyableVariable<TSrcType>& rIn0, const CopyableVariable<TSrcType>& rIn1)\
            {\
                return Operator_i2<TSrcType, TSrcType, TSrcType, Operators::operatorName<TSrcType> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rIn0, rIn1).call(CM_CREATE_DEBUG_INFO(#operatorName));\
            }\
        }\
    }

#define _CM_IMPL_OPERATOR_UNARY_GENERIC(operatorName, operatorIdent, returnIdent) \
    namespace Operators\
    {\
        template<typename TSrcType>\
        returnIdent operatorName(const TSrcType& rIn0)\
        {\
            return operatorIdent rIn0;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcType>\
            CopyableVariable<returnIdent> operator operatorIdent(const CopyableVariable<TSrcType>& rIn0)\
            {\
                return Operator_i1<returnIdent, TSrcType, Operators::operatorName<TSrcType> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rIn0).call(CM_CREATE_DEBUG_INFO(#operatorName));\
            }\
        }\
    }
#define _CM_IMPL_OPERATOR_UNARY(operatorName, operatorIdent) \
        _CM_IMPL_OPERATOR_UNARY_GENERIC(operatorName, operatorIdent, TSrcType)
#define _CM_IMPL_OPERATOR_UNARY_BOOL(operatorName, operatorIdent) \
        _CM_IMPL_OPERATOR_UNARY_GENERIC(operatorName, operatorIdent, bool)

#define _CM_IMPL_OPERATOR_PREFIX_MOD(operatorName, operatorIdent) \
    namespace Operators\
    {\
        template<typename TSrcType>\
        TSrcType operatorName(TSrcType& rOut0)\
        {\
            /* Note: this is not the right signature, because the returned value is just a copy! */\
            /* We can't do it right here, but the following definition of the c++-operator will handle it right.*/\
            return operatorIdent rOut0;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcType>\
            CopyableVariable<TSrcType>& operator operatorIdent(CopyableVariable<TSrcType>& rOut0)\
            {\
                Operator_o1<TSrcType, TSrcType, Operators::operatorName<TSrcType> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rOut0).call(CM_CREATE_DEBUG_INFO(#operatorName));\
                return rOut0;\
            }\
        }\
    }

#define _CM_IMPL_OPERATOR_SUFFIX_MOD(operatorName, operatorIdent) \
    namespace Operators\
    {\
        template<typename TSrcType>\
        TSrcType operatorName(TSrcType& rOut0)\
        {\
            return rOut0 operatorIdent;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcType>\
            CopyableVariable<TSrcType> operator operatorIdent(CopyableVariable<TSrcType>& rOut0, int)\
            {\
                return Operator_o1<TSrcType, TSrcType, Operators::operatorName<TSrcType> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rOut0).call(CM_CREATE_DEBUG_INFO(#operatorName));\
            }\
        }\
    }

#define _CM_IMPL_OPERATOR_COMPARE(operatorName, operatorIdent) \
    namespace Operators\
    {\
        template<typename TSrcTypeIn0, typename TSrcTypeIn1>\
        bool operatorName(const TSrcTypeIn0& rIn0, const TSrcTypeIn1& rIn1)\
        {\
            return rIn0 operatorIdent rIn1;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcTypeIn0, typename TSrcTypeIn1>\
            CopyableVariable<bool> operator operatorIdent(const CopyableVariable<TSrcTypeIn0>& rIn0, const CopyableVariable<TSrcTypeIn1>& rIn1)\
            {\
                return Operator_i2<bool, TSrcTypeIn0, TSrcTypeIn1, Operators::operatorName<TSrcTypeIn0, TSrcTypeIn1> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rIn0, rIn1).call(CM_CREATE_DEBUG_INFO(#operatorName));\
            }\
        }\
    }

#define _CM_IMPL_OPERATOR_BITWISE_SHIFT(operatorName, operatorIdent) \
    namespace Operators\
    {\
        template<typename TSrcTypeIn0, typename TSrcTypeIn1>\
        TSrcTypeIn0 operatorName(const TSrcTypeIn0& rIn0, const TSrcTypeIn1& rIn1)\
        {\
            return rIn0 operatorIdent rIn1;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcTypeIn0, typename TSrcTypeIn1>\
            CopyableVariable<TSrcTypeIn0> operator operatorIdent(const CopyableVariable<TSrcTypeIn0>& rIn0, const CopyableVariable<TSrcTypeIn1>& rIn1)\
            {\
                return Operator_i2<TSrcTypeIn0, TSrcTypeIn0, TSrcTypeIn1, Operators::operatorName<TSrcTypeIn0, TSrcTypeIn1> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rIn0, rIn1).call(CM_CREATE_DEBUG_INFO(#operatorName));\
            }\
        }\
    }

#define _CM_IMPL_OPERATOR_COMPOUND(operatorName, operatorIdent) \
    namespace Operators\
    {\
        template<typename TSrcType>\
        TSrcType operatorName(TSrcType& rOut0, const TSrcType& rIn0)\
        {\
            /* Note: this is not the right signature, because the returned value is just a copy! */\
            /* We can't do it right here, but the following definition of the c++-operator will handle it right.*/\
            return rOut0 operatorIdent rIn0;\
        }\
    }\
    namespace U\
    {\
        namespace O\
        {\
            template<typename TSrcType>\
            CopyableVariable<TSrcType>& operator operatorIdent(CopyableVariable<TSrcType>& rOut0, const CopyableVariable<TSrcType>& rIn0)\
            {\
                Operator_o1i1<TSrcType, TSrcType, TSrcType, Operators::operatorName<TSrcType> >\
                    (#operatorName, #operatorIdent, o_##operatorName, rOut0, rIn0).call(CM_CREATE_DEBUG_INFO(#operatorName));\
                return rOut0;\
            }\
        }\
    }

    // Arithmetic operators
    _CM_IMPL_OPERATOR_BINARY(addition, +)
    _CM_IMPL_OPERATOR_BINARY(subtracion, -)
    _CM_IMPL_OPERATOR_UNARY(plus, +)
    _CM_IMPL_OPERATOR_UNARY(minus, -)
    _CM_IMPL_OPERATOR_BINARY(multiplication, *)
    _CM_IMPL_OPERATOR_BINARY(division, /)
    _CM_IMPL_OPERATOR_BINARY(modulo, %)
    _CM_IMPL_OPERATOR_PREFIX_MOD(prefixIncrement, ++)
    _CM_IMPL_OPERATOR_PREFIX_MOD(prefixDecrement, --)
    _CM_IMPL_OPERATOR_SUFFIX_MOD(suffixIncrement, ++)
    _CM_IMPL_OPERATOR_SUFFIX_MOD(suffixDecrement, --)

    // Comparison operators/Relational operators
    _CM_IMPL_OPERATOR_COMPARE(equalTo, ==)
    _CM_IMPL_OPERATOR_COMPARE(notEqualTo, !=)
    _CM_IMPL_OPERATOR_COMPARE(greaterThan, >)
    _CM_IMPL_OPERATOR_COMPARE(lessThan, <)
    _CM_IMPL_OPERATOR_COMPARE(greaterThanOrEqualTo, >=)
    _CM_IMPL_OPERATOR_COMPARE(lessThanOrEqualTo, <=)

    // Logical operators
    _CM_IMPL_OPERATOR_UNARY_BOOL(logicalNegation, !)
    // _CM_IMPL_OPERATOR_COMPARE(logicalAND, &&) // Not allowed, because of changing the control flow!
    // _CM_IMPL_OPERATOR_COMPARE(logicalOR, ||)  // Not allowed, because of changing the control flow!

    // Bitwise operators
    _CM_IMPL_OPERATOR_UNARY(bitwiseNOT, ~)
    _CM_IMPL_OPERATOR_BINARY(bitwiseAND, &)
    _CM_IMPL_OPERATOR_BINARY(bitwiseOR, |)
    _CM_IMPL_OPERATOR_BINARY(bitwiseXOR, ^)
    _CM_IMPL_OPERATOR_BITWISE_SHIFT(bitwiseLeftShift, <<)
    _CM_IMPL_OPERATOR_BITWISE_SHIFT(bitwiseRightShift, >>)

    // Compound-assignment operators
    _CM_IMPL_OPERATOR_COMPOUND(additionAssign, +=)
    _CM_IMPL_OPERATOR_COMPOUND(subtractionAssign, -=)
    _CM_IMPL_OPERATOR_COMPOUND(multiplicationAssign, *=)
    _CM_IMPL_OPERATOR_COMPOUND(divisionAssign, /=)
    _CM_IMPL_OPERATOR_COMPOUND(moduloAssign, %=)
    _CM_IMPL_OPERATOR_COMPOUND(bitwiseANDAssign, &=)
    _CM_IMPL_OPERATOR_COMPOUND(bitwiseORAssign, |=)
    _CM_IMPL_OPERATOR_COMPOUND(bitwiseXORAssign, ^=)
    _CM_IMPL_OPERATOR_COMPOUND(bitwiseLeftShiftAssign, <<=)
    _CM_IMPL_OPERATOR_COMPOUND(bitwiseRightShiftAssign, >>=)

#undef _CM_IMPL_OPERATOR_BINARY_GENERIC
#undef _CM_IMPL_OPERATOR_BINARY
#undef _CM_IMPL_OPERATOR_BINARY_BOOL
#undef _CM_IMPL_OPERATOR_UNARY_GENERIC
#undef _CM_IMPL_OPERATOR_UNARY
#undef _CM_IMPL_OPERATOR_UNARY_BOOL
#undef _CM_IMPL_OPERATOR_PREFIX_MOD
#undef _CM_IMPL_OPERATOR_SUFFIX_MOD
#undef _CM_IMPL_OPERATOR_COMPOUND

}

#endif

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_FUNCTION_HPP
#define CM_FUNCTION_HPP

#include "ccr/impl/FunctionCallCCR.hpp"
#include "ccw/AFunction.hpp"
#include "ccw/impl/CopyableVariable.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // Aufruf nur nach den CM_*_TYPE-Aufrufen mit den dort definierten Typen!
    // Kein Namespace im Instruktion-Namen -> im Namespace der Instruktion aufrufen!
    // Keine überladungen der Instruktionen-Namen -> in inline-Funktionen mit anderen Namen einbetten!

    #define CMD_FUNCTION_i2(ret, instruction, in0, in1, paramIn0, paramIn1) \
        namespace U {\
            namespace I { typedef Function_i2<ret, in0, in1, paramIn0, paramIn1, instruction> instruction; }\
            namespace R { typedef FunctionCallCCR<I::instruction> instruction; } }\
        template<> inline const char* FunctionCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }
    #define CMD_FUNCTION_i2_sm(className, ret, instruction, in0, in1, paramIn0, paramIn1) \
        namespace U { typedef  className className;\
            namespace I { namespace className { typedef Function_i2<ret, in0, in1, paramIn0, paramIn1, U::className::instruction> instruction; } }\
            namespace R { namespace className { typedef FunctionCallCCR<I::className::instruction> instruction; } } }\
        template<> inline const char* FunctionCallCCR<U::I::className::instruction>::spec_getInstructionIdentifier() { return #className "::" #instruction; }

    #define CMD_FUNCTION_o1i2(ret, instruction, out0, in0, in1, paramIn0, paramIn1) \
        namespace U {\
            namespace I { typedef Function_o1i2<ret, out0, in0, in1, paramIn0, paramIn1, instruction> instruction; }\
            namespace R { typedef FunctionCallCCR<I::instruction> instruction; } }\
        template<> inline const char* FunctionCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }
#else
    #define CMD_FUNCTION_i2(ret, instruction, in0, in1, paramIn0, paramIn1) \
        namespace U { namespace R { typedef AFunctionCallCCR instruction; } }
    #define CMD_FUNCTION_i2_sm(className, ret, instruction, in0, in1, paramIn0, paramIn1) \
        namespace U { namespace R { namespace className { typedef AFunctionCallCCR instruction; } } }

    #define CMD_FUNCTION_o1i2(ret, instruction, out0, in0, in1, paramIn0, paramIn1) \
        namespace U { namespace R { typedef AFunctionCallCCR instruction; } }
#endif

namespace CodeManagement
{

    template<typename TSrcTypeReturn>
    class AFunctionTemplateBase : public AFunction
    {
    public:
        typedef TSrcTypeReturn Return_t;
        typedef CopyableVariable<Return_t> ReturnVariable_t;

    protected:
        AFunctionTemplateBase(size_t outputVariables, size_t inputVariables) :
            AFunction(outputVariables, inputVariables)
        {
        }

    public:
        ReturnVariable_t call(const DebugInfo& rDebugInfo)
        {
            setDebugInfo(rDebugInfo);
            ReturnVariable_t returnVariable(CM_CREATE_DEBUG_INFO("return of function [" + rDebugInfo.toString() + "]"));
            AFunction::call(&returnVariable, NULL);
            return returnVariable;
        }

    protected:
        static void finishExecution(const Return_t& rRet, const AFunctionCallCCR& rCCR,
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
    };

#define _CM_PREPARE_OUTPUT_VARIABLE(varInd) \
        assert(rCCR.getOutputInstance(rInstancesTable, varInd).getSourceInstance() != NULL);\
        TSrcTypeOut##varInd& rOut##varInd = *(TSrcTypeOut##varInd*)rCCR.getOutputInstance(rInstancesTable, varInd).getSourceInstance()
#define _CM_PREPARE_INPUT_VARIABLE(varInd) \
        assert(rCCR.getInputInstance(rInstancesTable, varInd).getConstSourceInstance() != NULL);\
        TSrcTypeIn##varInd& rIn##varInd = *(TSrcTypeIn##varInd*)rCCR.getInputInstance(rInstancesTable, varInd).getConstSourceInstance()
#define _CM_IMPL_FUNCTION_CREATE_NEW_CCR \
    public:\
        typedef FunctionCallCCR<This_t> CallCCR_t;\
        virtual AFunctionCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const\
        {\
            return new CallCCR_t(execute, this->getReturnSrcInstCaster(), this->hasReturnVariable(), rDebugInfo);\
        }

    template<typename TSrcTypeReturn, typename TSrcTypeIn0, typename TSrcTypeIn1,
        typename TParamTypeIn0, typename TParamTypeIn1,
        TSrcTypeReturn(*TSrcInstruction)(TParamTypeIn0, TParamTypeIn1)>
    class Function_i2 : public AFunctionTemplateBase<TSrcTypeReturn>
    {
    public:
        typedef Function_i2 This_t;
        typedef AFunctionTemplateBase<TSrcTypeReturn> Base_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;
        typedef Variable<TSrcTypeIn1> InputVariable1_t;

        _CM_IMPL_FUNCTION_CREATE_NEW_CCR

    public:
        Function_i2(const InputVariable0_t& rIn0, const InputVariable1_t& rIn1) :
            Base_t(0, 2)
        {
            bindInputVariable(0, rIn0);
            bindInputVariable(1, rIn1);
        }

    private:
        static void execute(const AFunctionCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            _CM_PREPARE_INPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(1);
            finishExecution(TSrcInstruction(rIn0, rIn1), rCCR, rInstancesTable, pRetSrcInstCopy);
        }
    };

    template<typename TSrcTypeReturn, typename TSrcTypeOut0, typename TSrcTypeIn0, typename TSrcTypeIn1,
        typename TParamTypeIn0, typename TParamTypeIn1,
        TSrcTypeReturn(*TSrcInstruction)(TSrcTypeOut0&, TParamTypeIn0, TParamTypeIn1)>
    class Function_o1i2 : public AFunctionTemplateBase<TSrcTypeReturn>
    {
    public:
        typedef Function_o1i2 This_t;
        typedef AFunctionTemplateBase<TSrcTypeReturn> Base_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;
        typedef Variable<TSrcTypeIn1> InputVariable1_t;

        _CM_IMPL_FUNCTION_CREATE_NEW_CCR

    public:
        Function_o1i2(OutputVariable0_t& rOut0,
            const InputVariable0_t& rIn0, const InputVariable1_t& rIn1) :
            Base_t(1, 2)
        {
            bindOutputVariable(0, rOut0);
            bindInputVariable(0, rIn0);
            bindInputVariable(1, rIn1);
        }

    private:
        static void execute(const AFunctionCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(1);
            finishExecution(TSrcInstruction(rOut0, rIn0, rIn1), rCCR, rInstancesTable, pRetSrcInstCopy);
        }
    };

#undef _CM_IMPL_FUNCTION_CREATE_NEW_CCR
#undef _CM_PREPARE_INPUT_VARIABLE
#undef _CM_PREPARE_OUTPUT_VARIABLE

}

#endif

#endif

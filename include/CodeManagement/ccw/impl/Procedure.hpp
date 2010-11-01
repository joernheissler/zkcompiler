#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_PROCEDURE_HPP
#define CM_PROCEDURE_HPP

#include "ccr/impl/ProcedureCallCCR.hpp"
#include "ccw/AProcedure.hpp"
#include "ccw/impl/Variable.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // Aufruf nur nach den CM_*_TYPE-Aufrufen mit den dort definierten Typen!
    // Kein Namespace im Instruktion-Namen -> im Namespace der Instruktion aufrufen!
    // Keine überladungen der Instruktionen-Namen -> in inline-Funktionen mit anderen Namen einbetten!

    #define CMD_PROCEDURE_o1(instruction, out0) \
        namespace U {\
            namespace I { typedef Procedure_o1<out0, instruction> instruction; }\
            namespace R { typedef ProcedureCallCCR<I::instruction> instruction; } }\
        template<> inline const char* ProcedureCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }

    #define CMD_PROCEDURE_o1i1(instruction, out0, in0, paramIn0) \
        namespace U {\
            namespace I { typedef Procedure_o1i1<out0, in0, paramIn0, instruction> instruction; }\
            namespace R { typedef ProcedureCallCCR<I::instruction> instruction; } }\
        template<> inline const char* ProcedureCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }
    #define CMD_PROCEDURE_o1i1_sm(className, instruction, out0, in0, paramIn0) \
        namespace U { typedef  className className;\
            namespace I { namespace className { typedef Procedure_o1i1<out0, in0, paramIn0, U::className::instruction> instruction; } }\
            namespace R { namespace className { typedef ProcedureCallCCR<I::className::instruction> instruction; } } }\
        template<> inline const char* ProcedureCallCCR<U::I::className::instruction>::spec_getInstructionIdentifier() { return #className "::" #instruction; }

    #define CMD_PROCEDURE_o1i2(instruction, out0, in0, in1, paramIn0, paramIn1) \
        namespace U {\
            namespace I { typedef Procedure_o1i2<out0, in0, in1, paramIn0, paramIn1, instruction> instruction; }\
            namespace R { typedef ProcedureCallCCR<U::I::instruction> instruction; } }\
        template<> inline const char* ProcedureCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }
    #define CMD_PROCEDURE_o1i2_sm(className, instruction, out0, in0, in1, paramIn0, paramIn1) \
        namespace U { typedef  className className;\
            namespace I { namespace className { typedef Procedure_o1i2<out0, in0, in1, paramIn0, paramIn1, U::className::instruction> instruction; } }\
            namespace R { namespace className { typedef ProcedureCallCCR<I::className::instruction> instruction; } } }\
        template<> inline const char* ProcedureCallCCR<U::I::className::instruction>::spec_getInstructionIdentifier() { return #className "::" #instruction; }

    #define CMD_PROCEDURE_o1i3(instruction, out0, in0, in1, in2, paramIn0, paramIn1, paramIn2) \
        namespace U {\
            namespace I { typedef Procedure_o1i3<out0, in0, in1, in2, paramIn0, paramIn1, paramIn2, instruction> instruction; }\
            namespace R { typedef ProcedureCallCCR<I::instruction> instruction; } }\
        template<> inline const char* ProcedureCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }

    #define CMD_PROCEDURE_i3(instruction, in0, in1, in2, paramIn0, paramIn1, paramIn2) \
        namespace U {\
            namespace I { typedef Procedure_i3<in0, in1, in2, paramIn0, paramIn1, paramIn2, instruction> instruction; }\
            namespace R { typedef ProcedureCallCCR<I::instruction> instruction; } }\
        template<> inline const char* ProcedureCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }

    #define CMD_PROCEDURE_o4i1(instruction, out0, out1, out2, out3, in0, paramIn0) \
        namespace U {\
            namespace I { typedef Procedure_o4i1<out0, out1, out2, out3, in0, paramIn0, instruction> instruction; }\
            namespace R { typedef ProcedureCallCCR<I::instruction> instruction; } }\
        template<> inline const char* ProcedureCallCCR<U::I::instruction>::spec_getInstructionIdentifier() { return #instruction; }
#else
    #define CMD_PROCEDURE_o1(instruction, out0) \
        namespace U { namespace R { typedef AProcedureCallCCR instruction; } }

    #define CMD_PROCEDURE_o1i1(instruction, out0, in0, paramIn0) \
        namespace U { namespace R { typedef AProcedureCallCCR instruction; } }
    #define CMD_PROCEDURE_o1i1_sm(className, instruction, out0, in0, paramIn0) \
        namespace U { namespace R { namespace className { typedef AProcedureCallCCR instruction; } } }

    #define CMD_PROCEDURE_o1i2(instruction, out0, in0, in1, paramIn0, paramIn1) \
        namespace U { namespace R { typedef AProcedureCallCCR instruction; } }
    #define CMD_PROCEDURE_o1i2_sm(className, instruction, out0, in0, in1, paramIn0, paramIn1) \
        namespace U { namespace R { namespace className { typedef AProcedureCallCCR instruction; } } }

    #define CMD_PROCEDURE_o1i3(instruction, out0, in0, in1, in2, paramIn0, paramIn1, paramIn2) \
        namespace U { namespace R { typedef AProcedureCallCCR instruction; } }

    #define CMD_PROCEDURE_i3(instruction, in0, in1, in2, paramIn0, paramIn1, paramIn2) \
        namespace U { namespace R { typedef AProcedureCallCCR instruction; } }

    #define CMD_PROCEDURE_o4i1(instruction, out0, out1, out2, out3, in0, paramIn0) \
        namespace U { namespace R { typedef AProcedureCallCCR instruction; } }
#endif

namespace CodeManagement
{

    class AProcedureTemplateBase : public AProcedure
    {
    protected:
        AProcedureTemplateBase(size_t outputVariables, size_t inputVariables) :
            AProcedure(outputVariables, inputVariables)
        {
        }

    public:
        void call(const DebugInfo& rDebugInfo)
        {
            setDebugInfo(rDebugInfo);
            CodeManager::getManager().onCallInstruction(*this);
        }
    };

#define _CM_PREPARE_OUTPUT_VARIABLE(varInd) \
        assert(rCCR.getOutputInstance(rInstancesTable, varInd).getSourceInstance() != NULL);\
        TSrcTypeOut##varInd& rOut##varInd = *(TSrcTypeOut##varInd*)rCCR.getOutputInstance(rInstancesTable, varInd).getSourceInstance()
#define _CM_PREPARE_INPUT_VARIABLE(varInd) \
        assert(rCCR.getInputInstance(rInstancesTable, varInd).getConstSourceInstance() != NULL);\
        TSrcTypeIn##varInd& rIn##varInd = *(TSrcTypeIn##varInd*)rCCR.getInputInstance(rInstancesTable, varInd).getConstSourceInstance()
#define _CM_IMPL_PROCEDURE_CREATE_NEW_CCR \
    public:\
        typedef ProcedureCallCCR<This_t> CallCCR_t;\
        virtual AProcedureCallCCR* createNewCCR(const DebugInfo& rDebugInfo) const\
        {\
            return new CallCCR_t(execute, rDebugInfo);\
        }

    template<typename TSrcTypeOut0,
        void(*TSrcInstruction)(TSrcTypeOut0&)>
    class Procedure_o1 : public AProcedureTemplateBase
    {
    public:
        typedef Procedure_o1 This_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;

        _CM_IMPL_PROCEDURE_CREATE_NEW_CCR

    public:
        Procedure_o1(OutputVariable0_t& rOut0) : AProcedureTemplateBase(1, 0)
        {
            bindOutputVariable(0, rOut0);
        }

    private:
        static void execute(const AProcedureCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            TSrcInstruction(rOut0);
        }
    };

    template<typename TSrcTypeOut0, typename TSrcTypeIn0,
        typename TParamTypeIn0,
        void(*TSrcInstruction)(TSrcTypeOut0&, TParamTypeIn0)>
    class Procedure_o1i1 : public AProcedureTemplateBase
    {
    public:
        typedef Procedure_o1i1 This_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;

        _CM_IMPL_PROCEDURE_CREATE_NEW_CCR

    public:
        Procedure_o1i1(OutputVariable0_t& rOut0, const InputVariable0_t& rIn0) :
            AProcedureTemplateBase(1, 1)
        {
            bindOutputVariable(0, rOut0);
            bindInputVariable(0, rIn0);
        }

    private:
        static void execute(const AProcedureCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(0);
            TSrcInstruction(rOut0, rIn0);
        }
    };

    template<typename TSrcTypeOut0, typename TSrcTypeIn0, typename TSrcTypeIn1,
        typename TParamTypeIn0, typename TParamTypeIn1,
        void(*TSrcInstruction)(TSrcTypeOut0&, TParamTypeIn0, TParamTypeIn1)>
    class Procedure_o1i2 : public AProcedureTemplateBase
    {
    public:
        typedef Procedure_o1i2 This_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;
        typedef Variable<TSrcTypeIn1> InputVariable1_t;

        _CM_IMPL_PROCEDURE_CREATE_NEW_CCR

    public:
        Procedure_o1i2(OutputVariable0_t& rOut0,
            const InputVariable0_t& rIn0, const InputVariable1_t& rIn1) :
            AProcedureTemplateBase(1, 2)
        {
            bindOutputVariable(0, rOut0);
            bindInputVariable(0, rIn0);
            bindInputVariable(1, rIn1);
        }

    private:
        static void execute(const AProcedureCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(1);
            TSrcInstruction(rOut0, rIn0, rIn1);
        }
    };

    template<typename TSrcTypeOut0, typename TSrcTypeIn0, typename TSrcTypeIn1, typename TSrcTypeIn2,
        typename TParamTypeIn0, typename TParamTypeIn1, typename TParamTypeIn2,
        void(*TSrcInstruction)(TSrcTypeOut0&, TParamTypeIn0, TParamTypeIn1, TParamTypeIn2)>
    class Procedure_o1i3 : public AProcedureTemplateBase
    {
    public:
        typedef Procedure_o1i3 This_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;
        typedef Variable<TSrcTypeIn1> InputVariable1_t;
        typedef Variable<TSrcTypeIn2> InputVariable2_t;

        _CM_IMPL_PROCEDURE_CREATE_NEW_CCR

    public:
        Procedure_o1i3(OutputVariable0_t& rOut0,
            const InputVariable0_t& rIn0, const InputVariable1_t& rIn1, const InputVariable2_t& rIn2) :
            AProcedureTemplateBase(1, 3)
        {
            bindOutputVariable(0, rOut0);
            bindInputVariable(0, rIn0);
            bindInputVariable(1, rIn1);
            bindInputVariable(2, rIn2);
        }

    private:
        static void execute(const AProcedureCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(1);
            _CM_PREPARE_INPUT_VARIABLE(2);
            TSrcInstruction(rOut0, rIn0, rIn1, rIn2);
        }
    };

    template<typename TSrcTypeIn0, typename TSrcTypeIn1, typename TSrcTypeIn2,
        typename TParamTypeIn0, typename TParamTypeIn1, typename TParamTypeIn2,
        void(*TSrcInstruction)(TParamTypeIn0, TParamTypeIn1, TParamTypeIn2)>
    class Procedure_i3 : public AProcedureTemplateBase
    {
    public:
        typedef Procedure_i3 This_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;
        typedef Variable<TSrcTypeIn1> InputVariable1_t;
        typedef Variable<TSrcTypeIn2> InputVariable2_t;

        _CM_IMPL_PROCEDURE_CREATE_NEW_CCR

    public:
        Procedure_i3(const InputVariable0_t& rIn0, const InputVariable1_t& rIn1, const InputVariable2_t& rIn2) :
            AProcedureTemplateBase(0, 3)
        {
            bindInputVariable(0, rIn0);
            bindInputVariable(1, rIn1);
            bindInputVariable(2, rIn2);
        }

    private:
        static void execute(const AProcedureCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable)
        {
            _CM_PREPARE_INPUT_VARIABLE(0);
            _CM_PREPARE_INPUT_VARIABLE(1);
            _CM_PREPARE_INPUT_VARIABLE(2);
            TSrcInstruction(rIn0, rIn1, rIn2);
        }
    };

    template<typename TSrcTypeOut0, typename TSrcTypeOut1, typename TSrcTypeOut2, typename TSrcTypeOut3, typename TSrcTypeIn0,
        typename TParamTypeIn0,
        void(*TSrcInstruction)(TSrcTypeOut0&, TSrcTypeOut1&, TSrcTypeOut2&, TSrcTypeOut3&, TParamTypeIn0)>
    class Procedure_o4i1 : public AProcedureTemplateBase
    {
    public:
        typedef Procedure_o4i1 This_t;
        typedef Variable<TSrcTypeOut0> OutputVariable0_t;
        typedef Variable<TSrcTypeOut1> OutputVariable1_t;
        typedef Variable<TSrcTypeOut2> OutputVariable2_t;
        typedef Variable<TSrcTypeOut3> OutputVariable3_t;
        typedef Variable<TSrcTypeIn0> InputVariable0_t;

        _CM_IMPL_PROCEDURE_CREATE_NEW_CCR

    public:
        Procedure_o4i1(OutputVariable0_t& rOut0, OutputVariable0_t& rOut1, OutputVariable0_t& rOut2, OutputVariable0_t& rOut3, const InputVariable0_t& rIn0) :
            AProcedureTemplateBase(4, 1)
        {
            bindOutputVariable(0, rOut0);
            bindOutputVariable(1, rOut1);
            bindOutputVariable(2, rOut2);
            bindOutputVariable(3, rOut3);
            bindInputVariable(0, rIn0);
        }

    private:
        static void execute(const AProcedureCallCCR& rCCR, AExecutableCCR::InstancesTable_t& rInstancesTable)
        {
            _CM_PREPARE_OUTPUT_VARIABLE(0);
            _CM_PREPARE_OUTPUT_VARIABLE(1);
            _CM_PREPARE_OUTPUT_VARIABLE(2);
            _CM_PREPARE_OUTPUT_VARIABLE(3);
            _CM_PREPARE_INPUT_VARIABLE(0);
            TSrcInstruction(rOut0, rOut1, rOut2, rOut3, rIn0);
        }
    };

#undef _CM_IMPL_PROCEDURE_CREATE_NEW_CCR
#undef _CM_PREPARE_INPUT_VARIABLE
#undef _CM_PREPARE_OUTPUT_VARIABLE
#undef _CM_EXECUTE_FUNCTION

}

#endif

#endif

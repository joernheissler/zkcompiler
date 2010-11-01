#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_OPERATOR_CALL_CCR_HPP
#define CM_A_OPERATOR_CALL_CCR_HPP

#include "ccr/AFunctionCallCCR.hpp"

namespace CodeManagement
{
    enum EOperator
    {
        o_undefined,

        // Arithmetic operators
        o_addition,
        o_subtracion,
        o_plus,
        o_minus,
        o_multiplication,
        o_division,
        o_modulo,

        // Comparison operators/Relational operators
        o_prefixIncrement,
        o_prefixDecrement,
        o_suffixIncrement,
        o_suffixDecrement,

        // Logical operators
        o_equalTo,
        o_notEqualTo,
        o_greaterThan,
        o_lessThan,
        o_greaterThanOrEqualTo,
        o_lessThanOrEqualTo,

        // Bitwise operators
        o_logicalNegation,
        // o_logicalAND,  // Not allowed, because of changing the control flow!
        // o_logicalOR,   // Not allowed, because of changing the control flow!

        //
        o_bitwiseNOT,
        o_bitwiseAND,
        o_bitwiseOR,
        o_bitwiseXOR,
        o_bitwiseLeftShift,
        o_bitwiseRightShift,

        // Compound-assignment operators
        o_additionAssign,
        o_subtractionAssign,
        o_multiplicationAssign,
        o_divisionAssign,
        o_moduloAssign,
        o_bitwiseANDAssign,
        o_bitwiseORAssign,
        o_bitwiseXORAssign,
        o_bitwiseLeftShiftAssign,
        o_bitwiseRightShiftAssign
    };

    class AOperatorCallCCR : public AFunctionCallCCR
    {
    public:
        typedef AFunctionCallCCR Base_t;
        typedef Base_t::InstancesTable_t InstancesTable_t;
        typedef void(*ExecuteFunc_t)(const AOperatorCallCCR&, AExecutableCCR::InstancesTable_t&, void*);
        typedef Base_t::Variables_t Variables_t;
        typedef Base_t::VariablesIter_t VariablesIter_t;
        typedef Base_t::VariablesConstIter_t VariablesConstIter_t;

    public:
        AOperatorCallCCR(ExecuteFunc_t executeFunc, const ASourceInstanceCaster* pReturnSrcInstCaster, bool hasReturnVar,
            const DebugInfo& rDebugInfo);

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual const char* getOperatorIdentifier() const = 0;
        virtual EOperator getOperatorEnum() const = 0;
    };
}

#endif

#endif

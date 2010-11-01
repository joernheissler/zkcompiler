#include <stdio.h>
#include "ccw/impl/Operator.hpp"

// FIXME: There are lots of warnings, but they are part of the test!
// The warnings should be disabled for this file independently of the used compiler...

typedef bool cm_bool_t;
typedef int cm_int_t;
typedef unsigned int cm_uint_t;
typedef short cm_short_t;
typedef long cm_long_t;
enum EnumType
{
    et_a = 1234,
    et_b = 4321
};

CMD_CODE_DEFINITIONS_BLOCK
{
    CMD_COPYABLE_TYPE(cm_bool_t)
    CMD_COPYABLE_TYPE(cm_int_t)
    CMD_COPYABLE_TYPE(cm_short_t)
    CMD_COPYABLE_TYPE(cm_long_t)
    CMD_COPYABLE_TYPE(EnumType)
}

CM_INIT_CODE_MANAGER;
CMO_USING_OPERATORS;

#define FAIL (printf("FAIL "), fail = true)
#define OK (printf("OK "), true)

#define TEST_CHECK(ccA, a) (CMV_OUT(ccA) == (a) && CMV_OUT((ccA) == CMV_IN(a)) ? OK : FAIL)

#define TEST_OPERATOR_BINARY(operName, operIdent, typeA, typeB, typeC, valA, valB) \
    printf("\n" #operName ": ");\
    {\
        typeA a = valA;\
        typeB b = valB;\
        typeC c1 = a operIdent typeA(b);\
        typeC c2 = (typeC)(a operIdent typeA(b));\
        CMV(typeA ccA);\
        CMV(typeB ccB);\
        CMV(typeC ccC1);\
        CMV(typeC ccC2);\
        ccA = CMV_IN(valA);\
        ccB = CMV_IN(valB);\
        ccC1 = ccA operIdent CMV::typeA(ccB);\
        ccC2 = CMV_CCAST(typeC, ccA operIdent CMV::typeA(ccB));\
        TEST_CHECK(ccA, a);\
        TEST_CHECK(ccB, b);\
        TEST_CHECK(ccC1, c1);\
        TEST_CHECK(ccC2, c2);\
    } (void)0
#define TEST_OPERATOR_UNARY_AND_PREFIX_MOD(operName, operIdent, typeA, typeB, valA) \
    printf("\n" #operName ": ");\
    {\
        typeA a = valA;\
        typeB b1 = operIdent a;\
        typeB b2 = (typeB)(operIdent a);\
        CMV(typeA ccA);\
        CMV(typeB ccB1);\
        CMV(typeB ccB2);\
        ccA = CMV_IN(valA);\
        ccB1 = operIdent ccA;\
        ccB2 = CMV_CCAST(typeB, operIdent ccA);\
        TEST_CHECK(ccA, a);\
        TEST_CHECK(ccB1, b1);\
        TEST_CHECK(ccB2, b2);\
    } (void)0
#define TEST_OPERATOR_SUFFIX_MOD(operName, operIdent, typeA, typeB, valA) \
    printf("\n" #operName ": ");\
    {\
        typeA a = valA;\
        typeB b1 = a operIdent;\
        typeB b2 = (typeB)(a operIdent);\
        CMV(typeA ccA);\
        CMV(typeB ccB1);\
        CMV(typeB ccB2);\
        ccA = CMV_IN(valA);\
        ccB1 = ccA operIdent;\
        ccB2 = CMV_CCAST(typeB, ccA operIdent);\
        TEST_CHECK(ccA, a);\
        TEST_CHECK(ccB1, b1);\
        TEST_CHECK(ccB2, b2);\
    } (void)0

CMV::EnumType testAsCopiedArguments(bool& fail, cm_short_t s, CMV::cm_short_t ccS, cm_long_t l, CMV::cm_long_t ccL, EnumType e, CMV::EnumType ccE)
{
    TEST_CHECK(ccS, s);
    TEST_CHECK(ccL, l);
    TEST_CHECK(ccE, e);
    return CMV_CCAST(EnumType, CMV::cm_long_t(ccS) + ccL - CMV::cm_long_t(ccE));
}

EnumType testAsCopiedArguments(cm_short_t s, cm_long_t l, EnumType e)
{
    return (EnumType)(l + s - e);
}

int main()
{
    bool fail = false;

    printf("variables as copied arguments in a function call: ");
    cm_short_t s = 12345;
    cm_long_t l = -235526;
    EnumType e = et_a;
    CMV(cm_short_t ccS);
    CMV(cm_long_t ccL);
    CMV(EnumType ccE);
    ccS = CMV_IN(12345);
    ccL = CMV_IN(-235526);
    ccE = CMV_IN(et_a);

    EnumType ret = testAsCopiedArguments(s, l, e);
    CMV(EnumType ccRet);
    ccRet = testAsCopiedArguments(fail, s, ccS, l, ccL, e, ccE);
    TEST_CHECK(ccRet, ret);

    ret = testAsCopiedArguments(e, s, (EnumType)l);
    ccRet = testAsCopiedArguments(fail, e, (CMV::cm_short_t)ccE, s, (CMV::cm_long_t)ccS, (EnumType)l, CMV_CCAST(EnumType, ccL));
    TEST_CHECK(ccRet, ret);

    // Arithmetic operators
    TEST_OPERATOR_BINARY(addition, +, cm_long_t, cm_short_t, cm_int_t, 45, -23);
    TEST_OPERATOR_BINARY(subtracion, -, cm_int_t, cm_long_t, cm_short_t, 235, 32);
    TEST_OPERATOR_BINARY(multiplication, *, cm_long_t, cm_long_t, cm_short_t, 665456, -2345);
    TEST_OPERATOR_BINARY(division, /, cm_short_t, cm_int_t, cm_short_t, 4578, 23456);
    TEST_OPERATOR_BINARY(modulo, %, cm_int_t, cm_long_t, cm_short_t, -22456, 765);
    TEST_OPERATOR_UNARY_AND_PREFIX_MOD(plus, +, cm_short_t, cm_long_t, 235456);
    TEST_OPERATOR_UNARY_AND_PREFIX_MOD(minus, -, cm_long_t, cm_short_t, -65872);
    TEST_OPERATOR_UNARY_AND_PREFIX_MOD(prefixIncrement, ++, cm_short_t, cm_long_t, 3324);
    TEST_OPERATOR_UNARY_AND_PREFIX_MOD(prefixDecrement, --, cm_long_t, cm_short_t, 345);
    TEST_OPERATOR_SUFFIX_MOD(suffixIncrement, ++, cm_int_t, cm_short_t, -572);
    TEST_OPERATOR_SUFFIX_MOD(suffixDecrement, --, cm_long_t, cm_short_t, 93492);

    // Comparison operators/Relational operators
    TEST_OPERATOR_BINARY(equalTo, ==, cm_long_t, cm_short_t, cm_bool_t, 34, -7257);
    TEST_OPERATOR_BINARY(notEqualTo, !=, cm_long_t, cm_long_t, cm_short_t, 3, 2533);
    TEST_OPERATOR_BINARY(greaterThan, >, cm_long_t, cm_short_t, cm_bool_t, 4265, -2523);
    TEST_OPERATOR_BINARY(lessThan, <, cm_long_t, cm_bool_t, cm_short_t, -42225, false);
    TEST_OPERATOR_BINARY(greaterThanOrEqualTo, >=, cm_int_t, cm_long_t, cm_bool_t, 45645, 223);
    TEST_OPERATOR_BINARY(lessThanOrEqualTo, <=, cm_short_t, cm_long_t, cm_int_t, -4757, 25343);

    // Logical operators
    TEST_OPERATOR_UNARY_AND_PREFIX_MOD(logicalNegation, !, cm_bool_t, cm_int_t, 34);

    // Bitwise operators
    TEST_OPERATOR_UNARY_AND_PREFIX_MOD(bitwiseNOT, ~, cm_int_t, cm_short_t, 34);
    TEST_OPERATOR_BINARY(bitwiseAND, &, cm_long_t, cm_long_t, cm_short_t, 36664, 4-67832);
    TEST_OPERATOR_BINARY(bitwiseOR, |, cm_long_t, cm_int_t, cm_short_t, -357, 4784334);
    TEST_OPERATOR_BINARY(bitwiseXOR, ^, cm_long_t, cm_long_t, cm_short_t, 1234, -632);
    TEST_OPERATOR_BINARY(bitwiseLeftShift, <<, cm_int_t, cm_int_t, cm_long_t, 3421, 3);
    TEST_OPERATOR_BINARY(bitwiseRightShift, >>, cm_long_t, cm_short_t, cm_long_t, -12355, 2);

    // Compound-assignment operators
    TEST_OPERATOR_BINARY(additionAssign, +=, cm_long_t, cm_int_t, cm_short_t, 5568934, -4784334);
    TEST_OPERATOR_BINARY(subtractionAssign, -=, cm_long_t, cm_int_t, cm_int_t, 578347, 462);
    TEST_OPERATOR_BINARY(multiplicationAssign, *=, cm_long_t, cm_int_t, cm_short_t, 23478, -4784334);
    TEST_OPERATOR_BINARY(divisionAssign, /=, cm_long_t, cm_int_t, cm_long_t, -2346787, 4784334);
    TEST_OPERATOR_BINARY(moduloAssign, %=, cm_short_t, cm_int_t, cm_short_t, 35379, 2599783);
    TEST_OPERATOR_BINARY(bitwiseANDAssign, &=, cm_long_t, cm_short_t, cm_long_t, -2599, 225899);
    TEST_OPERATOR_BINARY(bitwiseORAssign, |=, cm_long_t, cm_long_t, cm_short_t, 4835, 476);
    TEST_OPERATOR_BINARY(bitwiseXORAssign, ^=, cm_long_t, cm_short_t, cm_short_t, 7568, 44672);
    TEST_OPERATOR_BINARY(bitwiseLeftShiftAssign, <<=, cm_long_t, cm_long_t, cm_int_t, 23456253, -4);
    TEST_OPERATOR_BINARY(bitwiseRightShiftAssign, >>=, cm_long_t, cm_int_t, cm_short_t, 4346, 8);

    printf("\n");

    return fail ? 1 : 0;
}

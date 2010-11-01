#include <stdio.h>
#include <cstring>
#include "ccw/impl/Function.hpp"
#include "ccw/impl/Operator.hpp"
#include "ccw/impl/Procedure.hpp"

// FIXME: There are lots of warnings, but they are part of the test!
// The warnings should be disabled for this file independently of the used compiler...

CM_INIT_CODE_MANAGER;

#define FAIL (printf("FAIL\n"), fail = true)
#define OK (printf("OK\n"), true)

#define TEST_CHECK(msg, ccA, a) (printf("%s: ", (msg)), ((CMV_OUT(ccA) == (a) && CMV_OUT((ccA) == CMV_IN(a))) ? OK : FAIL))

struct SomeType
{
    SomeType(int i = 0) : _someNumber(i)
    {
//        printf("  Execute Construct: SomeType{%d}\n", _someNumber);
    }
    ~SomeType()
    {
//        printf("  Execute Destruct: SomeType{%d}\n", _someNumber);
    }
    SomeType(const SomeType& rToCopy) : _someNumber(rToCopy._someNumber)
    {
//        printf("  Execute Copy-Construct: SomeType{%d}\n", _someNumber);
    }
    SomeType& operator=(const SomeType& rRHS)
    {
//        printf("  Execute Copy-Assign: SomeType{%d} = SomeType{%d}\n", _someNumber, rRHS._someNumber);
        _someNumber = rRHS._someNumber;
        return *this;
    }
    bool operator==(const SomeType& rRHS) const
    {
//        printf("  Execute EqualTo: SomeType{%d} == SomeType{%d}\n", _someNumber, rRHS._someNumber);
        return _someNumber == rRHS._someNumber;
    }
    int _someNumber;
};

void someTypeSet(SomeType& rA, const SomeType& rB)
{
//    printf("  Execute Instruction: someTypeSet(%d,%d)\n", rA._someNumber, rB._someNumber);
    rA._someNumber = rB._someNumber;
}

SomeType someTypeAdd(const SomeType& rA, const SomeType& rB)
{
    int someNumber = rA._someNumber + rB._someNumber;
//    printf("  Execute Instruction: someTypeAdd(%d,%d)->%d\n", rA._someNumber, rB._someNumber, someNumber);
    return SomeType(someNumber);
}

void someTypeSetFromInt(SomeType& rA, int b)
{
//    printf("  Execute Instruction: someTypeSetFromInt(%d,%d)\n", rA._someNumber, b);
    rA._someNumber = b;
}

void someTypeSetFromStr(SomeType& rA, const char* pStr)
{
//    printf("  Execute Instruction: someTypeSetFromStr(%d,\"%s\")\n", rA._someNumber, pStr);

    int pow = 1;
    int r = 0;
    for (size_t i = strlen(pStr); i > 0; --i, pow *= 10)
        r += (pStr[i - 1] - '0') * pow;

    rA._someNumber = r;
}

class StaticClass
{
public:
    static int intSub(int a, int b)
    {
        int r = a - b;
//        printf("  Execute Instruction: StaticClass::intSub(%d,%d)->%d\n", a, b, r);
        return r;
    }
};

enum EnumType {et_a = 123, et_b = 321};
typedef bool cm_bool_t;
typedef int cm_int_t;
typedef short cm_short_t;
typedef const char* cm_pcchar_t;

CMD_CODE_DEFINITIONS_BLOCK
{
    CMD_COPYABLE_TYPE(SomeType)
    CMD_COPYABLE_TYPE(EnumType)
    CMD_COPYABLE_TYPE(cm_bool_t)
    CMD_COPYABLE_TYPE(cm_short_t)
    CMD_COPYABLE_TYPE(cm_int_t)
    CMD_COPYABLE_TYPE(cm_pcchar_t)

    CMD_PROCEDURE_o1i1(someTypeSet, SomeType, SomeType, const SomeType&)
    CMD_FUNCTION_i2(SomeType, someTypeAdd, SomeType, SomeType, const SomeType&, const SomeType&)
    CMD_FUNCTION_i2_sm(StaticClass, cm_int_t, intSub, cm_int_t, cm_int_t, cm_int_t, cm_int_t)
    CMD_PROCEDURE_o1i1(someTypeSetFromInt, SomeType, cm_int_t, cm_int_t)
    CMD_PROCEDURE_o1i1(someTypeSetFromStr, SomeType, cm_pcchar_t, cm_pcchar_t)
}

int main()
{
    CMO_USING_OPERATORS;

    bool fail = false;

    CMV::SomeType* pCCST = new CMV(SomeType);
    delete pCCST;

    CMV(SomeType ccSTA);
    CMV(SomeType ccSTB);
    CMV(SomeType ccSTR);
    ccSTA == CMV_IN(SomeType(1));
    SomeType st = 2;
    CMI(someTypeSet(ccSTA, CMV_IN(SomeType(1))));
    TEST_CHECK("init", ccSTA, SomeType(1));
    CMI(someTypeSet(ccSTB, CMV_IN(SomeType(st))));
    TEST_CHECK("init", ccSTB, SomeType(st));
    CMI(someTypeSet(ccSTR, ccSTA));
    TEST_CHECK("init", ccSTR, CMV_OUT(ccSTA));
    ccSTR = CMI(someTypeAdd(ccSTA, ccSTB));
    TEST_CHECK("someTypeAdd", ccSTR, someTypeAdd(CMV_OUT(ccSTA), CMV_OUT(ccSTB)));

    CMV(cm_int_t ccIA);
    CMV(cm_int_t ccIB);
    CMV(cm_int_t ccIR);

    ccIA = CMV_IN(1);
    TEST_CHECK("init", ccIA, 1);
    ccIB = CMV_IN(2);
    TEST_CHECK("init", ccIB, 2);
    ccIR = ccIA + -(ccIB += CMV_IN(-3));
    TEST_CHECK("expression", ccIA, 1);
    TEST_CHECK("expression", ccIB, -1);
    TEST_CHECK("expression", ccIR, 2);
    ccIR = ccIA + -ccIB;
    TEST_CHECK("expression", ccIR, 2);
    ccIR = -ccIA + ccIB;
    TEST_CHECK("expression", ccIR, -2);
    ccIR = CMI(StaticClass::intSub(ccIB, ccIR)) - ccIA;
    TEST_CHECK("StaticClass::intSub in expression", ccIR, 0);
    ++ccIR = ccIA;
    TEST_CHECK("expression", ccIR, 1);

    CMI(someTypeSetFromInt(ccSTA, ccIR));
    TEST_CHECK("someTypeSetFromInt", ccSTA, SomeType(1));
    CMI(someTypeSetFromInt(ccSTB, CMV_IN(13)));
    TEST_CHECK("someTypeSetFromInt", ccSTB, SomeType(13));

    CMV(cm_pcchar_t ccCCPA);
    ccCCPA = CMV_IN((cm_pcchar_t)"1234");
    CMI(someTypeSetFromStr(ccSTR, ccCCPA));
    TEST_CHECK("someTypeSetFromStr", ccSTR, SomeType(1234));

    ccIA = CMV_IN(et_a);
    CMV(EnumType ccET);
    ccET = CMV_IN(et_b);
    ccET = CMV_CCAST(EnumType, ccIA);
    TEST_CHECK("c-cast on var", ccET, et_a);
    ccET = CMI_CCAST(EnumType, StaticClass::intSub(ccIB, ccIR));
    TEST_CHECK("c-cast on func", ccET, -2);

    CMV(cm_short_t ccS);
    ccS = CMI(StaticClass::intSub(ccIB, ccIR)); // warning
    TEST_CHECK("impl-cast on func", ccS, -2);

    return fail ? 1 : 0;
}

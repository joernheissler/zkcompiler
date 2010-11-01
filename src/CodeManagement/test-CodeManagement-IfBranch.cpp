#include <stdio.h>
#include "ccw/impl/Operator.hpp"

// FIXME: There are lots of warnings, but they are part of the test!
// The warnings should be disabled for this file independently of the used compiler...

typedef bool cm_bool_t;
typedef int cm_int_t;

CMD_CODE_DEFINITIONS_BLOCK
{
    CMD_COPYABLE_TYPE(cm_bool_t)
    CMD_COPYABLE_TYPE(cm_int_t)
}

CM_INIT_CODE_MANAGER;
CMO_USING_OPERATORS;

#define FAIL (printf("FAIL\n"), fail = true)
#define OK (printf("OK\n"), true)

#define TEST_EXECUTION(execIdent, inExecutedCodeRegion) \
    (printf("execution %s check: ", (execIdent)), ((CMM_IS_EXECUTING == (inExecutedCodeRegion)) ? OK : FAIL))

CMV::cm_bool_t funcWithIfBranch(bool& fail, bool cond1, bool cond2,
                            bool testExec1, bool testExec2, bool testExec3,
                            bool& rVisited1, bool& rVisited2, bool& rVisited3,
                            CMV::cm_bool_t& rbVisited1, CMV::cm_bool_t& rbVisited2, CMV::cm_bool_t& rbVisited3)
{
    CMV(cm_bool_t bTrue); bTrue = CMV_IN(true);
    CMV(cm_bool_t bFalse); bFalse = CMV_IN(false);
    CMV(cm_bool_t result);
    CMM_IF(CMV_IN(cond1))
        TEST_EXECUTION("func", testExec1);
        rVisited1 = true;
        rbVisited1 = bTrue;
        result = bTrue;
    CMM_ELIF(CMV_IN(cond2))
        TEST_EXECUTION("func", testExec2);
        rVisited2 = true;
        rbVisited2 = bTrue;
        result = bTrue;
    CMM_ELSE
        TEST_EXECUTION("func", testExec3);
        rVisited3 = true;
        rbVisited3 = bTrue;
        result = bFalse;
    CMM_ENDIF
    return result;
}

int main()
{
    bool fail = false;

    CMV(cm_int_t iA); iA = CMV_IN(1234);
    CMV(cm_int_t i0); i0 = CMV_IN(0);
    CMV(cm_int_t i1); i1 = CMV_IN(1);
    CMV(cm_int_t i2); i2 = CMV_IN(2);
    CMV(cm_int_t i3); i3 = CMV_IN(3);
    CMV(cm_int_t i4); i4 = CMV_IN(4);

    CMV(cm_bool_t bTrue); bTrue = CMV_IN(true);
    CMV(cm_bool_t bFalse); bFalse = CMV_IN(false);


    CMV(cm_bool_t bVisited1); bVisited1 = bFalse;
    CMV(cm_bool_t bVisited2); bVisited2 = bFalse;
    CMV(cm_bool_t bVisited3); bVisited3 = bFalse;
    CMV(cm_bool_t bVisited4); bVisited4 = bFalse;
    CMV(cm_bool_t bVisited5); bVisited5 = bFalse;
    CMV(cm_bool_t bVisited6); bVisited6 = bFalse;
    CMV(cm_bool_t bVisited7); bVisited7 = bFalse;
    CMV(cm_bool_t bVisited8); bVisited8 = bFalse;
    CMV(cm_bool_t bVisited9); bVisited9 = bFalse;
    CMV(cm_bool_t bVisited10); bVisited10 = bFalse;
    CMV(cm_bool_t bVisited11); bVisited11 = bFalse;
    CMV(cm_bool_t bVisited12); bVisited12 = bFalse;
    CMV(cm_bool_t bVisited13); bVisited13 = bFalse;
    CMV(cm_bool_t bInFunc1Visited1); bInFunc1Visited1 = bFalse;
    CMV(cm_bool_t bInFunc1Visited2); bInFunc1Visited2 = bFalse;
    CMV(cm_bool_t bInFunc1Visited3); bInFunc1Visited3 = bFalse;
    CMV(cm_bool_t bInFunc2Visited1); bInFunc2Visited1 = bFalse;
    CMV(cm_bool_t bInFunc2Visited2); bInFunc2Visited2 = bFalse;
    CMV(cm_bool_t bInFunc2Visited3); bInFunc2Visited3 = bFalse;
    bool visited1 = false;
    bool visited2 = false;
    bool visited3 = false;
    bool visited4 = false;
    bool visited5 = false;
    bool visited6 = false;
    bool visited7 = false;
    bool visited8 = false;
    bool visited9 = false;
    bool visited10 = false;
    bool visited11 = false;
    bool visited12 = false;
    bool inFunc1Visited1 = false;
    bool inFunc1Visited2 = false;
    bool inFunc1Visited3 = false;
    bool inFunc2Visited1 = false;
    bool inFunc2Visited2 = false;
    bool inFunc2Visited3 = false;

    TEST_EXECUTION("0", true);

    CMM_IF(bTrue)
        TEST_EXECUTION("1", true);
        visited1 = true;
        bVisited1 = bTrue;
        CMM_IF(i2 * i2 == i3)
            TEST_EXECUTION("2", false);
            visited2 = true;
            bVisited2 = bTrue;
        CMM_ELIF(i3 - i2 == i4)
            TEST_EXECUTION("3", false);
            visited3 = true;
            bVisited3 = bTrue;
        CMM_ELIF(i1)
            TEST_EXECUTION("4", true);
            visited4 = true;
            bVisited4 = bTrue;
            CMM_IF(i0)
                TEST_EXECUTION("5", false);
                visited5 = true;
                bVisited5 = bTrue;
            CMM_ELSE
                CMM_IF(funcWithIfBranch(fail, false, true, false, true, false,
                        inFunc1Visited1, inFunc1Visited2, inFunc1Visited3,
                        bInFunc1Visited1, bInFunc1Visited2, bInFunc1Visited3))
                    TEST_EXECUTION("6", true);
                    visited6 = true;
                    bVisited6 = bTrue;
                    CMV(cm_int_t iA); iA = i4 - i3 * i2;
                    CMV(cm_bool_t bA); bA = (iA < CMV_IN(-1)) & (iA > CMV_IN(-3));
                    printf("inside branch check: ");
                    CMV_OUT(bA) && CMV_OUT(iA) == -2 ? OK : FAIL;
                CMM_ENDIF
            CMM_ENDIF
            TEST_EXECUTION("4b", true);
        CMM_ENDIF
        TEST_EXECUTION("1b", true);
    CMM_ELIF(bTrue)
        TEST_EXECUTION("7", false);
        visited7 = true;
        bVisited7 = bTrue;
        i1 = i0;
        CMM_IF(CMV_IN(false))
            TEST_EXECUTION("8", false);
            visited8 = true;
            bVisited8 = bTrue;
            iA = i4;
        CMM_ELSE
            TEST_EXECUTION("9", false);
            visited9 = true;
            bVisited9 = bTrue;
            CMM_IF(iA)
                TEST_EXECUTION("10", false);
                visited10 = true;
                bVisited10 = bTrue;
            CMM_ELIF(funcWithIfBranch(fail, true, false, false, false, false,
                    inFunc2Visited1, inFunc2Visited2, inFunc2Visited3,
                    bInFunc2Visited1, bInFunc2Visited2, bInFunc2Visited3))
            CMM_ELSE
                TEST_EXECUTION("11", false);
                i1 = i2 = i3 = i4;
                visited11 = true;
                bVisited11 = bTrue;
            CMM_ENDIF
            TEST_EXECUTION("9b", false);
        CMM_ENDIF
        TEST_EXECUTION("7b", false);
    CMM_ELSE
        TEST_EXECUTION("12", false);
        visited12 = true;
        bVisited12 = bTrue;
    CMM_ENDIF

    TEST_EXECUTION("0b", true);

    printf("after branch check iA: "); CMV_OUT(iA == CMV_IN(1234)) ? OK : FAIL;
    printf("after branch check i0: "); CMV_OUT(i0 == CMV_IN(0)) ? OK : FAIL;
    printf("after branch check i1: "); CMV_OUT(i1 == CMV_IN(1)) ? OK : FAIL;
    printf("after branch check i2: "); CMV_OUT(i2 == CMV_IN(2)) ? OK : FAIL;
    printf("after branch check i3: "); CMV_OUT(i3 == CMV_IN(3)) ? OK : FAIL;
    printf("after branch check i4: "); CMV_OUT(i4 == CMV_IN(4)) ? OK : FAIL;

#ifdef CM_ENABLE_CODE_COLLECTING
    printf("visit branch check 1: "); visited1 && CMV_OUT(bVisited1) ? OK : FAIL;
    printf("visit branch check 2: "); visited2 && CMV_OUT(!bVisited2) ? OK : FAIL;
    printf("visit branch check 3: "); visited3 && CMV_OUT(!bVisited3) ? OK : FAIL;
    printf("visit branch check 4: "); visited4 && CMV_OUT(bVisited4) ? OK : FAIL;
    printf("visit branch check 5: "); visited5 && CMV_OUT(!bVisited5) ? OK : FAIL;
    printf("visit branch check 6: "); visited6 && CMV_OUT(bVisited6) ? OK : FAIL;
    printf("visit branch check 7: "); visited7 && CMV_OUT(!bVisited7) ? OK : FAIL;
    printf("visit branch check 8: "); visited8 && CMV_OUT(!bVisited8) ? OK : FAIL;
    printf("visit branch check 9: "); visited9 && CMV_OUT(!bVisited9) ? OK : FAIL;
    printf("visit branch check 10: "); visited10 && CMV_OUT(!bVisited10) ? OK : FAIL;
    printf("visit branch check 11: "); visited11 && CMV_OUT(!bVisited11) ? OK : FAIL;
    printf("visit branch check 12: "); visited12 && CMV_OUT(!bVisited12) ? OK : FAIL;
    printf("visit branch in func1 check 1: "); inFunc1Visited1 && CMV_OUT(!bInFunc1Visited1) ? OK : FAIL;
    printf("visit branch in func1 check 2: "); inFunc1Visited2 && CMV_OUT(bInFunc1Visited2) ? OK : FAIL;
    printf("visit branch in func1 check 3: "); inFunc1Visited3 && CMV_OUT(!bInFunc1Visited3) ? OK : FAIL;
    printf("visit branch in func2 check 1: "); inFunc2Visited1 && CMV_OUT(!bInFunc2Visited1) ? OK : FAIL;
    printf("visit branch in func2 check 2: "); inFunc2Visited2 && CMV_OUT(!bInFunc2Visited2) ? OK : FAIL;
    printf("visit branch in func2 check 3: "); inFunc2Visited3 && CMV_OUT(!bInFunc2Visited3) ? OK : FAIL;
#else
    printf("visit branch check 1: "); visited1 && CMV_OUT(bVisited1) ? OK : FAIL;
    printf("visit branch check 2: "); !visited2 && CMV_OUT(!bVisited2) ? OK : FAIL;
    printf("visit branch check 3: "); !visited3 && CMV_OUT(!bVisited3) ? OK : FAIL;
    printf("visit branch check 4: "); visited4 && CMV_OUT(bVisited4) ? OK : FAIL;
    printf("visit branch check 5: "); !visited5 && CMV_OUT(!bVisited5) ? OK : FAIL;
    printf("visit branch check 6: "); visited6 && CMV_OUT(bVisited6) ? OK : FAIL;
    printf("visit branch check 7: "); !visited7 && CMV_OUT(!bVisited7) ? OK : FAIL;
    printf("visit branch check 8: "); !visited8 && CMV_OUT(!bVisited8) ? OK : FAIL;
    printf("visit branch check 9: "); !visited9 && CMV_OUT(!bVisited9) ? OK : FAIL;
    printf("visit branch check 10: "); !visited10 && CMV_OUT(!bVisited10) ? OK : FAIL;
    printf("visit branch check 11: "); !visited11 && CMV_OUT(!bVisited11) ? OK : FAIL;
    printf("visit branch check 12: "); !visited12 && CMV_OUT(!bVisited12) ? OK : FAIL;
    printf("visit branch in func1 check 1: "); !inFunc1Visited1 && CMV_OUT(!bInFunc1Visited1) ? OK : FAIL;
    printf("visit branch in func1 check 2: "); inFunc1Visited2 && CMV_OUT(bInFunc1Visited2) ? OK : FAIL;
    printf("visit branch in func1 check 3: "); !inFunc1Visited3 && CMV_OUT(!bInFunc1Visited3) ? OK : FAIL;
    printf("visit branch in func2 check 1: "); !inFunc2Visited1 && CMV_OUT(!bInFunc2Visited1) ? OK : FAIL;
    printf("visit branch in func2 check 2: "); !inFunc2Visited2 && CMV_OUT(!bInFunc2Visited2) ? OK : FAIL;
    printf("visit branch in func2 check 3: "); !inFunc2Visited3 && CMV_OUT(!bInFunc2Visited3) ? OK : FAIL;
#endif

    return fail ? 1 : 0;
}

/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsOffAfterCreate(void);
extern void test_IndividualLedOn(void);
extern void test_IndividualLedOff(void);
extern void test_MultipleLedsOnAndOff(void);
extern void test_AllLedsOn(void);
extern void test_AllLedsOff(void);
extern void test_LedStatus(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}
/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {

            setUp();
            func();

    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 26);
  run_test(test_IndividualLedOn, "test_IndividualLedOn", 33);
  run_test(test_IndividualLedOff, "test_IndividualLedOff", 40);
  run_test(test_MultipleLedsOnAndOff, "test_MultipleLedsOnAndOff", 48);
  run_test(test_AllLedsOn, "test_AllLedsOn", 56);
  run_test(test_AllLedsOff, "test_AllLedsOff", 64);
  run_test(test_LedStatus, "test_LedStatus", 73);

  return UnityEnd();
}

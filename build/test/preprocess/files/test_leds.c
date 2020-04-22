#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;



void setUp(void) {

    leds_Create(&ledsVirtuales);

}



void tearDown(void) {

}





void test_LedsOffAfterCreate(void){

    uint16_t ledsVirtuales = 0xFFFF;

    leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedOn(void){

    const uint8_t led = 3;

    leds_On(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (led - 1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedOff(void){

    const uint16_t led = 3;

    leds_On(led);

    leds_Off(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_MultipleLedsOnAndOff(void){

    leds_On(2);

    leds_On(5);

    leds_Off(2);

    UnityAssertEqualNumber((UNITY_INT)((1 << (5 - 1))), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}





void test_AllLedsOn(void){

    uint16_t i;

    for ( i = 0 ; i <= 16 ; ++i){

        leds_On(i);

    }

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);

}



void test_AllLedsOff(void){

    uint16_t i;

    for ( i = 0 ; i <= 16 ; ++i){

        leds_On(i);

        leds_Off(i);

    }

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}



void test_LedStatus(void){

    uint8_t led = 3;

    leds_On(led);

    leds_status(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX16);



}

/*
>Despues de la inicializacion, todos los leds deben qedar apagados
>Se puede prender un led individual
>Se puede apagar un led individual
>Se pueden prender y apagar multiples leds
>Se pueden prender todos los leds de una vez
>Se pueden apagar todos los leds de una vez
>Se puede consultar el estado de un led
*/

#include "unity.h"
#include "leds.h"

static uint16_t ledsVirtuales;

void setUp(void) {
    leds_Create(&ledsVirtuales);
}

void tearDown(void) {
}

//Despues de la inicializacion, todos los leds deben qedar apagados
void test_LedsOffAfterCreate(void){                 //Primer prueba
    uint16_t ledsVirtuales = 0xFFFF;                //emulo puerto GPIO
    leds_Create(&ledsVirtuales);                    //llamamos a la funcion con el puntero de la variable
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);      //HEX16 para asegurar que la comparacion sera en 16 bits
}

//Se puede prender un led individual
void test_IndividualLedOn(void){
    const uint8_t led = 3;
    leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), ledsVirtuales);
}

//Se puede apagar un led individual
void test_IndividualLedOff(void){
    const uint16_t led = 3;
    leds_On(led);
    leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

//Se pueden prender y apagar multiples leds
void test_MultipleLedsOnAndOff(void){
    leds_On(2);
    leds_On(5);
    leds_Off(2);
    TEST_ASSERT_EQUAL(1 << (5 - 1), ledsVirtuales);
}

//Se pueden prender todos los leds de una vez
void test_AllLedsOn(void){
    uint16_t i;
    for ( i = 0 ; i <= 16 ; ++i){
        leds_On(i);
    }
    TEST_ASSERT_EQUAL_HEX16(0xFF, ledsVirtuales);
}
//Se pueden apagar todos los leds de una vez
void test_AllLedsOff(void){
    uint16_t i;
    for ( i = 0 ; i <= 16 ; ++i){
        leds_On(i);
        leds_Off(i);
    }
    TEST_ASSERT_EQUAL(0, ledsVirtuales);
}
//Se puede consultar el estado de un led
void test_LedStatus(void){
    uint8_t led = 3;
    leds_On(led);
    leds_status(led);
    TEST_ASSERT_EQUAL_HEX16(1 , ledsVirtuales);
    //TEST_ASSERT_EQUAL(1 , leds_status(led));         // queria probar la misma funcion luego de prender un led y esta deberia darme 1
}
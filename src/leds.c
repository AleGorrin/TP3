#include "leds.h"

#define ALL_OFF 0
#define BIT_ON 1
#define LED_OFFSET 1

static uint16_t * leds;

uint8_t leds_Bits(uint8_t led){
    return (BIT_ON << (led -LED_OFFSET));
}

void leds_Create(uint16_t * direction){
    leds = direction;
    *leds = ALL_OFF;
}

void leds_On(uint8_t led){
    *leds |= leds_Bits(led);
}

void leds_Off(uint8_t led){
    *leds &= ~leds_Bits(led);
}


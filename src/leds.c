#include "leds.h"

#define ALL_OFF 0       //Constante para apagar todos los leds
#define BIT_ON 1        //Constante para fijar el primer bit en uno
#define LED_OFFSET 1    //Constante para convertir el numero de led en bit

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
void leds_status(uint8_t led){
    if (*leds = 1){
        return 1;
    }
    else{
        return 0;
    }
}
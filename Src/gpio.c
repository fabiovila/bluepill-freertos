
#include "gpio.h"
#include "main.h"

void Gpio (void) {




    // OutPut
    RCC->APB2ENR |= 0x10;
    GPIOC->CRH |= (OUT << 20);






}

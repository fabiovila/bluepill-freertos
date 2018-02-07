
#ifndef _GPIOH
#define _GPIOH

#define     OUT         0x02 //0010
#define     IN          0x20 //0100

// Atalhos
// Alguns compiladores já deslocam os bits em tempo de compilação - A verificar isto


#define     OffLED              GPIOC->ODR |= 1 << 13
#define     OnLED               GPIOC->ODR &= ~(1 << 13)
#define     ToogleLED           GPIOC->ODR ^= 1 << 13





void Gpio(void);

#endif

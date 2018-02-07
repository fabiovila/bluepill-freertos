#include "rtc.h"
#include "time.h"

void        SetEpoch(void) {

RTC->CRL |= RTC_CRL_CNF;
while((RTC->CRL & RTC_CRL_RTOFF) == 0);

RTC->CNTH = e >> 16;
RTC->CNTL = e & 0xffff;

RTC->CRL &= ~RTC_CRL_CNF;

while((RTC->CRL & RTC_CRL_RTOFF) == 0);

}

void        RTCInit (void){

RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;
PWR->CR |= PWR_CR_DBP;

RCC->BDCR |= RCC_BDCR_BDRST;
RCC->BDCR &= ~RCC_BDCR_BDRST;


RCC->BDCR |= RCC_BDCR_LSEON;


while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0);
RCC->BDCR |= RCC_BDCR_RTCSEL_LSE | RCC_BDCR_LSEBYP;
RCC->BDCR |= RCC_BDCR_RTCEN;
RTC->CRL  &= ~RTC_CRL_RSF;

while ((RTC->CRL & RTC_CRL_RSF) == 0);

RTC->CRL |= RTC_CRL_CNF;

while((RTC->CRL & RTC_CRL_RTOFF) == 0);

RTC->ALRH = 0;
RTC->ALRL = 0;
RTC->PRLH = 0;
RTC->PRLL = 0x7fff;                     // 8Mhz Crystal
RTC->CRH = RTC_CRH_SECIE;               // 1 Second Interrupt

RTC->CRL &= ~RTC_CRL_CNF;

while((RTC->CRL & RTC_CRL_RTOFF) == 0);
RTC->CRH = RTC_CRH_SECIE;
NVIC_ClearPendingIRQ(RTC_IRQn);
RTC->CRL = 0;
NVIC_EnableIRQ(RTC_IRQn);
}

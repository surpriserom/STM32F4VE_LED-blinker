
//prevent recursive inclusion
#ifndef __DELAY_H
#define __DELAY_H


//if c++ define as c structure
#ifdef __cplusplus
extern "C" {
#endif

//-------------- include lib ------------------------
#include "stm32f4xx_hal.h"

//-------------- define variable --------------------
#define NB_DELAY 10
static __IO uint32_t TimingDelay = 0;
static __IO uint32_t TimingDelay_tab[NB_DELAY];

//--------------- define function -------------------
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);

void TimingDelay_tab_Decrement(void);
void Set_timing_delay(__IO uint32_t delay_time, __IO uint8_t timer_id);
__IO uint32_t Get_timing_delay(__IO uint8_t timer_id);

// end if c++
#ifdef __cplusplus
}
#endif

//end if recursive inclusion
#endif

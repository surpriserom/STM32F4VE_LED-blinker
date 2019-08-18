/*
 * delay.c
 *
 *	Delay function used to add a delay between call
 *  and a counter decremented every 1ms, based on system tick interrupt
 *  a call to decrement function have to be init in stm32fxxx_it.c
 *  in SysTick_Handler function
 */


#include "delay.h"

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay > 0x00)
  {
    TimingDelay--;
  }
  else
  {
	  TimingDelay = 0x00;
  }
}

/**
  * @brief  Decrements each timer in the Timing delay tab - called from SysTick_Handler
  * @param  None
  * @retval None
  */
void TimingDelay_tab_Decrement(void)
{
	int cpt = 0;
	for(cpt=0; cpt < NB_DELAY; cpt++)
	{
		if (TimingDelay_tab[cpt] > 0x00)
		{
			TimingDelay_tab[cpt]--;
		}
		else
		{
			TimingDelay_tab[cpt] = 0x00;
		}
	}
}


/**
  * @brief  Set a delay counter in one of the TimingDelay_tab
  * @param  delay_time: specifies the delay time length, in milliseconds.
  * @param  timer_id: specifies the delay id that will store the counter for the timer should be between 0 and NB_DELAY
  * @retval None
  */
void Set_timing_delay(__IO uint32_t delay_time, __IO uint8_t timer_id)
{
	//check that id is in range
	if(timer_id < 0 || timer_id >= NB_DELAY)
	{
		return;
	}
	TimingDelay_tab[timer_id] = delay_time;
}

/**
  * @brief  Return the delay value from the requested TimingDelay_tab id
  * @param  timer_id: specifies the id of the TimingDelay_tab we wan't to read - should be between 0 and NB_DELAY
  * @retval uint32_t the value of the counter for the requested counter, remaning time in counter in millisecond
  */
__IO uint32_t Get_timing_delay(__IO uint8_t timer_id)
{
	//check that id is in range
	if(timer_id < 0 || timer_id >= NB_DELAY)
	{
		return 0;
	}
	return TimingDelay_tab[timer_id];

}

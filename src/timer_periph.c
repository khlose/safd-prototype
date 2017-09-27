/*
 * timer_periph.c
 *
 *  Created on: Sep 27, 2017
 *      Author: spinkoh
 */


#include "stm32f4xx.h"
#ifdef __cplusplus
extern "C" {
#endif
/* unfortunate globals because they get used in the ISR */
uint32_t TIM3COUNTER_Frequency = 2560;
/* determine the correct counter intervals */
uint16_t CCR1_Interval = TIM3COUNTER_Frequency / 8; // blue LED
uint16_t CCR2_Interval = TIM3COUNTER_Frequency / 4; // orange LED


void timer_interrupt_init (void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  RCC_ClocksTypeDef RCC_Clocks;
  /* Enable the timer global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init (&amp;NVIC_InitStructure);
}

uint32_t get_timer_clock_frequency (void)
{
  RCC_ClocksTypeDef RCC_Clocks;
  RCC_GetClocksFreq (&amp;RCC_Clocks);
  uint32_t multiplier;
  if (RCC_Clocks.PCLK1_Frequency == RCC_Clocks.SYSCLK_Frequency) {
    multiplier = 1;
  } else {
    multiplier = 2;
  }
  return multiplier * RCC_Clocks.PCLK1_Frequency;
}

void timer_clock_init (void)
{
  uint32_t TIM3CLK_Frequency = get_timer_clock_frequency();
  uint16_t prescaler = (TIM3CLK_Frequency / TIM3COUNTER_Frequency) - 1;
  /* allow the timer to wrap around naturally */
  uint16_t reload = 65535;

  /* make sure the peripheral is clocked */
  RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM3, ENABLE);
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  /* set everything back to default values */
  TIM_TimeBaseStructInit (&amp;TIM_TimeBaseStructure);
  /* only changes from the defaults are needed */
  TIM_TimeBaseStructure.TIM_Period = reload;
  TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
  TIM_TimeBaseInit (TIM3, &amp;TIM_TimeBaseStructure);
}

void timer_start (void)
{
  TIM_Cmd (TIM3, ENABLE);
}

void timer_stop (void)
{
  TIM_Cmd (TIM3, DISABLE);
}

void timer_interrupt_enable (void)
{
  /*
   * It is important to clear any pending interrupt flags since the timer
   * has been free-running since we last used it and that may generate
   * interrups on overflow even though the associated interrupt event has
   * not been enabled.
   */
  TIM_ClearITPendingBit (TIM3, TIM_IT_CC1 | TIM_IT_CC2);
  /* put the counter into a known state */
  //TIM_SetCounter (TIM3, 0);
  /* enable the interrupt for CC1 and CC2 only */
  TIM_ITConfig (TIM3, TIM_IT_CC1 | TIM_IT_CC2, ENABLE);
}

void TIM3_IRQHandler (void)
{
  /* run through the interrupt sources looking for a hit */
  if (TIM_GetITStatus (TIM3, TIM_IT_CC1) != RESET) {
    GPIO_ToggleBits (BLUE_LED);

    uint16_t CCR1_Current = TIM_GetCapture1 (TIM3);
    TIM_SetCompare1 (TIM3, CCR1_Current + CCR1_Interval);

    TIM_ClearITPendingBit (TIM3, TIM_IT_CC1);
  }
  if (TIM_GetITStatus (TIM3, TIM_IT_CC2) != RESET) {
    GPIO_ToggleBits (ORANGE_LED);

    uint16_t CCR2_Current = TIM_GetCapture2 (TIM3);
    TIM_SetCompare2 (TIM3, CCR2_Current + CCR2_Interval);

    TIM_ClearITPendingBit (TIM3, TIM_IT_CC2);
  }
}

#ifdef __cplusplus
}
#endif

void timer_ccr_init (void)
{
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  /* always initialise local variables before use */
  TIM_OCStructInit (&amp;TIM_OCInitStructure);
  /* just use basic Output Compare Mode*/
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Active;
  /* set the initial match interval for CC1 */
  TIM_OCInitStructure.TIM_Pulse = CCR1_Interval;
  TIM_OC1Init (TIM3, &amp;TIM_OCInitStructure);
  /* and then for CC2 */
  TIM_OCInitStructure.TIM_Pulse = CCR2_Interval;
  TIM_OC2Init (TIM3, &amp;TIM_OCInitStructure);
}

/*
// Enable GPIOB & TIM3 clocks
__HAL_RCC_GPIOB_CLK_ENABLE();
__HAL_RCC_TIM3_CLK_ENABLE();

// Set up GPIOB1 (timer 3, channel 4) in alternate function (AF) mode
GPIO_InitTypeDef GPIO_InitStruct;
GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
GPIO_InitStruct.Pull  = GPIO_PULLUP;
GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
GPIO_InitStruct.Pin   = GPIO_PIN_1;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

// Set up the counter itself.
TIM_Base_InitTypeDef TIM_BaseStruct;
TIM_HandleTypeDef TIM_HandleStruct;
TIM_HandleStruct.Instance = TIM3;

// No prescaler (PSC), so the count (CNT) will count up 64 million times per second
TIM_BaseStruct.Prescaler   = 0;
TIM_BaseStruct.CounterMode = TIM_COUNTERMODE_UP;

// When the counter hits the Period value, it will reset back to 0.
// This is the ARR register. In this case, the clock is 64mhz so:
//   64,000,000 / 842 / 2 = 38,005hz
// The divide by two is because it takes two toggles to create one wave
TIM_BaseStruct.Period = 842;

TIM_HandleStruct.Init    = TIM_BaseStruct;
TIM_HandleStruct.Channel = HAL_TIM_ACTIVE_CHANNEL_4;

// Initialize the timer hardware in output compare mode
HAL_TIM_OC_Init(&TIM_HandleStruct);

// Set the parameters for output compare
TIM_OC_InitTypeDef TIM_OCStruct;

// Toggle the associated pin when CNT >= CCR
TIM_OCStruct.OCMode = TIM_OCMODE_TOGGLE;

// This is the counter value when the the channel will be toggled
// For this simple case, the value here does not matter.
TIM_OCStruct.Pulse = 0;

// Configure the channel.
HAL_TIM_OC_ConfigChannel(&TIM_HandleStruct, &TIM_OCStruct, TIM_CHANNEL_4);

// Start the timer comparing
HAL_TIM_OC_Start(&TIM_HandleStruct, TIM_CHANNEL_4);

*/


/*
 * timer_periph.c
 *
 *  Created on: Sep 27, 2017
 *      Author: spinkoh
 */
//https://relicware.com/timer-interrupt-on-stm32f4-using-hal/

#include "stm32l4xx.h"
#include "timer_periph.h"
#include "stm32l476g_discovery.h"

void tmr3_init(uint16_t ps, uint16_t period)
{

	__TIM3_CLK_ENABLE();

	TIM_Base_InitTypeDef TIM_BaseStruct;

	//TIM_HandleTypeDef TIM_HandleStruct;




	TIM_BaseStruct.Prescaler = ps-1;
	TIM_BaseStruct.CounterMode = TIM_COUNTERMODE_UP;
	TIM_BaseStruct.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIM_BaseStruct.RepetitionCounter = 0;
	TIM_BaseStruct.Period = period -1;


	TIM_HandleStruct.Instance = TIM3;
	TIM_HandleStruct.Init = TIM_BaseStruct;
	TIM_HandleStruct.Channel = HAL_TIM_ACTIVE_CHANNEL_4;

	HAL_TIM_Base_Init(&TIM_HandleStruct);

	HAL_TIM_Base_Start_IT(&TIM_HandleStruct);
	HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);

}


void TIM3_IRQHandler(void)
{

	if (__HAL_TIM_GET_ITSTATUS(&TIM_HandleStruct, TIM_IT_UPDATE) != RESET)
	{
		__HAL_TIM_CLEAR_FLAG(&TIM_HandleStruct, TIM_FLAG_UPDATE);
		/*put your code here */
		BSP_LED_Toggle(LED_GREEN);
	}

}

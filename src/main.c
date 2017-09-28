/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l4xx.h"
#include "stm32l476g_discovery.h"
#include "stm32l476g_discovery_gyroscope.h"
#include "buffer.h"
#include "i2c.h"

void SystemClock_Config(void);
void Error_Handler(void);



int main(void)
{

	HAL_Init();
	SystemClock_Config();
	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);


	/* SPI Init Routine
	SpiHandle.Instance               = DISCOVERY_SPIx;
	SpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	SpiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
	SpiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
	SpiHandle.Init.CLKPolarity       = SPI_POLARITY_HIGH;
	SpiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLED;
	SpiHandle.Init.CRCPolynomial     = 7;
	SpiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
	SpiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
	SpiHandle.Init.NSS               = SPI_NSS_SOFT;
	SpiHandle.Init.TIMode            = SPI_TIMODE_DISABLED;
	SpiHandle.Init.Mode = SPI_MODE_MASTER;
	 */


	/*Try out joystick*/
	BSP_JOY_Init(JOY_MODE_GPIO);
	JOYState_TypeDef joyState;


	/*Initialize gyroscope for angular velocity measurement*/
	uint8_t gyroRet;
	gyroRet = BSP_GYRO_Init();


	/*in mdeg/sec*/
	//float gyroRead1[3] = {0,0,0};
	//float gyroRead2[3] = {0,0,0};


	/*TIM3 timer set up*/
	//tmr3_init(670,62498);

	/*Using I2C*/
	I2C1_Init();

	HAL_StatusTypeDef readStat;

	uint8_t pBuffer[2] = {0};

	while(1)
	{

		//I2C2 READ WRITE HERE

		/*
		if(gyroRet == GYRO_OK) BSP_GYRO_GetXYZ(gyroRead1);
		if(gyroRet == GYRO_OK) BSP_GYRO_GetXYZ(gyroRead2);
		 */

		readStat = I2C1_ReadBuffer(0b01101010,0x0F,8,pBuffer,8);




		/*Use joystick to debug: Just for fun*/

		joyState = BSP_JOY_GetState();
		if(joyState == JOY_UP)	BSP_LED_Off(LED_GREEN);
		if(joyState == JOY_DOWN)	BSP_LED_On(LED_GREEN);
	}
}


void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 48;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV4;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

  __PWR_CLK_ENABLE();

  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  HAL_RCCEx_EnableMSIPLLMode();

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}



void Error_Handler(void)
{
  /* Turn LED5 (RED) on and stay here */
  BSP_LED_On(LED_RED);
  while(1)
  {
  }
}

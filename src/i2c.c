/*
 * i2c.c
 *
 *  Created on: Sep 28, 2017
 *      Author: Station13
 */
#include "i2c.h"

/**
 * @brief BUS variables
 */
#if defined(HAL_I2C_MODULE_ENABLED)
static I2C_HandleTypeDef I2c1Handle;
#endif /* HAL_I2C_MODULE_ENABLED */

void I2C1_Init_Mod(I2C_HandleTypeDef* I2c1Handle)
{
  if(HAL_I2C_GetState(&I2c1Handle) == HAL_I2C_STATE_RESET)
  {
    I2c1Handle->Instance              = DISCOVERY_I2C1;
    I2c1Handle->Init.Timing           = DISCOVERY_I2C1_TIMING;
    I2c1Handle->Init.OwnAddress1      = 0;
    I2c1Handle->Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
    I2c1Handle->Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
    I2c1Handle->Init.OwnAddress2      = 0;
    I2c1Handle->Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
    I2c1Handle->Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;

    /* Init the I2C */
    I2C1_MspInit(I2c1Handle);
    HAL_I2C_Init(I2c1Handle);
  }
}

/**
  * @brief Discovery I2C1 MSP Initialization
  * @param hi2c: I2C handle
  * @retval None
  */
void I2C1_MspInit(I2C_HandleTypeDef *hi2c)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_PeriphCLKInitTypeDef  RCC_PeriphCLKInitStruct;

  /* IOSV bit MUST be set to access GPIO port G[2:15] */
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWREx_EnableVddIO2();

  if (hi2c->Instance == DISCOVERY_I2C1)
  {
    /*##-1- Configure the Discovery I2C clock source. The clock is derived from the SYSCLK #*/
    RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
    RCC_PeriphCLKInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
    HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);

    /*##-2- Configure the GPIOs ################################################*/
    /* Enable GPIO clock */
    DISCOVERY_I2C1_SDA_GPIO_CLK_ENABLE();
    DISCOVERY_I2C1_SCL_GPIO_CLK_ENABLE();

    /* Configure I2C Rx/Tx as alternate function  */
    GPIO_InitStructure.Pin       = DISCOVERY_I2C1_SCL_PIN | DISCOVERY_I2C1_SDA_PIN;
    GPIO_InitStructure.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStructure.Pull      = GPIO_PULLUP;
    GPIO_InitStructure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStructure.Alternate = DISCOVERY_I2C1_SCL_SDA_AF;
    HAL_GPIO_Init(DISCOVERY_I2C1_SCL_GPIO_PORT, &GPIO_InitStructure);

    /*##-3- Configure the Discovery I2C1 peripheral #######################################*/
    /* Enable Discovery I2C1 clock */
    DISCOVERY_I2C1_CLK_ENABLE();

    /* Force and release the I2C Peripheral Clock Reset */
    DISCOVERY_I2C1_FORCE_RESET();
    DISCOVERY_I2C1_RELEASE_RESET();

    /* Enable and set Discovery I2C1 Interrupt to the highest priority */
    HAL_NVIC_SetPriority(DISCOVERY_I2C1_EV_IRQn, 0x00, 0);
    HAL_NVIC_EnableIRQ(DISCOVERY_I2C1_EV_IRQn);

    /* Enable and set Discovery I2C1 Interrupt to the highest priority */
    HAL_NVIC_SetPriority(DISCOVERY_I2C1_ER_IRQn, 0x00, 0);
    HAL_NVIC_EnableIRQ(DISCOVERY_I2C1_ER_IRQn);
  }
}

/**
  * @brief Discovery I2C1 Bus Deitialization
  * @retval None
  */
void I2C1_DeInit(void)
{
  if(HAL_I2C_GetState(&I2c1Handle) != HAL_I2C_STATE_RESET)
  {
    /* Deinit the I2C */
    HAL_I2C_DeInit(&I2c1Handle);
    I2C1_MspDeInit(&I2c1Handle);
  }
}

/**
  * @brief Discovery I2C1 MSP Deinitialization
  * @param hi2c: I2C handle
  * @retval None
  */
void I2C1_MspDeInit(I2C_HandleTypeDef *hi2c)
{
  if(hi2c->Instance == DISCOVERY_I2C1)
  {
    /*##-1- Unconfigure the GPIOs ################################################*/
    /* Enable GPIO clock */
    DISCOVERY_I2C1_SDA_GPIO_CLK_ENABLE();
    DISCOVERY_I2C1_SCL_GPIO_CLK_ENABLE();

    /* Deinit Rx/Tx pins */
    HAL_GPIO_DeInit(DISCOVERY_I2C1_SCL_GPIO_PORT, (DISCOVERY_I2C1_SCL_PIN | DISCOVERY_I2C1_SDA_PIN));

    /*##-2- Unconfigure the Discovery I2C1 peripheral ############################*/
    /* Force & Release the I2C Peripheral Clock Reset */
    DISCOVERY_I2C1_FORCE_RESET();
    DISCOVERY_I2C1_RELEASE_RESET();

    /* Disable Discovery I2C1 clock */
    DISCOVERY_I2C1_CLK_DISABLE();

    /* Disable Discovery I2C1 interrupts */
    HAL_NVIC_DisableIRQ(DISCOVERY_I2C1_EV_IRQn);
    HAL_NVIC_DisableIRQ(DISCOVERY_I2C1_ER_IRQn);

    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWREx_DisableVddIO2();
  }
}

/**
  * @brief  Write a value in a register of the device through BUS.
  * @param  Addr: Device address on BUS Bus.
  * @param  Reg: The target register address to write
  * @param  RegSize: The target register size (can be 8BIT or 16BIT)
  * @param  pBuffer: The target register value to be written
  * @param  Length: buffer size to be written
  * @retval None
  */
HAL_StatusTypeDef I2C1_WriteBuffer(uint16_t Addr, uint16_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_I2C_Mem_Write(&I2c1Handle, Addr, (uint16_t)Reg, RegSize, pBuffer, Length, DISCOVERY_I2C2_TIMEOUT_MAX);

/* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the BUS */
    I2C1_Error();
  }
  return status;
}

/**
  * @brief  Reads multiple data on the BUS.
  * @param  Addr: I2C Address
  * @param  Reg: Reg Address
  * @param  RegSize : The target register size (can be 8BIT or 16BIT)
  * @param  pBuffer: pointer to read data buffer
  * @param  Length: length of the data
  * @retval 0 if no problems to read multiple data
  */
HAL_StatusTypeDef I2C1_ReadBuffer(uint16_t Addr, uint16_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_I2C_Mem_Read(&I2c1Handle, Addr, (uint16_t)Reg, RegSize, pBuffer, Length, DISCOVERY_I2C2_TIMEOUT_MAX);

/* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initiaize the BUS */
    I2C1_Error();
  }
  return status;
}

/**
  * @brief Discovery I2C1 error treatment function
  * @retval None
  */
void I2C1_Error (void)
{
  /* De-initialize the I2C communication BUS */
  HAL_I2C_DeInit(&I2c1Handle);

  /* Re- Initiaize the I2C communication BUS */
  I2C1_Init();
}

/*
 * i2c.h
 *
 *  Created on: Sep 28, 2017
 *      Author: Schwin Pinkoh
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32l4xx.h"
#include "stm32l476g_discovery.h"


typedef enum
{
	I2C_Normal = 0x00,
	I2C_Busy
}I2C_ProtocolStateTypedef;


void I2C1_Init(void);
void I2C1_MspInit(I2C_HandleTypeDef *hi2c);
void I2C1_DeInit(I2C_HandleTypeDef* I2c1Handle);
void I2C1_MspDeInit(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef I2C1_WriteBuffer(uint16_t Addr, uint16_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length);
HAL_StatusTypeDef I2C1_ReadBuffer(uint16_t Addr, uint16_t Reg, uint16_t RegSize, uint8_t *pBuffer, uint16_t Length);

void I2C1_Error (void);


#endif /* I2C_H_ */

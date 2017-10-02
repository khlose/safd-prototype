/*
 * lsm6ds3.c
 *
 *  Created on: Oct 2, 2017
 *      Author: Schwin Pinkoh
 */

#include "lsm6ds3.h"


LSM6DS3_StatusTypedef init_accelerometer(I2C_HandleTypeDef *hi2c,uint8_t sensor_no, LSM6DS3_SensitivityTypedef sensitivity,LSM6DS3_DataRateTypedef data_rate)
{
	HAL_StatusTypeDef wStat;

	/*Acc X, Y, Z axes enabled*/
	uint8_t wData = ACC_XYZ_EN;
	wStat = HAL_I2C_Mem_Write(hi2c,sensor_no,CTRL9_XL,I2C_MEMADD_SIZE_8BIT,&wData,1,1000);

	if(wStat != HAL_OK)
		return LSM6DS3_ERROR;

	/*Acc performance select*/
	wData = sensitivity | data_rate;

	/*Selecting Anti Aliasing filter based on data rate*/
	switch(data_rate)
	{
		case rate12hz:
		case rate26hz:
		case rate52hz:
		case rate104hz:
			wData |= 0x03;
		break;

		case rate208hz:
			wData |= 0x02;
		break;

		case rate416hz:
			wData |= 0x01;
		break;

		case rate833hz:
		case rate1_66khz:
			wData |= 0x00;
		break;

		/*Filter not used for 3.33-6.66kHzs*/
		default:
			wData |= 0x00;
	}
	wStat = HAL_I2C_Mem_Write(hi2c,sensor_no,CTRL1_XL,I2C_MEMADD_SIZE_8BIT,&wData,1,1000);
	if(wStat != HAL_OK)
			return LSM6DS3_ERROR;
	/* Acc Data Ready interrupt on INT1*/
	wData = 0x01;
	wStat = HAL_I2C_Mem_Write(hi2c,sensor_no,INT1_CTRL,I2C_MEMADD_SIZE_8BIT,&wData,1,1000); // Do we need this???
	if(wStat != HAL_OK)
			return LSM6DS3_ERROR;

	return LSM6DS3_OK;
}

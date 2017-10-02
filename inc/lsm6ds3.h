/*
 * lsm6ds3.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Schwin Pinkoh
 */
#include "stm32l4xx.h"
#ifndef LSM6DS3_H_
#define LSM6DS3_H_

#define CTRL9_XL                 ((uint8_t)0x18)            /*!< CTRL9_XL register address */
#define CTRL1_XL                 ((uint8_t)0x10)            /*!< CTRL1_XL register address */
#define INT1_CTRL                ((uint8_t)0x0D)            /*!< INT1_CTRL register address */
#define ACC_XYZ_EN				 ((uint8_t)0x38)			/*!< Enable xyz acc data - bit3,4,5*/
#define INTERRUPT_INT1			 ((uint8_t)0x01)			/*!< Acc Data ready interrupt on INT1*/
#define SENSOR_1				 ((uint8_t)0x6B<<1)			/*!< Sensor No.1 (SDO/SA0 - Supply Voltage)*/
#define SENSOR_2				 ((uint8_t)0x6A<<1)			/*!< Sensor No.2 (SDO/SA0 - GND)*/

typedef enum
{
	sensitivity_2g = 0x00,
	sensitivity_4g = 0x08,
	sensitivity_8g = 0x0C,
	sensitivity_16g = 0x04
}LSM6DS3_SensitivityTypedef;

typedef enum
{
	power_down = 0x00,
	rate12hz = 0x10,
	rate26hz = 0x20,
	rate52hz = 0x30,
	rate104hz = 0x40,
	rate208hz = 0x50,
	rate416hz = 0x60,
	rate833hz = 0x70,
	rate1_66khz = 0x80,
	rate3_33khz = 0x90,
	rate6_66khz = 0xA0
}LSM6DS3_DataRateTypedef;

typedef enum
{
	LSM6DS3_OK = 0x00,
	LSM6DS3_ERROR = 0x01
}LSM6DS3_StatusTypedef;

LSM6DS3_StatusTypedef init_accelerometer(I2C_HandleTypeDef *hi2c, uint8_t sensor_no,LSM6DS3_SensitivityTypedef sensitivity, LSM6DS3_DataRateTypedef data_rate);


#endif /* LSM6DS3_H_ */

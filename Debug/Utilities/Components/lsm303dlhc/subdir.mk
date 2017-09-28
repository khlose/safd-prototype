################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/lsm303dlhc/lsm303dlhc.c 

OBJS += \
./Utilities/Components/lsm303dlhc/lsm303dlhc.o 

C_DEPS += \
./Utilities/Components/lsm303dlhc/lsm303dlhc.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/lsm303dlhc/%.o: ../Utilities/Components/lsm303dlhc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32L476VGTx -DSTM32L4 -DSTM32L476G_DISCO -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Station13/Documents/GitHub/safd-prototype/inc" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/CMSIS/core" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/CMSIS/device" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/HAL_Driver/Inc/Legacy" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/HAL_Driver/Inc" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/Common" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/cs42l51" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/cs43l22" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/ft6x06" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/hx8347g" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/l3gd20" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/ls016b8uy" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/lsm303c" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/lsm303dlhc" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/mfxstm32l152" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/mx25r6435f" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/n25q128a" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/n25q256a" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/ov9655" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/st7735" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/st7789h2" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/stmpe1600" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/stmpe811" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/wm8994" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/STM32L476G-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



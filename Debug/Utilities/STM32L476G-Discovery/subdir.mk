################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery.c \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery_audio.c \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery_compass.c \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery_glass_lcd.c \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.c \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery_idd.c \
../Utilities/STM32L476G-Discovery/stm32l476g_discovery_qspi.c 

OBJS += \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery.o \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_audio.o \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_compass.o \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_glass_lcd.o \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.o \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_idd.o \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_qspi.o 

C_DEPS += \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery.d \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_audio.d \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_compass.d \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_glass_lcd.d \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_gyroscope.d \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_idd.d \
./Utilities/STM32L476G-Discovery/stm32l476g_discovery_qspi.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32L476G-Discovery/%.o: ../Utilities/STM32L476G-Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32L476VGTx -DSTM32L4 -DSTM32L476G_DISCO -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/inc" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/CMSIS/core" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/CMSIS/device" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/HAL_Driver/Inc/Legacy" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/HAL_Driver/Inc" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/Common" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/cs42l51" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/cs43l22" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/ft6x06" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/hx8347g" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/l3gd20" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/ls016b8uy" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/lsm303c" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/lsm303dlhc" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/mfxstm32l152" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/mx25r6435f" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/n25q128a" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/n25q256a" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/ov9655" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/st7735" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/st7789h2" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/stmpe1600" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/stmpe811" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/Components/wm8994" -I"C:/Users/spinkoh/Documents/GitHub/eclipse-workspace/prototype/Utilities/STM32L476G-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



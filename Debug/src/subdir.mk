################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Trace.c \
../src/buffer.c \
../src/fall_detection.c \
../src/i2c.c \
../src/lsm6ds3.c \
../src/main.c \
../src/stm32l4xx_it.c \
../src/syscalls.c \
../src/system_stm32l4xx.c \
../src/timer_periph.c \
../src/trace_impl.c 

OBJS += \
./src/Trace.o \
./src/buffer.o \
./src/fall_detection.o \
./src/i2c.o \
./src/lsm6ds3.o \
./src/main.o \
./src/stm32l4xx_it.o \
./src/syscalls.o \
./src/system_stm32l4xx.o \
./src/timer_periph.o \
./src/trace_impl.o 

C_DEPS += \
./src/Trace.d \
./src/buffer.d \
./src/fall_detection.d \
./src/i2c.d \
./src/lsm6ds3.d \
./src/main.d \
./src/stm32l4xx_it.d \
./src/syscalls.d \
./src/system_stm32l4xx.d \
./src/timer_periph.d \
./src/trace_impl.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32L476VGTx -DSTM32L4 -DSTM32L476G_DISCO -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/Station13/Documents/GitHub/safd-prototype/inc" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/CMSIS/core" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/CMSIS/device" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/HAL_Driver/Inc/Legacy" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/HAL_Driver/Inc" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/Common" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/cs42l51" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/cs43l22" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/ft6x06" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/hx8347g" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/l3gd20" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/ls016b8uy" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/lsm303c" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/lsm303dlhc" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/mfxstm32l152" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/mx25r6435f" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/n25q128a" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/n25q256a" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/ov9655" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/st7735" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/st7789h2" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/stmpe1600" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/stmpe811" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/Components/wm8994" -I"C:/Users/Station13/Documents/GitHub/safd-prototype/Utilities/STM32L476G-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



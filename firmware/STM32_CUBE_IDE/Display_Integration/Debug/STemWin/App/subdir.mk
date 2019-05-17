################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STemWin/App/FramewinDLG.c 

OBJS += \
./STemWin/App/FramewinDLG.o 

C_DEPS += \
./STemWin/App/FramewinDLG.d 


# Each subdirectory must supply rules for building sources it contributes
STemWin/App/FramewinDLG.o: ../STemWin/App/FramewinDLG.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -c -I../Middlewares/ST/STemWin/inc -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/BSP/Components/otm8009a -I../Drivers/BSP/Components/Common -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STemWin/App/FramewinDLG.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Drivers/BSP/Components/otm8009a/otm8009a.c 

OBJS += \
./Drivers/Components/otm8009a/otm8009a.o 

C_DEPS += \
./Drivers/Components/otm8009a/otm8009a.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Components/otm8009a/otm8009a.o: /Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Drivers/BSP/Components/otm8009a/otm8009a.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -c -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FatFs/src -I../Inc -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Include -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FreeRTOS/Source/include -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I/Users/christiansager/STM32Cube/Repository/STM32Cube_FW_F4_V1.24.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Components/otm8009a/otm8009a.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


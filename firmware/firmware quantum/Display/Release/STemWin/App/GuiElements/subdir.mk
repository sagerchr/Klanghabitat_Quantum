################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STemWin/App/GuiElements/AudioMeter.c \
../STemWin/App/GuiElements/Controlls.c 

OBJS += \
./STemWin/App/GuiElements/AudioMeter.o \
./STemWin/App/GuiElements/Controlls.o 

C_DEPS += \
./STemWin/App/GuiElements/AudioMeter.d \
./STemWin/App/GuiElements/Controlls.d 


# Each subdirectory must supply rules for building sources it contributes
STemWin/App/GuiElements/AudioMeter.o: ../STemWin/App/GuiElements/AudioMeter.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../STemWin/Target -I../STemWin/App -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/BSP/Components/otm8009a -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/ST/STemWin/inc -I../Drivers/BSP/Components/Common -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"STemWin/App/GuiElements/AudioMeter.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
STemWin/App/GuiElements/Controlls.o: ../STemWin/App/GuiElements/Controlls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../STemWin/Target -I../STemWin/App -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/BSP/Components/otm8009a -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/ST/STemWin/inc -I../Drivers/BSP/Components/Common -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"STemWin/App/GuiElements/Controlls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


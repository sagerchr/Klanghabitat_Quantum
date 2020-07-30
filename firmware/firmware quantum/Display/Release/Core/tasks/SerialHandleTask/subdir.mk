################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/tasks/SerialHandleTask/SerialHandleTask.c \
../Core/tasks/SerialHandleTask/UART_IO.c 

OBJS += \
./Core/tasks/SerialHandleTask/SerialHandleTask.o \
./Core/tasks/SerialHandleTask/UART_IO.o 

C_DEPS += \
./Core/tasks/SerialHandleTask/SerialHandleTask.d \
./Core/tasks/SerialHandleTask/UART_IO.d 


# Each subdirectory must supply rules for building sources it contributes
Core/tasks/SerialHandleTask/SerialHandleTask.o: ../Core/tasks/SerialHandleTask/SerialHandleTask.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../STemWin/Target -I../STemWin/App -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/BSP/Components/otm8009a -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/ST/STemWin/inc -I../Drivers/BSP/Components/Common -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Core/tasks/SerialHandleTask/SerialHandleTask.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/tasks/SerialHandleTask/UART_IO.o: ../Core/tasks/SerialHandleTask/UART_IO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../STemWin/Target -I../STemWin/App -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/BSP/Components/otm8009a -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/ST/STemWin/inc -I../Drivers/BSP/Components/Common -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Core/tasks/SerialHandleTask/UART_IO.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


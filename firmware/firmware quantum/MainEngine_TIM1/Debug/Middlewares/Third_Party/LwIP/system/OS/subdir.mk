################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LwIP/system/OS/sys_arch.c 

OBJS += \
./Middlewares/Third_Party/LwIP/system/OS/sys_arch.o 

C_DEPS += \
./Middlewares/Third_Party/LwIP/system/OS/sys_arch.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LwIP/system/OS/sys_arch.o: ../Middlewares/Third_Party/LwIP/system/OS/sys_arch.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DDEBUG -c -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/Third_Party/LwIP/src/include -I../LWIP/App -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Core/Inc -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Drivers/CMSIS/Include -I../LWIP/Target -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/apps/http -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngine_TIM1/Drivers/DSP/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngine_TIM1/Core/Functions/inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngine_TIM1/Core/Tasks/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Third_Party/LwIP/system/OS/sys_arch.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

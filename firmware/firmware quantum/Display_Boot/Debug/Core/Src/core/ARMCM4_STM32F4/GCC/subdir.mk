################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/GCC/cpu_comp.c 

OBJS += \
./Core/Src/core/ARMCM4_STM32F4/GCC/cpu_comp.o 

C_DEPS += \
./Core/Src/core/ARMCM4_STM32F4/GCC/cpu_comp.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/core/ARMCM4_STM32F4/GCC/cpu_comp.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/GCC/cpu_comp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/BSP/Components" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/BSP/STM32469I-Discovery" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Fonts" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/GCC/cpu_comp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

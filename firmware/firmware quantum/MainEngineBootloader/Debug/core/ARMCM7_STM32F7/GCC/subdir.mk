################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/GCC/cpu_comp.c 

OBJS += \
./core/ARMCM7_STM32F7/GCC/cpu_comp.o 

C_DEPS += \
./core/ARMCM7_STM32F7/GCC/cpu_comp.d 


# Each subdirectory must supply rules for building sources it contributes
core/ARMCM7_STM32F7/GCC/cpu_comp.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/GCC/cpu_comp.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MainEngineBootloader/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/GCC/cpu_comp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


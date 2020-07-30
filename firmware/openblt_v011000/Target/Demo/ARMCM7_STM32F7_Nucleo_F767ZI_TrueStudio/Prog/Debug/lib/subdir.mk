################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/system_stm32f7xx.c 

OBJS += \
./lib/system_stm32f7xx.o 

C_DEPS += \
./lib/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
lib/system_stm32f7xx.o: ../lib/system_stm32f7xx.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/lib/uip" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lib/system_stm32f7xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


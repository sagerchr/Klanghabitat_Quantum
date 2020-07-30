################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc/dhcpc.c 

OBJS += \
./core/third_party/uip/apps/dhcpc/dhcpc.o 

C_DEPS += \
./core/third_party/uip/apps/dhcpc/dhcpc.d 


# Each subdirectory must supply rules for building sources it contributes
core/third_party/uip/apps/dhcpc/dhcpc.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc/dhcpc.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/third_party/uip/apps/dhcpc/dhcpc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


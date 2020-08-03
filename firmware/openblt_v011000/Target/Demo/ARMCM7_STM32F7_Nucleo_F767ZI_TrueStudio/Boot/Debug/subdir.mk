################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup_stm32f767xx.s 

C_SRCS += \
../hooks.c \
../led.c \
../main.c \
../shared_params.c 

OBJS += \
./hooks.o \
./led.o \
./main.o \
./shared_params.o \
./startup_stm32f767xx.o 

S_DEPS += \
./startup_stm32f767xx.d 

C_DEPS += \
./hooks.d \
./led.d \
./main.d \
./shared_params.d 


# Each subdirectory must supply rules for building sources it contributes
hooks.o: ../hooks.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"hooks.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
led.o: ../led.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"led.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
main.o: ../main.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
shared_params.o: ../shared_params.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"shared_params.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
startup_stm32f767xx.o: ../startup_stm32f767xx.s
	arm-none-eabi-gcc -c -mcpu=cortex-m7 -g3 -c -Wa,-W -x assembler-with-cpp -MMD -MP -MF"startup_stm32f767xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"


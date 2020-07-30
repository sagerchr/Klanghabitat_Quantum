################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/can.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/cpu.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/flash.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/nvm.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/rs232.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/timer.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/usb.c 

OBJS += \
./core/ARMCM7_STM32F7/can.o \
./core/ARMCM7_STM32F7/cpu.o \
./core/ARMCM7_STM32F7/flash.o \
./core/ARMCM7_STM32F7/nvm.o \
./core/ARMCM7_STM32F7/rs232.o \
./core/ARMCM7_STM32F7/timer.o \
./core/ARMCM7_STM32F7/usb.o 

C_DEPS += \
./core/ARMCM7_STM32F7/can.d \
./core/ARMCM7_STM32F7/cpu.d \
./core/ARMCM7_STM32F7/flash.d \
./core/ARMCM7_STM32F7/nvm.d \
./core/ARMCM7_STM32F7/rs232.d \
./core/ARMCM7_STM32F7/timer.d \
./core/ARMCM7_STM32F7/usb.d 


# Each subdirectory must supply rules for building sources it contributes
core/ARMCM7_STM32F7/can.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/can.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/can.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
core/ARMCM7_STM32F7/cpu.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/cpu.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/cpu.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
core/ARMCM7_STM32F7/flash.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/flash.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
core/ARMCM7_STM32F7/nvm.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/nvm.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/nvm.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
core/ARMCM7_STM32F7/rs232.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/rs232.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/rs232.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
core/ARMCM7_STM32F7/timer.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/timer.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
core/ARMCM7_STM32F7/usb.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7/usb.c
	arm-none-eabi-gcc -c "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_FULL_LL_DRIVER '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Boot/lib/uip" -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/uip -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/third_party/uip/apps/dhcpc -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM7_STM32F7 -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"core/ARMCM7_STM32F7/usb.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


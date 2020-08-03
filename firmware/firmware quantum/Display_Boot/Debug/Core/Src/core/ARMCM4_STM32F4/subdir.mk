################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/can.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/cpu.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/flash.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/nvm.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/rs232.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/timer.c \
/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/usb.c 

OBJS += \
./Core/Src/core/ARMCM4_STM32F4/can.o \
./Core/Src/core/ARMCM4_STM32F4/cpu.o \
./Core/Src/core/ARMCM4_STM32F4/flash.o \
./Core/Src/core/ARMCM4_STM32F4/nvm.o \
./Core/Src/core/ARMCM4_STM32F4/rs232.o \
./Core/Src/core/ARMCM4_STM32F4/timer.o \
./Core/Src/core/ARMCM4_STM32F4/usb.o 

C_DEPS += \
./Core/Src/core/ARMCM4_STM32F4/can.d \
./Core/Src/core/ARMCM4_STM32F4/cpu.d \
./Core/Src/core/ARMCM4_STM32F4/flash.d \
./Core/Src/core/ARMCM4_STM32F4/nvm.d \
./Core/Src/core/ARMCM4_STM32F4/rs232.d \
./Core/Src/core/ARMCM4_STM32F4/timer.d \
./Core/Src/core/ARMCM4_STM32F4/usb.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/core/ARMCM4_STM32F4/can.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/can.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/can.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/core/ARMCM4_STM32F4/cpu.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/cpu.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/cpu.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/core/ARMCM4_STM32F4/flash.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/core/ARMCM4_STM32F4/nvm.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/nvm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/nvm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/core/ARMCM4_STM32F4/rs232.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/rs232.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/rs232.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/core/ARMCM4_STM32F4/timer.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/core/ARMCM4_STM32F4/usb.o: /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4/usb.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source -I/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Source/ARMCM4_STM32F4 -I"/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display_Boot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/core/ARMCM4_STM32F4/usb.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


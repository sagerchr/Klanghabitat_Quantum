################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/gcc/startup_stm32f769xx.s 

C_SRCS += \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_audio.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_lcd.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_qspi.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sdram.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/wm8994_Modified.c 

OBJS += \
./Board/startup_stm32f769xx.o \
./Board/stm32f769i_discovery.o \
./Board/stm32f769i_discovery_audio.o \
./Board/stm32f769i_discovery_lcd.o \
./Board/stm32f769i_discovery_qspi.o \
./Board/stm32f769i_discovery_sdram.o \
./Board/system_stm32f7xx.o \
./Board/wm8994_Modified.o 

C_DEPS += \
./Board/stm32f769i_discovery.d \
./Board/stm32f769i_discovery_audio.d \
./Board/stm32f769i_discovery_lcd.d \
./Board/stm32f769i_discovery_qspi.d \
./Board/stm32f769i_discovery_sdram.d \
./Board/system_stm32f7xx.d \
./Board/wm8994_Modified.d 


# Each subdirectory must supply rules for building sources it contributes
Board/startup_stm32f769xx.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/gcc/startup_stm32f769xx.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/stm32f769i_discovery.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/stm32f769i_discovery.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/stm32f769i_discovery_audio.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_audio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/stm32f769i_discovery_audio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/stm32f769i_discovery_lcd.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_lcd.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/stm32f769i_discovery_lcd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/stm32f769i_discovery_qspi.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_qspi.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/stm32f769i_discovery_qspi.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/stm32f769i_discovery_sdram.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sdram.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/stm32f769i_discovery_sdram.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/system_stm32f7xx.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/system_stm32f7xx.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Board/wm8994_Modified.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/wm8994_Modified.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"Board/wm8994_Modified.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



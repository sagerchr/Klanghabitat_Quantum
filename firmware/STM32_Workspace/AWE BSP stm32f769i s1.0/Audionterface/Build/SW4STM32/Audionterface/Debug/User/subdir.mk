################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/AudioDriver.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/BoardSetup.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/ControlDriver.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/GPIO.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/Platform.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/TuningDriver.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/USBDescriptors.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/main.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/stm32f7xx_hal_msp.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/stm32f7xx_it.c 

OBJS += \
./User/AudioDriver.o \
./User/BoardSetup.o \
./User/ControlDriver.o \
./User/GPIO.o \
./User/Platform.o \
./User/TuningDriver.o \
./User/USBDescriptors.o \
./User/main.o \
./User/stm32f7xx_hal_msp.o \
./User/stm32f7xx_it.o 

C_DEPS += \
./User/AudioDriver.d \
./User/BoardSetup.d \
./User/ControlDriver.d \
./User/GPIO.d \
./User/Platform.d \
./User/TuningDriver.d \
./User/USBDescriptors.d \
./User/main.d \
./User/stm32f7xx_hal_msp.d \
./User/stm32f7xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
User/AudioDriver.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/AudioDriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/AudioDriver.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/BoardSetup.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/BoardSetup.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/BoardSetup.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/ControlDriver.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/ControlDriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/ControlDriver.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/GPIO.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/GPIO.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/GPIO.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/Platform.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/Platform.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/Platform.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/TuningDriver.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/TuningDriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/TuningDriver.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/USBDescriptors.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/USBDescriptors.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/USBDescriptors.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/main.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/stm32f7xx_hal_msp.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/stm32f7xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/stm32f7xx_hal_msp.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/stm32f7xx_it.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/stm32f7xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O0 -g -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"User/stm32f7xx_it.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



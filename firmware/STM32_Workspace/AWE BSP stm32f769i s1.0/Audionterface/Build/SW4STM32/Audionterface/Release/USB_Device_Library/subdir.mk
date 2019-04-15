################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_audio.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_audio_if.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_conf.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_ctlreq.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_desc.c \
C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./USB_Device_Library/usbd_audio.o \
./USB_Device_Library/usbd_audio_if.o \
./USB_Device_Library/usbd_conf.o \
./USB_Device_Library/usbd_core.o \
./USB_Device_Library/usbd_ctlreq.o \
./USB_Device_Library/usbd_desc.o \
./USB_Device_Library/usbd_ioreq.o 

C_DEPS += \
./USB_Device_Library/usbd_audio.d \
./USB_Device_Library/usbd_audio_if.d \
./USB_Device_Library/usbd_conf.d \
./USB_Device_Library/usbd_core.d \
./USB_Device_Library/usbd_ctlreq.d \
./USB_Device_Library/usbd_desc.d \
./USB_Device_Library/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
USB_Device_Library/usbd_audio.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_audio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_audio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_Device_Library/usbd_audio_if.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_audio_if.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_audio_if.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_Device_Library/usbd_conf.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_conf.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_conf.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_Device_Library/usbd_core.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_core.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_Device_Library/usbd_ctlreq.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_ctlreq.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_ctlreq.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_Device_Library/usbd_desc.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Source/usbd_desc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_desc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_Device_Library/usbd_ioreq.o: C:/DSP\ Concepts/AWE\ BSP\ stm32f769i\ s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_GPIO -DUSE_HAL_DRIVER -DHID_INTERFACE -DSTM32F769xx -DEXTERNMODULETABLE -DUSE_USB_HS -DUSE_IOEXPANDER -DPROFILE_TIMES -DCORE_M7 -DDSPC_CORTEX_M -DARM_MATH_CM7 -D__FPU_PRESENT -DUSE_FLASH_FILE_SYSTEM -DNDEBUG -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Source" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Lib/AWEInclude/Modules" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Vendor/Drivers/BSP/STM32F769I-Discovery"  -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"USB_Device_Library/usbd_ioreq.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



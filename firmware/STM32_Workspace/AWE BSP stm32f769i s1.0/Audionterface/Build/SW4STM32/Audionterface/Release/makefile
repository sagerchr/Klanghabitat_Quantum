################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include USB_Device_Library/subdir.mk
-include STM32F7xx_HAL_Driver/subdir.mk
-include Board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: STM32F769i_Discovery.elf

# Tool invocations
STM32F769i_Discovery.elf: $(OBJS) $(USER_OBJS) C:\DSP\ Concepts\AWE\ BSP\ stm32f769i\ s1.0\STM32F769i_Discovery\Build\SW4STM32\STM32F769i_Discovery/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -L"C:\DSP Concepts\AWE BSP stm32f769i s1.0\STM32F769i_Discovery\Lib\AWELibs\SW4STM32" -L"C:\DSP Concepts\AWE BSP stm32f769i s1.0\STM32F769i_Discovery\Lib\STLibs\SW4STM32" -L../../../../Lib/VendorLibs/SW4STM32 -L"C:\DSP Concepts\AWE BSP stm32f769i s1.0\STM32F769i_Discovery\Vendor\Drivers\CMSIS\Lib\GCC"  -specs=nosys.specs -specs=nano.specs -specs=rdimon.specs -lrdimon -T"C:/DSP Concepts/AWE BSP stm32f769i s1.0/STM32F769i_Discovery/Build/SW4STM32/STM32F769i_Discovery/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "STM32F769i_Discovery.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -R .sdram -R .dtcmram -O binary "STM32F769i_Discovery.elf" "STM32F769i_Discovery.bin"
	arm-none-eabi-size -B "STM32F769i_Discovery.elf"  & arm-none-eabi-objdump -D "STM32F769i_Discovery.elf" > "STM32F769i_Discovery.lst" & cscript -nologo ../renamefile.js "STM32F769i_Discovery.bin" "STM32F769i_Discovery_SW4STM32.bin" & cscript -nologo ../copyfile.js "STM32F769i_Discovery_SW4STM32.bin" "../../../../Bin/"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

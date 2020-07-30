################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include third_party/uip/uip/subdir.mk
-include third_party/uip/apps/dhcpc/subdir.mk
-include lib/uip/subdir.mk
-include lib/STM32F7xx_HAL_Driver/Src/subdir.mk
-include lib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
demoprog_stm32f767.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
demoprog_stm32f767.list \

OBJCOPY_BIN += \
demoprog_stm32f767.bin \

OBJCOPY_SREC += \
demoprog_stm32f767.srec \


# All Target
all: demoprog_stm32f767.elf secondary-outputs

# Tool invocations
demoprog_stm32f767.elf: $(OBJS) $(USER_OBJS) /Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/STM32F767ZI_FLASH.ld
	arm-none-eabi-gcc -o "demoprog_stm32f767.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"/Users/christiansager/klanghabitat_quantum/firmware/openblt_v011000/Target/Demo/ARMCM7_STM32F7_Nucleo_F767ZI_TrueStudio/Prog/STM32F767ZI_FLASH.ld" --specs=nosys.specs -Wl,-Map="Prog.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

demoprog_stm32f767.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "demoprog_stm32f767.list"
	@echo 'Finished building: $@'
	@echo ' '

demoprog_stm32f767.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "demoprog_stm32f767.bin"
	@echo 'Finished building: $@'
	@echo ' '

demoprog_stm32f767.srec: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "demoprog_stm32f767.srec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN) $(OBJCOPY_SREC)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

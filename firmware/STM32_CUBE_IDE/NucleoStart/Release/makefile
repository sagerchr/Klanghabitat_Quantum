################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
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
NucleoStart.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NucleoStart.list \


# All Target
all: NucleoStart.elf secondary-outputs

# Tool invocations
NucleoStart.elf: $(OBJS) $(USER_OBJS) /Users/christiansager/Documents/Klanghabitat_Quantum/firmware/STM32_CUBE_IDE/NucleoStart/STM32F103RBTX_FLASH.ld
	arm-none-eabi-gcc -o "NucleoStart.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"/Users/christiansager/Documents/Klanghabitat_Quantum/firmware/STM32_CUBE_IDE/NucleoStart/STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NucleoStart.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NucleoStart.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NucleoStart.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

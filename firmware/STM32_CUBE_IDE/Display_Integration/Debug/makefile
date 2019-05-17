################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STemWin/App/subdir.mk
-include Middlewares/ST/STemWin/Software/subdir.mk
-include Middlewares/ST/STemWin/OS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/Components/otm8009a/subdir.mk
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
Display_Integration.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Display_Integration.list \


# All Target
all: Display_Integration.elf secondary-outputs

# Tool invocations
Display_Integration.elf: $(OBJS) $(USER_OBJS) C:\klanghabitat_quantum\firmware\STM32_CUBE_IDE\Display_Integration\STM32F469NIHX_FLASH.ld
	arm-none-eabi-gcc -o "Display_Integration.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\klanghabitat_quantum\firmware\STM32_CUBE_IDE\Display_Integration\STM32F469NIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Display_Integration.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Display_Integration.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Display_Integration.list"
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

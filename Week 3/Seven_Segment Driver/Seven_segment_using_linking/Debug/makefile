################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/Seven_Segment_Driver/subdir.mk
-include HAL/SWITCH_Driver/subdir.mk
-include HAL/LED_Driver/subdir.mk
-include APPs/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Seven_segment.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Seven_segment.elf secondary-outputs

# Tool invocations
Seven_segment.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Seven_segment.map -mmcu=atmega32 -o "Seven_segment.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Seven_segment.lss: Seven_segment.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Seven_segment.elf  >"Seven_segment.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Seven_segment.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Seven_segment.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Seven_segment.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

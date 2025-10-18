################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app.c \
../external_interrupts.c \
../gpio.c \
../led.c \
../main.c \
../timer1.c 

OBJS += \
./app.o \
./external_interrupts.o \
./gpio.o \
./led.o \
./main.o \
./timer1.o 

C_DEPS += \
./app.d \
./external_interrupts.d \
./gpio.d \
./led.d \
./main.d \
./timer1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FAN.c \
../LDR.c \
../LED.c \
../PWM.c \
../Smart_Home.c \
../adc.c \
../buzzer.c \
../flameSensor.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c 

OBJS += \
./FAN.o \
./LDR.o \
./LED.o \
./PWM.o \
./Smart_Home.o \
./adc.o \
./buzzer.o \
./flameSensor.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o 

C_DEPS += \
./FAN.d \
./LDR.d \
./LED.d \
./PWM.d \
./Smart_Home.d \
./adc.d \
./buzzer.d \
./flameSensor.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



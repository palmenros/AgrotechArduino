################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\lib\HX711-master\HX711.cpp 

LINK_OBJ += \
.\HX711-master\HX711.cpp.o 

CPP_DEPS += \
.\HX711-master\HX711.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
HX711-master\HX711.cpp.o: B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master\HX711.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '



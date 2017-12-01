################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\Agrotech.ino 

CPP_SRCS += \
..\.ino.cpp \
..\Feeder.cpp \
..\Ultrasonic.cpp \
..\Ventilation.cpp \
..\WaterTrough.cpp 

LINK_OBJ += \
.\.ino.cpp.o \
.\Feeder.cpp.o \
.\Ultrasonic.cpp.o \
.\Ventilation.cpp.o \
.\WaterTrough.cpp.o 

INO_DEPS += \
.\Agrotech.ino.d 

CPP_DEPS += \
.\.ino.cpp.d \
.\Feeder.cpp.d \
.\Ultrasonic.cpp.d \
.\Ventilation.cpp.d \
.\WaterTrough.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
.ino.cpp.o: ..\.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -I"B:\Users\Pedro\Documents\Arduino\libraries\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Agrotech.o: ..\Agrotech.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -I"B:\Users\Pedro\Documents\Arduino\libraries\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Feeder.cpp.o: ..\Feeder.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -I"B:\Users\Pedro\Documents\Arduino\libraries\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Ultrasonic.cpp.o: ..\Ultrasonic.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -I"B:\Users\Pedro\Documents\Arduino\libraries\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Ventilation.cpp.o: ..\Ventilation.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -I"B:\Users\Pedro\Documents\Arduino\libraries\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

WaterTrough.cpp.o: ..\WaterTrough.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"B:\Program Files\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"B:\Program Files\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"B:\Users\Pedro\Documents\sloeber-workspace\Agrotech\lib\HX711-master" -I"B:\Users\Pedro\Documents\Arduino\libraries\HX711-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '



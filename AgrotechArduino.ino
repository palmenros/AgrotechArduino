#include "Arduino.h"
#include "Communication.h"
#include "Feeder.h"
#include "Ventilation.h"
#include "Lightning.h"
#include "Alarm.h"
#include "Ultrasonic.h"
#include "WaterTrough.h"


byte buffer[5];

/*
 * Custom classes driving actuators with sensors information
 */
Feeder feeder(A1, A0, 9);					//SENSOR 0x0
Ventilation ventilation(10, A2);			//SENSOR 0x1
Lightning lightning(3, A5);					//SENSOR 0x2
WaterTrough waterTrough(1, 11, 12);			//SENSOR 0x3

/*Waste ultrasonic sensor*/
Ultrasonic ultrasonic(7, 6);				//SENSOR 0x4

/* Flame sensor Digital Output PIN*/
int flameSensor = 8;						//SENSOR 0x5

/*
 *  PIR Sensor Digital Output PIN
 *  Very important, set your PIR Sensor to only trigger once until some time passes
 */
int PIRSensor = 5;							//SENSOR 0x6

/* Height in cm of waste container */
float wasteContainerHeight = 10.5;

/* Number of milliseconds since program started */
unsigned long elapsedTime = 0;

void setup()
{
  Communication::init();
  Alarm::init(2);

  /* This may take some time in order to calibrate the load cell*/
  feeder.setup();
  ventilation.setup();
  lightning.setup();
  waterTrough.setup();

  pinMode(flameSensor, INPUT);
  pinMode(PIRSensor, INPUT);
}

void handleInput()
{
	if(Serial.available() < 5)
	{
		return;
	}

	Serial.readBytes(buffer, 5);

	byte actuator = (buffer[0] & 0xf0) >> 4;
	bool automatic = buffer[0] & 0x0f;

	bool refill = true;
	uint32_t input = 0;

	if(actuator > 2)
	{
		refill = buffer[1] != 0;
	} else {
		//Read Little Endian float
		input |= uint32_t(buffer[1]);
		input |= uint32_t(buffer[2]) << 8;
		input |= uint32_t(buffer[3]) << 16;
		input |= uint32_t(buffer[4]) << 24;
	}

	float value = *((float*)&input);

	switch(actuator) {
	case 0:
		lightning.setAutomatic(automatic);
		if(!automatic) lightning.setLightsBrightness(value / 100.f);
		break;
	case 1:
		ventilation.setAutomatic(automatic);
		if(!automatic) ventilation.setVentilatorSpeed(value / 100.f);
		break;
	case 2:
		feeder.setAutomatic(automatic);
		if(!automatic) feeder.switchMotor(refill);
		break;
	case 3:
		waterTrough.setAutomatic(automatic);
		if(!automatic) waterTrough.switchPump(refill);
		break;
	}

}

void loop()
{
	unsigned long newTime = millis();
	float deltaTime = (newTime - elapsedTime) / 1000.f;
	elapsedTime = newTime;

	handleInput();

	lightning.loop();
	feeder.loop();
	ventilation.loop();
	waterTrough.loop();

	/* Send waste level */
	Communication::sendSensorData(0x4, (wasteContainerHeight - ultrasonic.read()) / wasteContainerHeight);
  
    /* Flame Sensor */
	bool flameDetected = !digitalRead(flameSensor);
	Communication::sendSensorData(0x5, flameDetected);
	if(flameDetected)
	{
		Alarm::on();
		Alarm::setTimeout(15.f);
	}

	/* PIR Sensor */
	bool PIRValue = digitalRead(PIRSensor);
	Communication::sendSensorData(0x6, PIRValue);

	Alarm::loop(deltaTime);
}

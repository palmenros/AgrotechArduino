/*
 * Ventilation.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "Ventilation.h"
#include "Arduino.h"
#include "Communication.h"

Ventilation::Ventilation(int fanPin, int LM35Pin)
	: fanPin(fanPin), LM35Pin(LM35Pin)
{
}


/* Import the symbols from Lightning.cpp */
/* TODO: Stop being lazy and create a dedicated math class */
float mapf(float x, float inMin, float inMax, float outMin, float outMax);
float clamp(float x, float min, float max);


void Ventilation::setup()
{
	pinMode(fanPin, OUTPUT);
	pinMode(LM35Pin, INPUT);
}

void Ventilation::loop()
{
	float temperature = getTemperature();
	Communication::sendSensorData(0x1, temperature);

	if(!isAutomatic())
	{
		return;
	}

	float speed = mapf(temperature, 15, 30, 0, 1);
	speed = clamp(speed, 0, 1);

	setVentilatorSpeed(speed);
}

float Ventilation::getTemperature()
{
	float mV = (analogRead(LM35Pin) / 1023.f) * 5000;
	return mV / 10.f;
}

void Ventilation::setVentilatorSpeed(float percentage)
{
	analogWrite(fanPin, percentage * 255);
}

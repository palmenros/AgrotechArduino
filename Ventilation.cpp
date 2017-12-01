/*
 * Ventilation.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "Ventilation.h"
#include "Arduino.h"

Ventilation::Ventilation(int fanPin, int LM35Pin)
	: fanPin(fanPin), LM35Pin(LM35Pin)
{
}

void Ventilation::setup()
{
	pinMode(fanPin, OUTPUT);
	pinMode(LM35Pin, INPUT);
}

void Ventilation::loop()
{
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

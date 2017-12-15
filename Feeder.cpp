/*
 * Feeder.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "Arduino.h"
#include "Feeder.h"
#include "Communication.h"

Feeder::Feeder(int DOUTPin, int CLKPin, int motorPin)
	: motorPin(motorPin), loadCell(DOUTPin, CLKPin)
{
}

void Feeder::setup()
{
	pinMode(motorPin, OUTPUT);
	loadCell.set_scale();
	loadCell.tare(20);
}

void Feeder::loop()
{
	float weight = getWeight();

	Communication::sendSensorData(0x0, weight);

	if(!isAutomatic())
	{
		return;
	}

	if(motorState)
	{
		if(weight >= fillWeight) {
			switchMotor(false);
		}
	} else {
		if(weight <= minThreshold) {
			switchMotor(true);
		}
	}
}

void Feeder::switchMotor(bool state)
{
	digitalWrite(motorPin, state);
	motorState = state;
}

float Feeder::getWeight()
{
	//HACK: Our load cell amplifier circuit HX711 broke, so we had to add a magic number
	//Do *NOT* add this to any functional HX711
	return loadCell.get_value(10) / 1000.f;
}

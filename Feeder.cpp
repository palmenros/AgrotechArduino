/*
 * Feeder.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "Arduino.h"
#include "Feeder.h"

Feeder::Feeder(int DOUTPin, int CLKPin, int motorPin)
	: loadCell(DOUTPin, CLKPin), motorPin(motorPin)
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
	return loadCell.get_value(10);
}

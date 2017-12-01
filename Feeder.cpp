/*
 * Feeder.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "Feeder.h"

Feeder::Feeder()
	: loadCell(DOUTPin, CLKPin)
{
}

void Feeder::setup()
{
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

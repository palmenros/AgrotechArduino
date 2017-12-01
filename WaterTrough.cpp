/*
 * WaterTrough.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "WaterTrough.h"
#include "Arduino.h"

WaterTrough::WaterTrough(int triggerPin, int echoPin, int pumpPin)
	: ultrasonic(triggerPin, echoPin), pumpPin(pumpPin)
{
}

void WaterTrough::setup()
{
	pinMode(pumpPin, OUTPUT);
}

void WaterTrough::loop()
{
	float height = getWaterHeight();
	if(pumpState)
	{
		if(height >= fillHeight)
		{
			switchPump(false);
		}
	} else {
		if(height <= minThreshold)
		{
			switchPump(true);
		}
	}
}

float WaterTrough::getWaterHeight()
{
	return sensorHeight - ultrasonic.getDistance();
}

void WaterTrough::switchPump(bool state)
{
	digitalWrite(pumpPin, state);
	pumpState = state;
}

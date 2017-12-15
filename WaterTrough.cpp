/*
 * WaterTrough.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "WaterTrough.h"
#include "Arduino.h"
#include "Communication.h"

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
	float percentage = (fillHeight - height) / fillHeight;
	Communication::sendSensorData(0x3, percentage);

	if(!isAutomatic())
	{
		return;
	}

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
	return sensorHeight - ultrasonic.read();
}

void WaterTrough::switchPump(bool state)
{
	digitalWrite(pumpPin, state);
	pumpState = state;
}

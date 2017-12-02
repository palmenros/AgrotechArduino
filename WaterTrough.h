/*
 * WaterTrough.h
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#ifndef WATERTROUGH_H_
#define WATERTROUGH_H_

#include "Ultrasonic.h"
#include "AutomatedModule.h"

class WaterTrough : public AutomatedModule
{
protected:

	const int pumpPin;

	/* Ultrasonic sensor */

	Ultrasonic ultrasonic;

	const int sensorHeight;
	const int minThreshold;
	const int fillHeight;

	bool pumpState = false;

public:

	WaterTrough(int triggerPin, int echoPin, int pumpPin);

	void setup();

	void loop();

	float getWaterHeight();

	void switchPump(bool state);

};

#endif /* WATERTROUGH_H_ */

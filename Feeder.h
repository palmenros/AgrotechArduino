/*
 * Feeder.h
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */
#include "HX711.h"
#include "AutomatedModule.h"

#ifndef FEEDER_H_
#define FEEDER_H_

class Feeder : public AutomatedModule
{
protected:

	const int motorPin;

	/* Load cell */

	const float fillWeight = 120.f;
	const float minThreshold = 50.f;

	HX711 loadCell;

	bool motorState = false;

public:

	Feeder(int DOUTPin, int CLKPin, int motorPin);

	void setup();
	void loop();

	void switchMotor(bool state);
	float getWeight();
};

#endif /* FEEDER_H_ */

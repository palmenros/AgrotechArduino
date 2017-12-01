/*
 * Feeder.h
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */
#include "HX711.h"

#ifndef FEEDER_H_
#define FEEDER_H_

class Feeder {
protected:

	const int motorPin = 9;

	/* Load cell */
	const int DOUTPin;
	const int CLKPin;

	const int fillWeight;
	const int minThreshold;

	HX711 loadCell;

	bool motorState = false;

public:

	Feeder();

	void setup();
	void loop();

	void switchMotor(bool state);
	float getWeight();
};

#endif /* FEEDER_H_ */

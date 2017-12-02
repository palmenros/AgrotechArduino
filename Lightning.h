/*
 * Lightning.h
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#ifndef LIGHTNING_H_
#define LIGHTNING_H_

class Lightning
{
protected:

	const int ledPin;
	const int ldrPin;

public:
	Lightning(int ledPin, int ldrPin);

	void setup();
	void loop();

	float getLightingPercentage();
	void setLightsBrightness(float percentage);
};

#endif /* LIGHTNING_H_ */

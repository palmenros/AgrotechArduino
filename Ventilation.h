/*
 * Ventilation.h
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#ifndef VENTILATION_H_
#define VENTILATION_H_

class Ventilation
{
protected:

	const int fanPin;

	/* Temperature sensor */
	const int LM35Pin;

public:
	Ventilation(int fanPin, int LM35Pin);

	void setup();
	void loop();

	float getTemperature();

	void setVentilatorSpeed(float percentage);
};

#endif /* VENTILATION_H_ */

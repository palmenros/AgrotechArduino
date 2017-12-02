/*
 * Ultrasonic.h
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

class Ultrasonic
{
protected:
	const int triggerPin;
	const int echoPin;
public:
	Ultrasonic(int trigger, int echo);

	float read();
	float readAverage(int times);

	float getDistance(int times = 10);
};

#endif /* ULTRASONIC_H_ */

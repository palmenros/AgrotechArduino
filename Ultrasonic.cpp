/*
 * Ultrasonic.cpp
 *
 *  Created on: 1 dic. 2017
 *      Author: Pedro
 */

#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigger, int echo)
	: triggerPin(trigger), echoPin(echo)
{
}

float Ultrasonic::read()
{
	  digitalWrite(triggerPin, HIGH);
	  delay(10);
	  digitalWrite(triggerPin, LOW);

	  float time = pulseIn(echoPin, HIGH) / 2;
	  return time * 0.034321;
}

float Ultrasonic::readAverage(int times)
{
	float sum = 0;
	for(int i = 0; i < times; i++)
	{
		sum += read();
		yield();
	}
	return sum / times;
}

float Ultrasonic::getDistance(int times)
{
	return readAverage(times);
}


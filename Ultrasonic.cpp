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
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

float Ultrasonic::read()
{
	  digitalWrite(triggerPin, LOW);
	  delayMicroseconds(4);
	  digitalWrite(triggerPin, HIGH);
	  delayMicroseconds(10);
	  digitalWrite(triggerPin, LOW);

	  long duration = pulseIn(echoPin, HIGH);

	  float time = duration / 2.f;
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


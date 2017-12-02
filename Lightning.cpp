/*
 * Lightning.cpp
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#include "Arduino.h"
#include "Lightning.h"

Lightning::Lightning(int ledPin, int ldrPin)
	: ledPin(ledPin), ldrPin(ldrPin)
{
}

void Lightning::setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(ldrPin, INPUT);
}

void Lightning::loop()
{
}

float Lightning::getLightingPercentage()
{
	return analogRead(ldrPin) / 1023.f;
}

void Lightning::setLightsBrightness(float percentage)
{
	analogWrite(ledPin, percentage * 255);
}

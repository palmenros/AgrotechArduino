/*
 * Lightning.cpp
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#include "Arduino.h"
#include "Lightning.h"
#include "Communication.h"

Lightning::Lightning(int ledPin, int ldrPin)
	: ledPin(ledPin), ldrPin(ldrPin)
{
}

float mapf(float x, float inMin, float inMax, float outMin, float outMax)
{
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

float clamp(float x, float min, float max)
{
  if(x < min) {
    return min;
  }
  if(x > max){
    return max;
  }

  return x;
}

void Lightning::setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(ldrPin, INPUT);
}

void Lightning::loop()
{
  float ldr = getLightingPercentage();
  float value = mapf(ldr, 0.2, 0.7, 0, 1);
  value = clamp(value, 0, 1);

  if(isAutomatic())
  {
	setLightsBrightness(1.f - value);
  }

  Communication::sendSensorData(0x2, value);
}

float Lightning::getLightingPercentage()
{
	return analogRead(ldrPin) / 1023.f;
}

void Lightning::setLightsBrightness(float percentage)
{
	analogWrite(ledPin, percentage * 255);
}

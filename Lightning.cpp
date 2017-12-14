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

float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
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
  Communication::sendSensorData(3, value);
  //setLightsBrightness(1.f - value);
}

float Lightning::getLightingPercentage()
{
	return analogRead(ldrPin) / 1023.f;
}

void Lightning::setLightsBrightness(float percentage)
{
	analogWrite(ledPin, percentage * 255);
}

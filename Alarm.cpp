/*
 * Alarm.cpp
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#include "Alarm.h"
#include "Arduino.h"
#include "TimerOne.h"

float Alarm::time = 1.f;
volatile bool Alarm::isOn = false;
volatile bool Alarm::shouldRing = false;
int Alarm::buzzerPin = 0;

void Alarm::init(int buzzerPin)
{
	pinMode(buzzerPin, OUTPUT);
	Timer1.initialize(time * 1000000);
	Timer1.attachInterrupt(interrupt);
	Alarm::buzzerPin = buzzerPin;
}

void Alarm::switchBuzzer(bool state)
{
	digitalWrite(buzzerPin, state);
}

void Alarm::on()
{
	isOn = true;
	shouldRing = true;
}

void Alarm::off()
{
	isOn = false;
	shouldRing = false;
}

void Alarm::interrupt()
{
	if(shouldRing)
	{
		switchBuzzer(true);
		shouldRing = false;
	} else {
		switchBuzzer(false);
		shouldRing = isOn;
	}
}

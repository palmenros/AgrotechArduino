/*
 * Communication.cpp
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#include "Communication.h"

const uint16_t Communication::endSignal = 0xfade;

void Communication::init(int baudRate)
{
	Serial.begin(baudRate);
}

void Communication::sendSensorData(byte sensorIndex, float data)
{
	Serial.write(sensorIndex);
	Serial.write((uint8_t*) &data, 4);
	Serial.write((uint8_t*) &endSignal, 2);
}

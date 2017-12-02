/*
 * Communication.h
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "Arduino.h"

class Communication
{
protected:

	static const uint16_t endSignal;

public:

	static void init(int baudRate = 9600);
	static void sendSensorData(byte sensorIndex, float data = 0.0f);

};

#endif /* COMMUNICATION_H_ */

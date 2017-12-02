/*
 * Alarm.h
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#ifndef ALARM_H_
#define ALARM_H_

class Alarm
{
protected:

	/*Time in seconds*/
	static float time;

	static volatile bool isOn;
	static volatile bool shouldRing;
	static int buzzerPin;

	static void switchBuzzer(bool state);

public:
	static void init(int buzzerPin);

	static void interrupt();

	static void on();
	static void off();
};

#endif /* ALARM_H_ */

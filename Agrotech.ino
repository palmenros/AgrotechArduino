#include "Arduino.h"
#include "Communication.h"

byte buffer[5];

void setup()
{
	Communication::init();
}

void handleInput()
{
	if(Serial.available() < 5){
		return;
	}

	Serial.readBytes(buffer, 5);

	byte actuator = (buffer[0] & 0xf0) >> 4;
	bool automatic = buffer[0] & 0x0f;

	bool refill = true;
	uint32_t input = 0;

	if(actuator < 2)
	{
		refill = buffer[1] != 0;
	} else {
		//Read Little Endian float
		input |= uint32_t(buffer[1]);
		input |= uint32_t(buffer[2]) << 8;
		input |= uint32_t(buffer[3]) << 16;
		input |= uint32_t(buffer[4]) << 24;
	}

	float value = *((float*)&input);
}

void loop()
{
	//Communication::sendSensorData(random(0, 5), millis() / 1000.f);

	handleInput();
}

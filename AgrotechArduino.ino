#include "Arduino.h"
#include "Communication.h"
#include "Feeder.h"
#include "Ventilation.h"
#include "Lightning.h"
#include "Alarm.h"
#include "Ultrasonic.h"

byte buffer[5];

Feeder feeder(A1, A0, 9);
Ventilation ventilation(10, A2);
Lightning lightning(3, A5);
Ultrasonic ultrasonic(7, 6);
int flameSensor = 8;
int PIRSensor = 5;

int pump =12;

void setup()
{
	Communication::init();
  feeder.setup();
  ventilation.setup();
  lightning.setup();
  pinMode(flameSensor, INPUT);
  pinMode(PIRSensor, INPUT);
  pinMode(pump, OUTPUT);
  Alarm::init(2);
  Alarm::on();
}

void handleInput()
{
	if(Serial.available() < 5)
	{
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

  if(actuator == 3) {
    lightning.setLightsBrightness(value / 100.f); 
  }
}

void loop()
{

  handleInput();
	//Communication::sendSensorData(random(0, 5), millis() / 1000.f);

//  Serial.print("Temperatura: ");

  /* Read multiple times to recharge ADC */
//  ventilation.getTemperature();
//  ventilation.getTemperature();
//  ventilation.getTemperature();
//  ventilation.getTemperature();
//  ventilation.getTemperature();
//  
//  /* Just keep the last reading */
  lightning.loop();
  ventilation.getTemperature();
  ventilation.getTemperature();
  ventilation.getTemperature();
  ventilation.getTemperature();
  ventilation.getTemperature();
  ventilation.getTemperature();
  Communication::sendSensorData(1, ventilation.getTemperature());

  Communication::sendSensorData(5, ultrasonic.read());

  
//
  /* FLAME SENSOR */
//  bool flameDetected = !digitalRead(flameSensor);
//  Serial.print("Llama: ");
//  Serial.println(flameDetected);

  /* PIR SENSOR */
//  bool PIRValue = digitalRead(PIRSensor);
//  Serial.println(PIRValue);
//
//  Serial.print("Peso: ");
//  Serial.println(feeder.getWeight());


//analogWrite(11, 255);

  
//feeder.loop();
//  handleInput();

/* MOTOR TEST */
//  feeder.switchMotor(true);
//  Serial.println("Encendido");
//  delay(1000);
//  feeder.switchMotor(false);
//  Serial.println("Apagado");
//  delay(1000);
//
//

//lightning.loop();

//  Serial.println(lightning.getLightingPercentage());
  
//  digitalWrite(pump, true);
//  Serial.println("Encendido");
//  delay(1000);
//  digitalWrite(pump, false);
//  Serial.println("Apagado");
//  delay(1000);

  
//  Serial.println("Encendido");
//  delay(1000);
//  ventilation.setVentilatorSpeed(0);
//  Serial.println("Apagado");
//  delay(2000);
}

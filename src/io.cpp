#include "Arduino.h"
#include "io.hpp"
void setupButtons()
{
    pinMode(LED_BUILTIN,OUTPUT);
	pinMode(LEFT_BTN, INPUT);
	pinMode(UP_BTN, INPUT);
	pinMode(DOWN_BTN, INPUT);
	pinMode(RIGHT_BTN, INPUT);
}
int readButtons()
{
	#ifdef DEBUGING_COMMS
	printInputs();
	#endif
	return digitalRead(LEFT_BTN) |
		   digitalRead(UP_BTN) << 1 |
		   digitalRead(DOWN_BTN) << 2 |
		   digitalRead(RIGHT_BTN) << 3;
}
void printInputs()
{
	Serial.print("LEFT_BTN");
	Serial.print(digitalRead(LEFT_BTN));
	Serial.print(" ");
	Serial.print("UP_BTN");
	Serial.print(digitalRead(UP_BTN));
	Serial.print(" ");
	Serial.print("DOWN_BTN");
	Serial.print(digitalRead(DOWN_BTN));
	Serial.print(" ");
	Serial.print("RIGHT_BTN");
	Serial.print(digitalRead(RIGHT_BTN));
	Serial.println(" ");
}
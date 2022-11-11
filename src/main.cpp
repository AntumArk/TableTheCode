#include <Arduino.h>
// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;	// 5;//2
const int stepPin = 3;	// 6;//3
const int dirPin2 = 5;	// 5;//2
const int stepPin2 = 6; // 6;//3

#define LEFT_BTN 7
#define UP_BTN 8
#define DOWN_BTN 9
#define RIGHT_BTN 10
//#define DEBUGING_COMMS // comment out so motors could turn

enum BtnPressed
{
	LEFT = 0b0001,
	UP = 0b0010,
	DOWN = 0b0100,
	RIGHT = 0b1000
};

int inputValue = 0;
// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper leftStepper(motorInterfaceType, stepPin, dirPin);
AccelStepper rightStepper(motorInterfaceType, stepPin2, dirPin2);

void setupButtons()
{
	pinMode(LEFT_BTN, INPUT);
	pinMode(UP_BTN, INPUT);
	pinMode(DOWN_BTN, INPUT);
	pinMode(RIGHT_BTN, INPUT);
}
void setupSteppers()
{
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
	leftStepper.setMaxSpeed(1000);
	leftStepper.setAcceleration(50);
	leftStepper.setSpeed(0);

	rightStepper.setMaxSpeed(1000);
	rightStepper.setAcceleration(50);
	rightStepper.setSpeed(0);
}
int readButtons()
{
	//TODO debug button board,. 
	// only LEFT_BTN1 UP_BTN0 DOWN_BTN1 RIGHT_BTN1  is got, and 
	// only UP is working (second btn)
	#ifdef DEBUGING_COMMS
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
	#endif
	return digitalRead(LEFT_BTN) |
		   digitalRead(UP_BTN) << 1 |
		   digitalRead(DOWN_BTN) << 2 |
		   digitalRead(RIGHT_BTN) << 3;
}
void moveSteppers(int left, int right)
{
	leftStepper.setSpeed(left);
	leftStepper.runSpeed();

	rightStepper.setSpeed(right);
	rightStepper.runSpeed();
}
void setup()
{
	pinMode(LED_BUILTIN,OUTPUT);
	Serial.begin(9600);
	setupButtons();
	setupSteppers();
}

void loop()
{

	int leftSteps = 0;
	int rightSteps = 0;
	int stepsPerRot = 200;
	inputValue = readButtons();
	BtnPressed val = static_cast<BtnPressed>(inputValue);
	Serial.println(inputValue, BIN);
	switch (inputValue)
	{
	case LEFT:
		/* code */
		Serial.println("Moving Left UP");
		leftSteps = stepsPerRot;
		break;
	case RIGHT:
		/* code */
		Serial.println("Moving Right UP");
		rightSteps = stepsPerRot;
		break;
	case UP:
		/* code */
		Serial.println("Moving UP");
		leftSteps = stepsPerRot;
		rightSteps = stepsPerRot;
		break;
	case DOWN:
		/* code */
		Serial.println("Moving DOWN");
		leftSteps = -stepsPerRot;
		rightSteps = -stepsPerRot;
		break;
	default:
		break;
	}
	digitalWrite(LED_BUILTIN,leftSteps!=0||rightSteps!=0);
	
// Serial.print("left steps ");
// Serial.print(leftSteps);
// Serial.print(" right steps ");
// Serial.println(rightSteps);
#ifndef DEBUGING_COMMS

	moveSteppers(leftSteps, rightSteps);
#endif
delay(100);
}
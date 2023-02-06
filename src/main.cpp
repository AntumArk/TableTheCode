#include <Arduino.h>
#include "main.hpp"
#include "io.hpp"
int inputValue = 0;

// Creates an instance
AccelStepper leftStepper(MOTOR_INTERFACE_TYPE, lStepPin, lRirPin);
AccelStepper rightStepper(MOTOR_INTERFACE_TYPE, rStepPin, rDirPin);

void setupSteppers()
{
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
	leftStepper.setMaxSpeed(MAX_SPEED);
	leftStepper.setAcceleration(ACCELERATION);
	leftStepper.setSpeed(0);
	leftStepper.setEnablePin(LEFT_EN_PIN);
	leftStepper.setPinsInverted(false,false,true);

	rightStepper.setMaxSpeed(MAX_SPEED);
	rightStepper.setAcceleration(ACCELERATION);
	rightStepper.setSpeed(0);
	rightStepper.setEnablePin(RIGHT_EN_PIN);
	rightStepper.setPinsInverted(false,false,true);
}

void moveSteppers(int leftSpeed, int rightSpeed)
{
	moveStepper(leftStepper,leftSpeed);
	moveStepper(rightStepper,rightSpeed);
}

void moveStepper(AccelStepper stepper, int speed)
{
	if (speed==0)
	{
		// Disable driver to save power
		stepper.disableOutputs();
	}
	else
	{
		stepper.enableOutputs();
	
	}	
		stepper.setSpeed(speed);
		stepper.runSpeed();		
}

void setup()
{
	Serial.begin(BAUD_RATE);
	setupButtons();
	setupSteppers();
}

void loop()
{

	int leftSteps = 0;
	int rightSteps = 0;
	int stepsPerRot = MAX_SPEED;
	inputValue = readButtons();	
	
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
	digitalWrite(LED_BUILTIN, leftSteps!=0 || rightSteps!=0 );

#ifndef DEBUGING_COMMS
	moveSteppers(leftSteps, rightSteps);
#endif

	delay(LOOP_WAIT_TIME);
}
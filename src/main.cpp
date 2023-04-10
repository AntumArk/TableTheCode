#include <Arduino.h>
#include "main.hpp"
#include "io.hpp"
int inputValue = 0;

// Creates an instance

// 2-wire basic config, microstepping is hardwired on the driver
// Other drivers can be mixed and matched but must be configured individually
Motor leftStepper(lDirPin, lStepPin, LEFT_EN_PIN);
Motor rightStepper(rDirPin, rStepPin, RIGHT_EN_PIN);

void setupSteppers()
{
}

void moveSteppers(int leftSpeed, int rightSpeed)
{
	moveStepper(leftStepper, leftSpeed);
	moveStepper(rightStepper, rightSpeed);
}

void moveStepper(Motor stepper, int speed)
{

	stepper.Spin(speed);
}

void setup()
{
	#ifdef DEBUGING_COMMS
	Serial.begin(BAUD_RATE);
	#endif
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
		#ifdef DEBUGING_COMMS
		Serial.println("Moving Left UP");
		#endif
		leftSteps = stepsPerRot;
		break;
	case RIGHT:
		/* code */
		#ifdef DEBUGING_COMMS
		Serial.println("Moving Right UP");
		#endif
		rightSteps = stepsPerRot;
		break;
	case UP:
		/* code */
		#ifdef DEBUGING_COMMS
		Serial.println("Moving UP");
		#endif
		leftSteps = stepsPerRot;
		rightSteps = stepsPerRot;
		break;
	case DOWN:
		/* code */
		#ifdef DEBUGING_COMMS
		Serial.println("Moving DOWN");
		#endif
		leftSteps = -stepsPerRot;
		rightSteps = -stepsPerRot;
		break;
	default:
		break;
	}
	digitalWrite(LED_BUILTIN, leftSteps != 0 || rightSteps != 0);

#ifndef DEBUGING_COMMS
	moveSteppers(leftSteps, rightSteps);
#endif

	//delayMicroseconds(LOOP_WAIT_TIME);
}

#include <Arduino.h>
#include "main.hpp"
#include "io.hpp"
int inputValue = 0;

// Creates an instance

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *leftStepper = NULL;
FastAccelStepper *rightStepper = NULL;

void setupSteppers()
{

	engine.init();
	leftStepper = engine.stepperConnectToPin(lStepPin);

	if (leftStepper)
	{
		leftStepper->setDirectionPin(lDirPin);
		leftStepper->setEnablePin(LEFT_EN_PIN);
		leftStepper->setAutoEnable(true);

		leftStepper->setSpeedInUs(MAX_SPEED); // the parameter is us/step !!!
		leftStepper->setAcceleration(ACCELERATION);
	}

	rightStepper = engine.stepperConnectToPin(rStepPin);

	if (rightStepper)
	{
		rightStepper->setDirectionPin(rDirPin);
		rightStepper->setEnablePin(RIGHT_EN_PIN);
		rightStepper->setAutoEnable(true);

		rightStepper->setSpeedInUs(MAX_SPEED); // the parameter is us/step !!!
		rightStepper->setAcceleration(ACCELERATION);
	}
}

void moveSteppers(int leftSpeed, int rightSpeed)
{
	moveStepper(leftStepper, leftSpeed);
	moveStepper(rightStepper, rightSpeed);
}

void moveStepper(FastAccelStepper *stepper, int speed)
{
	if (speed != 0)
	{
		stepper->move(speed);
	}
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
	digitalWrite(LED_BUILTIN, leftSteps != 0 || rightSteps != 0);

#ifndef DEBUGING_COMMS
	moveSteppers(leftSteps, rightSteps);
#endif

	delay(LOOP_WAIT_TIME);
}

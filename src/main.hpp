#pragma once
// Include the AccelStepper Library
#include "FastAccelStepper.h"
// Define pin connections
const int lDirPin = 2;	// 5;//2
const int lStepPin = 3;	// 6;//3
const int rDirPin = 5;	// 5;//2
const int rStepPin = 6; // 6;//3

#define LEFT_EN_PIN 11
#define RIGHT_EN_PIN 12

// Define motor interface type
#define MOTOR_INTERFACE_TYPE 1
#define MAX_SPEED 1
#define ACCELERATION 50
#define STEPS_PER_ROT 1000

#define LOOP_WAIT_TIME 1
#define BAUD_RATE 9600

void setupSteppers();
void moveSteppers(int left, int right);
void moveStepper(FastAccelStepper *stepper,int speed);

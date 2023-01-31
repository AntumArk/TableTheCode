#pragma once
// Include the AccelStepper Library
#include <AccelStepper.h>
// Define pin connections
const int lRirPin = 2;	// 5;//2
const int lStepPin = 3;	// 6;//3
const int rDirPin = 5;	// 5;//2
const int rStepPin = 6; // 6;//3

#define LEFT_EN_PIN 11
#define RIGHT_EN_PIN 12

// Define motor interface type
#define MOTOR_INTERFACE_TYPE 1
#define MAX_SPEED 1000
#define ACCELERATION 50
#define STEPS_PER_ROT 200

#define LOOP_WAIT_TIME 100
#define BAUD_RATE 9600

void setupSteppers();
void moveSteppers(int left, int right);
void moveStepper(AccelStepper stepper,int speed);

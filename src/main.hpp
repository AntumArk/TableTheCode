#pragma once
#include "motor.hpp"
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
// Target RPM for X axis motor
#define MOTOR_X_RPM 30
// Target RPM for Y axis motor
#define MOTOR_Y_RPM 90

// If microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 16
// Include the AccelStepper Library
// Define pin connections
const int lDirPin = 2;	// 5;//2
const int lStepPin = 3;	// 6;//3
const int rDirPin = 5;	// 5;//2
const int rStepPin = 6; // 6;//3

#define LEFT_EN_PIN 11
#define RIGHT_EN_PIN 12

// Define motor interface type
#define MOTOR_INTERFACE_TYPE 1
#define MAX_SPEED 1000
#define ACCELERATION 50
#define STEPS_PER_ROT 1000

#define LOOP_WAIT_TIME 1
#define BAUD_RATE 9600

void setupSteppers();
void moveSteppers(int left, int right);
void moveStepper(Motor stepper,int speed);

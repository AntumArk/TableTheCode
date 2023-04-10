#include "motor.hpp"
#include "Arduino.h"
Motor::Motor(const int dirPin, const int stepPin, const int enPin) : dirPin(dirPin), stepPin(stepPin), enPin(enPin)
{
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(enPin, OUTPUT);
}

Motor::~Motor()
{
}

void Motor::Spin(int speed)
{
    CheckSpeed(speed);
    CheckDirection(speed);
    digitalWrite(dirPin, directionValue); 
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(MICROSTEPDUR);
    digitalWrite(stepPin,LOW);
    
    delayMicroseconds(MICROSTEPDUR);
}

void Motor::CheckSpeed(int speed)
{
    if (speed == 0)
    {
        Disable();
        /* code */
    }
    else
    {
        Enable();
    }
}

void Motor::CheckDirection(int speed)
{
    int newValue= speed > 0;
    if (directionValue!=newValue)
    {
        directionValue =newValue;
        delayMicroseconds(1);
    }
    
    
}

void Motor::Disable()
{
    digitalWrite(enPin, HIGH);
}

void Motor::Enable()
{
    digitalWrite(enPin, LOW);
}

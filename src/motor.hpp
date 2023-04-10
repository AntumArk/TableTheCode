#pragma once

#define MICROSTEPDUR 40
class Motor
{
private:
    const int dirPin = 0;
    const int stepPin = 0;
    const int enPin = 0;
    int directionValue = 0;
    int disableValue = 0;
    int stepValue = 0;

public:
    Motor(const int dirPin, const int stepPin, const int enPin);
    ~Motor();
    void Spin(int speed);

private:
    void CheckSpeed(int speed);
    void CheckDirection(int speed);
    void Disable();
    void Enable();
};

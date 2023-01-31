#pragma once

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

void setupButtons();
int readButtons();
void printInputs();
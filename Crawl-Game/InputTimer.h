#pragma once
#include <time.h>
#include <ctime>
#include <iostream>

#define INPUT_TIME 100

class InputTimer {

private:
	clock_t targetTime;
	void RestartTimer();
public:
	InputTimer();
	void Run();
	bool CheckInput();
};



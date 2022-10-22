#pragma once
#include <time.h>
#include <ctime>
#include <iostream>

class Timer {
private:
	int maxTime, minTime;
	clock_t targetTime;
	void RestartTimer();
public:
	Timer(int minxTime, int maxTime);
	Timer(int time);
	void Run();
	bool CheckTime();
};
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
	Timer(int maxTime, int minTime);
	Timer(int time);
	void Run();
	bool CheckTime();
};
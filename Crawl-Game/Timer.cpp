#include "Timer.h"

Timer::Timer(int maxTime, int minTime)
{
	this->maxTime = maxTime;
	this->minTime = minTime;
	targetTime = 0;
}

Timer::Timer(int time)
{
	this->maxTime = time;
	this->minTime = time;
	targetTime = 0;
}

void Timer::Run() {
	RestartTimer();
	while (true) {
		
	}
}

void Timer::RestartTimer() {
	if (maxTime == minTime) {
		targetTime = clock() + maxTime;
	}
	else {
		targetTime = clock() + (rand() % (maxTime - minTime)) + minTime;
	}
}

bool Timer::CheckTime() {
	if (clock() >= targetTime) {
		RestartTimer();
		return true;
	}
	return false;
}

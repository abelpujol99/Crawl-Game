#pragma once
#include <thread>
#include <vector>
#include <iostream>
#include "Input.h"
#include "Timer.h"

class ThreadManager
{
private:
	std::thread* _inputListenerThread;
	std::vector<std::thread*> _timerThreads;

public:
	ThreadManager();
	~ThreadManager();
	void StartInputListenerThread(Input* inputListener);
	void StartTimer(Timer* timer);
};


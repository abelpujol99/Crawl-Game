#pragma once
#include <thread>
#include "Input.h"

class ThreadManager
{
private:
	std::thread* _createEntityThread;
	std::thread* _autoSaveThread;
	std::thread* _inputListenerThread;
public:
	ThreadManager();
	~ThreadManager();
	void StartInputThread(Input* input);
};


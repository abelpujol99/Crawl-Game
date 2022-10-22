#pragma once
#include <ctime>
#include <iostream>

#define AUTOSAVE_SECONDS 5

class AutosaveTimer
{
public:
private:
	clock_t targetTime;
	void RestartTimer();
public:
	AutosaveTimer();
	void Run();
	bool CheckSave();
};


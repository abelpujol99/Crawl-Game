#pragma once
#include <thread>
#include "Input.h"
#include "AutosaveTimer.h"
#include "EnemySpawn.h"
#include "InputTimer.h"

class ThreadManager
{
private:
	std::thread* _enemySpawnThread;
	std::thread* _autoSaveThread;
	std::thread* _inputTimerThread;
	std::thread* _inputListenerThread;
public:
	ThreadManager();
	~ThreadManager();
	void StartInputListenerThread(Input* inputListener);
	void StartInputTimerThread(InputTimer* inputTimer);
	void StartAutoSaveThread(AutosaveTimer* autosave);
	void StartSpawnThread(EnemySpawn* enemySpawn);
};


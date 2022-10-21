#pragma once
#include <thread>
#include "Input.h"
#include "EnemySpawn.h"

class ThreadManager
{
private:
	std::thread* _enemySpawnThread;
	std::thread* _autoSaveThread;
	std::thread* _inputListenerThread;
public:
	ThreadManager();
	~ThreadManager();
	void StartInputThread(Input* input);
	void StartSpawnThread(EnemySpawn* enemySpawn);
};


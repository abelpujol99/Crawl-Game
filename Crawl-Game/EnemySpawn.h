#pragma once
#include <time.h>

#define MAX_SPAWN_TIME 15000
#define MIN_SPAWN_TIME 10000

class EnemySpawn {
private:
	clock_t targetTime;
	void RestartTimer();
public:
	EnemySpawn();
	void Run();
	bool CheckSpawn();
};
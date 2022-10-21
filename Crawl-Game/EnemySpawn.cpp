#include "EnemySpawn.h"
#include <ctime>
#include <iostream>

EnemySpawn::EnemySpawn() {
	targetTime = 0;
}

void EnemySpawn::Run() {
	RestartTimer();
	while (true) {
		
	}
}

void EnemySpawn::RestartTimer() {
	targetTime = clock() + (rand() % (MAX_SPAWN_TIME - MIN_SPAWN_TIME)) + MIN_SPAWN_TIME;
}

bool EnemySpawn::CheckSpawn() {
	if (clock() >= targetTime) {
		RestartTimer();
		return true;
	}
	return false;
}

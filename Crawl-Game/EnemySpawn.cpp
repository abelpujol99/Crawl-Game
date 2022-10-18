#include "EnemySpawn.h"
#include <ctime>
#include <iostream>

/*EnemySpawn::EnemySpawn(GameManager* gameManager) {
	//gm = gameManager;
}*/

void EnemySpawn::Run() {
	srand(time(NULL));

	while (true) {
		if (CheckSpawnTime()) {

		}
	}
}

bool EnemySpawn::CheckSpawnTime() {
	clock_t begin = clock();
	std::cout << begin << std::endl;
	return false;
}

void EnemySpawn::Spawn() {
	//gm->AddEnemy();
}

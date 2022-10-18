#pragma once
#include <time.h>

class EnemySpawn {
private:
	//GameManager* gm;

	void Spawn();
	bool CheckSpawnTime();
public:
	//EnemySpawn(GameManager* gameManager);
	void Run();
};
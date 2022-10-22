#include "EnemyPlacer.h"

Enemy* EnemyPlacer::PlaceEnemy(Map* map) {
	Coordinates spawnCoordinates;

	do {
		spawnCoordinates = Coordinates((rand() % (MAP_WIDTH - 2)) + 1, (rand() % (MAP_HEIGHT - 2)) + 1);
	} while (map->SelectMapElementPointer(spawnCoordinates)[0]->GetMapElementType() != NONE);

	Enemy* spawnedEnemy = new Enemy(spawnCoordinates, map->GetWorldMapCoordinates());
	spawnedEnemy->Draw();
	return spawnedEnemy;
}
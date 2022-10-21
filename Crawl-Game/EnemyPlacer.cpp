#include "EnemyPlacer.h"

Enemy* EnemyPlacer::PlaceEnemy(Map& map) {
	Coordinates spawnCoordinates;

	std::cout << "Spawn coordinates: ";
	do {
		spawnCoordinates = Coordinates((rand() % (MAP_WIDTH - 2)) + 1, (rand() % (MAP_HEIGHT - 2)) + 1);
		std::cout << spawnCoordinates.x << ", " << spawnCoordinates.y << std::endl;
	//} while (map.GetMapElements()[spawnCoordinates.x][spawnCoordinates.y]->GetMapElementType() != NONE);
	} while (map.SelectMapElement(spawnCoordinates)[0]->GetMapElementType() != NONE);

	Enemy* spawnedEnemy = new Enemy(spawnCoordinates);
	return spawnedEnemy;
}
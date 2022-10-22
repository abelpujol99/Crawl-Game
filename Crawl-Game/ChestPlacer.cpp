#include "ChestPlacer.h"

Chest* ChestPlacer::PlaceChest(Map* map) {
	Coordinates spawnCoordinates;

	do {
		spawnCoordinates = Coordinates((rand() % (MAP_WIDTH - 2)) + 1, (rand() % (MAP_HEIGHT - 2)) + 1);
	} while (map->SelectMapElementPointer(spawnCoordinates)[0]->GetMapElementType() != NONE);

	Chest* spawnedChest = new Chest(spawnCoordinates, map->GetWorldMapCoordinates());
	spawnedChest->Draw();
	return spawnedChest;
}
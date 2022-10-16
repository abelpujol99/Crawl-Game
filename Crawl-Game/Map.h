#pragma once
#include <iostream>
#include <vector>
#include "Coordinates.h"
#include "Portal.h"
#include "Block.h"
#include "MapElement.h"

#define MAP_WIDTH 7
#define MAP_HEIGHT 7
#define MAX_NUM_PORTALS 4

class Map {

private:

	std::vector<std::vector<MapElement*>> _map;
	std::vector<Portal> _portals;
	std::vector<Block> _blocks;

	void CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CreateMapLimits(std::vector<bool> cardinalPortals);
	void CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounters);

public:

	Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CheckCollision(MapElement* malElements);
	void Draw(MapElement* mapElements);
	void AddMapElement(MapElement* mapElement);
	std::vector<Portal> GetPortals();
	std::vector<Block> GetBlocks();
	void Draw();
};
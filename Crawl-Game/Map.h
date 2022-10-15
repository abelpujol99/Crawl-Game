#pragma once
#include <iostream>
#include <vector>
#include "Coordinates.h"
#include "Portal.h"
#include "Wall.h"
#include "MapElementCoordinates.h"

#define MAP_WIDTH 7
#define MAP_HEIGHT 7
#define MAX_NUM_PORTALS 4

class Map {

private:

	std::vector<std::vector<char>> _map;
	std::vector<Portal> _portals;
	std::vector<Wall> _walls;
	void CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CreatePortalsOrWalls(std::vector<bool> cardinalPortals);

public:

	Map();
	Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CheckCollision();
	void Draw(MapElementCoordinates* mapElements);
};
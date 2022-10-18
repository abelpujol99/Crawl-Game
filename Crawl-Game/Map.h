#pragma once
#include <iostream>
#include <vector>
#include "Coordinates.h"
#include "Portal.h"
#include "Block.h"
#include "EmptyBox.h"
#include "MapElement.h"

#define MAP_WIDTH 7
#define MAP_HEIGHT 7

class Map {

private:

	std::vector<std::vector<MapElement*>*>* _mapPtr = new std::vector<std::vector<MapElement*>*>();

	void CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CreateMap(std::vector<bool> cardinalPortals);
	void CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounters, MapElement* auxMapElement);

public:

	Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CheckCollision(MapElement* malElements);
	void Draw(MapElement* mapElements);
	void AddMapElement(MapElement* mapElement);
	std::vector<std::vector<MapElement*>*>* GetMapElements();
	void SetMapElementInCurrentMap(MapElement* mapElement);
	void SwapMapElementsInCurrentMap(std::vector<MapElement*> mapElementsToSwap);
	void Draw();
};
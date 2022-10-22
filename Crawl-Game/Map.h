#pragma once
#include <iostream>
#include <vector>

struct Coordinates;
class MapElement;
class Character;
class Portal;
class Block;
class EmptyBox;

#define MAP_WIDTH 7
#define MAP_HEIGHT 7

class Map {

private:

	//using SwapContainer = std::pair<MapElement*, MapElement*>;

	std::vector<std::vector<MapElement*>*>* _mapPtr = new std::vector<std::vector<MapElement*>*>();
	std::vector<Portal*> _portals;

	void CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	void CreateMap(std::vector<bool> cardinalPortals);
	void CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounters, std::vector<MapElement*>* auxMapElements);

public:

	Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap);
	MapElement* CheckCollision(Coordinates coordinates);
	MapElement** SelectMapElementPointer(Coordinates coordinates);
	std::vector<std::vector<MapElement*>*>* GetMapElements();
	std::vector<Portal*> GetPortals();
	void MoveCharacter(Character* character);
	void SetMapElement(MapElement* mapElement);
	void SetEmptyBox(Coordinates coordinates);
	void Draw();
};
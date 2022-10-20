#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Coordinates.h"

class MapElement;
class ConsoleControl;
class Input;
class ThreadManager;
class Player;
class Enemy;
class Chest;
class Coin;
class Potion;
class Weapon;
class Block;
class Portal;
class EmptyBox;
class GameUI;
class Map;

#define WORLD_MAP_WIDTH 3
#define WORLD_MAP_HEIGHT 3

class GameManager
{
private:

	ThreadManager* threadManager;
	Input* input;
	GameUI* gameUI;	
	std::vector<std::vector<Map*>> _maps;
	std::vector<std::vector<MapElement*>*>* _currentMap;
	Player* _player;
	std::vector<Portal*> _portals;
	Coordinates _currentWorldMapCoordinates;

	void SetMapElementInCurrentMap(MapElement* mapElement);
	void SetCurrentMap(Coordinates nextMapCoordinates);
	void ActionDependOnMapElementType(MapElement* mapElement);
	void DrawMapElements();

public:

	GameManager();
	~GameManager();
	void Setup();
	void Loop();
	bool CheckExit();
};

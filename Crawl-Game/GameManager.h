#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Coordinates.h"
#include "Character.h"

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
	Map* _currentMap;
	std::vector<std::vector<MapElement*>*>* _currentMapElements;
	Player* _player;
	std::vector<Portal*> _portals;
	Coordinates _currentWorldMapCoordinates;

	//void CreatePortals();
	void SetMapElementInCurrentMap(MapElement* mapElement);
	void SetCurrentMap(Coordinates nextMapCoordinates);
	void ActionDependOnMapElementType(MapElement* mapElement);
	Coordinates GetWeaponTargetCoordinates(Character* character);
	void SetPlayerCoordinates(Coordinates portalCoordinates);
	void DrawMapElements();

public:

	GameManager();
	~GameManager();
	void Setup();
	void Loop();
	bool CheckExit();
};

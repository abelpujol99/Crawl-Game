#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Coordinates.h"
#include "Character.h"
#include "ConsoleControl.h"
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"
#include "Coin.h"
#include "Potion.h"
#include "Weapon.h"
#include "Block.h"
#include "Portal.h"
#include "EmptyBox.h"
#include "GameUI.h"
#include "Map.h"
#include "Input.h"
#include "ThreadManager.h"
#include "JsonSaver.h"
#include "JsonLoader.h"
#include "AutosaveTimer.h"
#include "EnemySpawn.h"
#include "EnemyPlacer.h"

#define WORLD_MAP_WIDTH 3
#define WORLD_MAP_HEIGHT 3

class GameManager
{
private:

	ThreadManager* _threadManager;
	Input* _input;
	AutosaveTimer* _autosaveTimer;
	JsonSaver* _jsonSaver;
	JsonLoader* _jsonLoader;
	EnemySpawn* _spawnTimer;
	EnemyPlacer* _enemyPlacer;
	GameUI* _gameUI;	
	std::vector<std::vector<Map*>> _maps;
	Map* _currentMap;
	std::vector<std::vector<MapElement*>*>* _currentMapElements;
	Player* _player;
	std::vector<Portal*> _portals;

	//void CreatePortals();
	void SetMapElementInCurrentMap(MapElement* mapElement);
	void SetCurrentMap(Coordinates nextMapCoordinates);
	void ActionDependOnMapElementType(MapElement* mapElement);
	Coordinates GetWeaponTargetCoordinates(Character* character);
	void SetPlayerCoordinates(Coordinates portalCoordinates);

public:

	GameManager();
	~GameManager();
	void Setup();
	void Loop();
	bool CheckExit();
};

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
#include "Timer.h"

#define WORLD_MAP_WIDTH 3
#define WORLD_MAP_HEIGHT 3
#define MAX_SPAWN_TIME 15000
#define MIN_SPAWN_TIME 10000
#define AUTOSAVE_TIME 5000
#define INPUT_TIME 100

class GameManager
{
private:

	ThreadManager* _threadManager;
	Input* _input;
	JsonSaver* _jsonSaver;
	JsonLoader* _jsonLoader;
	Timer* _spawnTimer;
	Timer* _autosaveTimer;
	Timer* _inputTimer;
	Input* _inputListener;
	GameUI* _gameUI;	
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

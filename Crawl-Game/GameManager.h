#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Input.h"
#include "ThreadManager.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyPlacer.h"
#include "Chest.h"
#include "Coin.h"
#include "Potion.h"
#include "Weapon.h"
#include "Block.h"
#include "Portal.h"
#include "EmptyBox.h"
#include "GameUI.h"
#include "Map.h"
#include <time.h>

#define WORLD_MAP_WIDTH 3
#define WORLD_MAP_HEIGHT 3


class GameManager
{
private:
	bool _exit;
	ThreadManager* _threadManager;
	Input* _input;

	GameUI* _gameUI;	

	std::vector<std::vector<Map>> _maps;
	Coordinates _currentMap;

	Player _player;

	std::vector<EntityLootable*> _entityLootables;
	EnemySpawn* _enemySpawn;
	EnemyPlacer* _enemyPlacer;

public:

	GameManager();
	~GameManager();
	void Setup();
	void Loop();
	bool CheckExit();
	void SetCurrentMap(Coordinates nextMapCoordinates);
	void SetMapElementInCurrentMap(MapElement* mapElement);
};


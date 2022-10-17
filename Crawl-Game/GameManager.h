#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Input.h"
#include "ThreadManager.h"
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

#define WORLD_MAP_WIDTH 3
#define WORLD_MAP_HEIGHT 3

class GameManager
{
private:

	ThreadManager* threadManager;
	Input* input;
	GameUI* gameUI;	
	std::vector<std::vector<Map>> _maps;
	Player player;
	Coordinates _currentMap;

public:

	GameManager();
	~GameManager();
	void Setup();
	void Loop();
	bool CheckExit();
	void SetCurrentMap(Coordinates nextMapCoordinates);
	void SetMapElementInCurrentMap(MapElement* mapElement);
};


#pragma once
#include <iostream>
#include <vector>
#include "Input.h"
#include "ThreadManager.h"
#include "Player.h"
#include "EntityLootable.h"
#include "GameUI.h"
#include "Map.h"

class GameManager
{
private:
	bool exit = false;
	ThreadManager* threadManager;
	Input* input;
	GameUI* gameUI;
	Player* player;
	std::vector<EntityLootable*> entities;
	std::vector<std::vector<Map> > maps;
public:
	GameManager();
	~GameManager();
	void Setup();
	void Loop();
	bool CheckExit();
};


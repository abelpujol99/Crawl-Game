#include "GameManager.h"

GameManager::GameManager()
{
	threadManager = new ThreadManager();
	input = new Input();
	gameUI = new GameUI();
	
	for (int i = 0; i < WORLD_MAP_HEIGHT; i++)
	{
		std::vector<Map> auxMap;

		for (int j = 0; j < WORLD_MAP_WIDTH; j++)
		{
			auxMap.push_back(Map(Coordinates(i, j), Coordinates(WORLD_MAP_HEIGHT, WORLD_MAP_WIDTH)));
		}
		_maps.push_back(auxMap);
	}

	_currentMap = Coordinates(floor(WORLD_MAP_HEIGHT / 2), floor(WORLD_MAP_WIDTH / 2));
	Player player(Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2)));
	Player* playerPtr = &player;
	
	_mapElements.push_back(playerPtr);

	InsertStaticElements();	
}

GameManager::~GameManager()
{
	delete threadManager;
	delete input;
	delete gameUI;
}

void GameManager::Loop()
{
	char lastChar = input->LastInput();
	if (lastChar != 0) {
		//exit = lastChar == KB_ESCAPE;
		cout << lastChar << endl;
	}

	_maps[_currentMap.y][_currentMap.x].Draw();
}

void GameManager::Setup()
{
	threadManager->StartInputThread(input);
}

bool GameManager::CheckExit()
{
	return exit;
} 

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	this->_currentMap = nextMapCoordinates;
}

void GameManager::SetMapElementInCurrentMap(MapElement* mapElement) {


}

void GameManager::InsertStaticElements() {

	for (int i = 0; i < _maps.size(); i++)
	{
		for (int j = 0; j < _maps[i].size(); j++)
		{
			std::vector<Block> auxBlocks = _maps[i][j].GetBlocks();
			std::vector<Portal> auxPortals = _maps[i][j].GetPortals();

			for (int k = 0; k < auxBlocks.size(); k++)
			{
				Block auxBlock = auxBlocks[k];
				Block* auxBlockPtr = &auxBlock;
				_mapElements.push_back(auxBlockPtr);
			}

			for (int k = 0; k < auxPortals.size(); k++)
			{
				Portal auxPortal = auxPortals[k];
				Portal* auxPortalPtr = &auxPortal;
				_mapElements.push_back(auxPortalPtr);
			}
		}
	}
}
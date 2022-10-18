#include "GameManager.h"

GameManager::GameManager()
{
	threadManager = new ThreadManager();
	input = new Input();
	gameUI = new GameUI();
	
	for (int i = 0; i < WORLD_MAP_HEIGHT; i++)
	{
		std::vector<Map*> auxMap = std::vector<Map*>();

		for (int j = 0; j < WORLD_MAP_WIDTH; j++)
		{
			auxMap.push_back(new Map(Coordinates(i, j), Coordinates(WORLD_MAP_HEIGHT, WORLD_MAP_WIDTH)));
		}
		_maps.push_back(auxMap);
	}

	SetCurrentCoordinates(Coordinates(floor(WORLD_MAP_HEIGHT / 2), floor(WORLD_MAP_WIDTH / 2)));
	//this->player = Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))));
	Player* playerPtr = new Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))));
	_maps[_currentMapCoordinates.y][_currentMapCoordinates.x]->SetMapElementInCurrentMap(playerPtr);
}

GameManager::~GameManager()
{
	delete threadManager;
	delete input;
	delete gameUI;
}

void GameManager::Loop()
{
	SetCurrentMap(Coordinates(floor(WORLD_MAP_HEIGHT / 2), floor(WORLD_MAP_WIDTH / 2)));
	char lastChar = input->LastInput();
	if (lastChar != 0) {
		//exit = lastChar == KB_ESCAPE;
		cout << lastChar << endl;
	}
	while (/*!player.IsAlive()*/true)
	{		
		DrawMapElements();
	}

}

void GameManager::Setup()
{
	threadManager->StartInputThread(input);
}

bool GameManager::CheckExit()
{
	return exit;
} 

void GameManager::SetCurrentCoordinates(Coordinates coordinates) {

	this->_currentMapCoordinates = coordinates;
}

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	SetCurrentCoordinates(nextMapCoordinates);
	this->_currentMap = _maps[_currentMapCoordinates.y][_currentMapCoordinates.x]->GetMapElements();
	this->_maps[_currentMapCoordinates.y][_currentMapCoordinates.x]->Draw();
}

void GameManager::DrawMapElements() {

	for (int i = 0; i < MAP_HEIGHT - 1; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			std::vector<MapElement*>* auxMapElement = _currentMap->at(j);

			if (auxMapElement->at(i)->GetMapElementType() != WALL
				&& auxMapElement->at(i)->GetMapElementType() != PORTAL
				&& auxMapElement->at(i)->GetMapElementType() != NONE)
			{
				ConsoleControl::SetPosition(j, i);
				auxMapElement->at(i)->Draw();
			}
		}
	}

}
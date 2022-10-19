#include "GameManager.h"

GameManager::GameManager()
{
	threadManager = new ThreadManager();
	input = new Input();
	gameUI = new GameUI();
	
	for (int i = 0; i < WORLD_MAP_WIDTH; i++)
	{
		std::vector<Map*> auxMap = std::vector<Map*>();

		for (int j = 0; j < WORLD_MAP_HEIGHT; j++)
		{
			auxMap.push_back(new Map(Coordinates(i, j), Coordinates(WORLD_MAP_WIDTH, WORLD_MAP_HEIGHT)));
		}
		_maps.push_back(auxMap);
	}

	SetCurrentMap(Coordinates(floor(WORLD_MAP_HEIGHT / 2), floor(WORLD_MAP_WIDTH / 2)));
	player = new Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))));
	_maps[_currentMapCoordinates.x][_currentMapCoordinates.y]->SetMapElementInCurrentMap(player);
}

GameManager::~GameManager()
{
	delete threadManager;
	delete input;
	delete gameUI;
	delete player;
}

void GameManager::Loop()
{
	char lastChar = input->LastInput();
	if (lastChar != 0) {
		//exit = lastChar == KB_ESCAPE;
		cout << lastChar << endl;
	}
	while (player->IsAlive())
	{		
		DrawMapElements();

		char input;
		cin >> input;

		if (input == 'd')
		{
			player->SetTargetCoordinatesToMove(Coordinates(player->GetCoordinates().x + 1, player->GetCoordinates().y));
			std::vector<MapElement*>* mapElementCoordinates = _currentMap->at(player->GetTargetCoordinatesToMove().y);
			MapElement* mapElement = mapElementCoordinates->at(player->GetTargetCoordinatesToMove().x);
			if (mapElement->GetMapElementType() == NONE)
			{
				std::vector<MapElement*> mapElementsToSwap;
				mapElementsToSwap.push_back(player);
				mapElementsToSwap.push_back(mapElement);
				_maps[_currentMapCoordinates.x][_currentMapCoordinates.y]->SwapMapElementsInCurrentMap(mapElementsToSwap);
			}

			//std::cout << mapElementCoordinates->at(player->GetTargetCoordinatesToMove().y) << std::endl << mapElement << std::endl;
		}
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

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	this->_currentMapCoordinates = nextMapCoordinates;
	this->_currentMap = _maps[_currentMapCoordinates.x][_currentMapCoordinates.y]->GetMapElements();
	ConsoleControl::SetPosition(0, 0);
	this->_maps[_currentMapCoordinates.x][_currentMapCoordinates.y]->Draw();
}

void GameManager::DrawMapElements() {

	for (int i = 0; i < MAP_HEIGHT - 1; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			std::vector<MapElement*>* auxMapElement = _currentMap->at(j);

			if (auxMapElement->at(i)->GetMapElementType() != WALL
				&& auxMapElement->at(i)->GetMapElementType() != PORTAL)
			{
				ConsoleControl::SetPosition(i, j);
				auxMapElement->at(i)->Draw();
			}
		}
	}

}
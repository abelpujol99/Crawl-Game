#include "GameManager.h"

GameManager::GameManager()
{
	exit = false;
	threadManager = new ThreadManager();
	input = new Input();
	enemySpawn = new EnemySpawn();
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
	this->player = Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))));
	Player* playerPtr = &player;
	
	std::vector<std::vector<MapElement*>> auxMap = _maps[_currentMap.y][_currentMap.x].GetMapElements();
	auxMap[player.GetCoordinates().y][player.GetCoordinates().x] = playerPtr;

}

GameManager::~GameManager()
{
	delete threadManager;
	delete input;
	delete gameUI;
}

void GameManager::Loop()
{
	_maps[_currentMap.y][_currentMap.x].Draw();

	while (!CheckExit()) {
		char lastChar = input->LastInput();
		if (lastChar != 0) {
			exit = lastChar == KB_ESCAPE;
			//cout << lastChar << endl;
		}
	}
}

void GameManager::Setup()
{
	threadManager->StartInputThread(input);
	threadManager->StartSpawnThread(enemySpawn);
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
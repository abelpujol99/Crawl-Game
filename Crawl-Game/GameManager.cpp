#include "GameManager.h"

GameManager::GameManager()
{
	_exit = false;
	_threadManager = new ThreadManager();
	_input = new Input();
	_enemySpawn = new EnemySpawn();
	_gameUI = new GameUI();
	
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
	this->_player = Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))));
	Player* playerPtr = &_player;
	
	std::vector<std::vector<MapElement*>> auxMap = _maps[_currentMap.y][_currentMap.x].GetMapElements();
	auxMap[_player.GetCoordinates().y][_player.GetCoordinates().x] = playerPtr;

}

GameManager::~GameManager()
{
	delete _threadManager;
	delete _input;
	delete _enemySpawn;
	delete _gameUI;


	EntityLootable* el = _entityLootables[0];
	delete el;
	int i = 0;
	/*for (auto entityLootable : _entityLootables) {
		delete entityLootable;
	}
	_entityLootables.clear();*/
}

void GameManager::Loop()
{
	_maps[_currentMap.y][_currentMap.x].Draw();

	while (!CheckExit()) {
		char lastChar = _input->LastInput();
		if (lastChar != 0) {
			_exit = lastChar == KB_ESCAPE;
			//cout << lastChar << endl;
		}

		if (_enemySpawn->CheckSpawn()) {
			Enemy* spawnedEnemy = _enemyPlacer->PlaceEnemy(_maps[_currentMap.y][_currentMap.x]);
			_entityLootables.push_back(spawnedEnemy);
			
			cout << "Spawned enemy: " << spawnedEnemy->GetCoordinates().x << ", " << spawnedEnemy->GetCoordinates().y << std::endl;
		}
	}
}

void GameManager::Setup()
{
	srand(time(NULL));
	_threadManager->StartInputThread(_input);
	_threadManager->StartSpawnThread(_enemySpawn);
}

bool GameManager::CheckExit()
{
	return _exit;
} 

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	this->_currentMap = nextMapCoordinates;
}

void GameManager::SetMapElementInCurrentMap(MapElement* mapElement) {


}
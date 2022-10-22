#include "GameManager.h"

GameManager::GameManager()
{
	_threadManager = new ThreadManager();
	_input = new Input();
	_autosaveTimer = new AutosaveTimer();
	_spawnTimer = new EnemySpawn();
	_gameUI = new GameUI();
	_enemyPlacer = new EnemyPlacer();
	
	for (int i = 0; i < WORLD_MAP_WIDTH; i++)
	{
		std::vector<Map*> auxMap = std::vector<Map*>();

		for (int j = 0; j < WORLD_MAP_HEIGHT; j++)
		{
			auxMap.push_back(new Map(Coordinates(i, j), Coordinates(WORLD_MAP_WIDTH, WORLD_MAP_HEIGHT)));
		}
		_maps.push_back(auxMap);
	}

	_player = new Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))), Coordinates(1, 1));
	SetCurrentMap(_player->GetWorldMapCoordinates());
	_jsonLoader->LoadPlayerFromJson(*_player, "Saves/Player.json");
	_currentMap->SetMapElement(_player);
}

GameManager::~GameManager()
{
	delete _threadManager;
	delete _input;
	delete _autosaveTimer;
	delete _spawnTimer;
	delete _gameUI;
	delete _player;
}

void GameManager::Loop()
{
	while (_player->IsAlive())
	{		
		MapElement* auxMapElement;
		int lastCommand = _input->LastInput();
		
		_player->Move(lastCommand);

		if(lastCommand == KB_E)
		{
			_player->HealYourself();
		}

		auxMapElement = _currentMap->CheckCollision(_player->GetTargetCoordinatesToMove());
		ActionDependOnMapElementType(auxMapElement);

		if (_spawnTimer->CheckSpawn()) {
			int random = int(rand() % 10);
			if (random < 70) {
			 	Character* enemy = _enemyPlacer->PlaceEnemy(_currentMap);
				_currentMap->SetMapElement(enemy);
			}
			else {
				//ADD CHEST
			}
		}

		if (_autosaveTimer->CheckSave()) {
			_jsonSaver->SaveToJson(_player->ToJsonValue(), "Saves/Player.json");
		}
	}
}

void GameManager::ActionDependOnMapElementType(MapElement* mapElement) {

	switch (mapElement->GetMapElementType())
	{
	case NONE:
	
		if (/*_player->GetCurrentWeapon().GetRange() == 2*/false)
		{
			Coordinates weaponTargetCoordinates = GetWeaponTargetCoordinates(_player);
			MapElement* weaponTargetElement = _currentMap->CheckCollision(weaponTargetCoordinates);
			if (weaponTargetElement->GetMapElementType() == ENEMY || weaponTargetElement->GetMapElementType() == CHEST)
			{
				ActionDependOnMapElementType(weaponTargetElement);
			}
		}
		else
		{
			_player->SetLastCoordinates(_player->GetCoordinates());
			_currentMap->MoveCharacter(_player);
			mapElement->~MapElement();
		}			
		break;

	case ENEMY:
		{
			Enemy* enemy = dynamic_cast<Enemy*>(mapElement);
			enemy->ModifyHealthValueOnTakeDamageOrHeal(-1, _currentMap->SelectMapElementPointer(enemy->GetCoordinates()));
		}
		break;

	case CHEST:
		{
			Chest* chest = dynamic_cast<Chest*>(mapElement);
			chest->Drop(_currentMap->SelectMapElementPointer(chest->GetCoordinates()));
		}
		break;

	case POTION:
		{
			Potion* potion = dynamic_cast<Potion*>(mapElement);
			//_player->GetInventory()->AddPotion(potion);
		}	
		break;

	case COIN:
		{
			Coin* coin = dynamic_cast<Coin*>(mapElement);
			//_player->GetInventory()->AddCoin(coin);
		}
		break;

	case WEAPON:
		//_player->GetInventory()->AddWeapon(InventoryWeapon());
		break;

	case PORTAL:

		for (int i = 0; i < _portals.size(); i++)
		{
			if (_portals[i]->GetCoordinates().x == _player->GetTargetCoordinatesToMove().x
				&& _portals[i]->GetCoordinates().y == _player->GetTargetCoordinatesToMove().y)
			{
				_currentMap->SetEmptyBox(_player->GetCoordinates());
				Coordinates _portalCoordinates = _portals[i]->GetCoordinates();
				SetPlayerCoordinates(_portalCoordinates);
				SetCurrentMap(_portals[i]->Teleport(_player->GetWorldMapCoordinates()));
				_currentMap->SetMapElement(_player);
			}
		}
		break;
	}

	_player->SetTargetCoordinatesToMove(_player->GetCoordinates());
}

Coordinates GameManager::GetWeaponTargetCoordinates(Character* character) {

	Coordinates weaponTargetCoordinates = character->GetCoordinates().SubtractCoordinates(character->GetTargetCoordinatesToMove());
	if (weaponTargetCoordinates.y == 0)
	{
		//weaponTargetCoordinates.MultiplyCoordinateX(character->GetCurrentWeapon().GetRange());
	}
	else
	{
		//weaponTargetCoordinates.MultiplyCoordinateY(character->GetCurrentWeapon().GetRange());
	}
	return weaponTargetCoordinates;
}

void GameManager::SetPlayerCoordinates(Coordinates portalCoordinates) {

	if (portalCoordinates.x == 0)
	{
		_player->SetCoordinates(Coordinates(MAP_WIDTH - 2, floor(MAP_HEIGHT / 2)));
	}
	else if (portalCoordinates.x == MAP_WIDTH - 1)
	{
		_player->SetCoordinates(Coordinates(1, floor(MAP_HEIGHT / 2)));
	}
	else if (portalCoordinates.y == 0)
	{
		_player->SetCoordinates(Coordinates(floor(MAP_WIDTH / 2), MAP_HEIGHT - 2));
	}
	else if (portalCoordinates.y == MAP_HEIGHT - 1)
	{
		_player->SetCoordinates(Coordinates(floor(MAP_WIDTH / 2), 1));
	}

	_player->SetTargetCoordinatesToMove(_player->GetCoordinates());
}

void GameManager::Setup()
{
	_threadManager->StartInputThread(_input);
	_threadManager->StartAutoSaveThread(_autosaveTimer);
	_threadManager->StartSpawnThread(_spawnTimer);
}

bool GameManager::CheckExit()
{
	return exit;
}

void GameManager::SetMapElementInCurrentMap(MapElement* mapElement) {

	_currentMap->SetMapElement(mapElement);
}

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	this->_player->SetWorldMapCoordinates(nextMapCoordinates);
	this->_currentMap = _maps[_player->GetWorldMapCoordinates().x][_player->GetWorldMapCoordinates().y];
	this->_currentMapElements = _currentMap->GetMapElements();	
	this->_portals = _currentMap->GetPortals();
	ConsoleControl::SetPosition(0, 0);
	this->_currentMap->Draw();
}
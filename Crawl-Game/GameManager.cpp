#include "GameManager.h"
#include "ConsoleControl.h"
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
	_player = new Player((Coordinates(floor(MAP_HEIGHT / 2), floor(MAP_WIDTH / 2))));
	_currentMap->SetMapElement(_player);
}

GameManager::~GameManager()
{
	delete threadManager;
	delete input;
	delete gameUI;
	delete _player;
}

void GameManager::Loop()
{
	char lastChar = input->LastInput();
	if (lastChar != 0) {
		//exit = lastChar == KB_ESCAPE;
		cout << lastChar << endl;
	}
	while (_player->IsAlive())
	{		
		DrawMapElements();

		char input;
		cin >> input;

		MapElement* auxMapElement;

		if (input == 'd')
		{
			_player->SetTargetCoordinatesToMove(Coordinates(_player->GetCoordinates().x + 1, _player->GetCoordinates().y));
		}
		else if (input == 'a')
		{
			_player->SetTargetCoordinatesToMove(Coordinates(_player->GetCoordinates().x - 1, _player->GetCoordinates().y));
		}
		else if (input == 'w')
		{
			_player->SetTargetCoordinatesToMove(Coordinates(_player->GetCoordinates().x, _player->GetCoordinates().y - 1));
		}
		else if (input == 's')
		{
			_player->SetTargetCoordinatesToMove(Coordinates(_player->GetCoordinates().x, _player->GetCoordinates().y + 1));
		}
		else if(input == 'e')
		{
			_player->HealYourself();
		}

		auxMapElement = _currentMap->CheckCollision(_player->GetTargetCoordinatesToMove());
		ActionDependOnMapElementType(auxMapElement);
	}
}

void GameManager::ActionDependOnMapElementType(MapElement* mapElement) {

	switch (mapElement->GetMapElementType())
	{
	case NONE:
	
		if (/*_player->GetCurrentWeapon().GetRange() == 2*/false)
		{
			Coordinates weaponTargetCoordinates = GetWeaponTargetCoordinates(_player);
			MapElement* weaponTargetElement = _maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->CheckCollision(weaponTargetCoordinates);
			if (weaponTargetElement->GetMapElementType() == ENEMY || weaponTargetElement->GetMapElementType() == CHEST)
			{
				ActionDependOnMapElementType(weaponTargetElement);
			}
		}
		else
		{
			_currentMap->MoveCharacter(_player);
			mapElement->~MapElement();
		}
			
		break;

	case ENEMY:
		{
			Enemy* enemy = dynamic_cast<Enemy*>(mapElement);
			enemy->ModifyHealthValueOnTakeDamageOrHeal(-1);
		}
		break;
	case CHEST:
		{
			Chest* chest = dynamic_cast<Chest*>(mapElement);
			chest->Drop();
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
				SetCurrentMap(_portals[i]->Teleport(_currentWorldMapCoordinates));
				_currentMap->SetMapElement(_player);
			}
		}
		break;
	}

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
	threadManager->StartInputThread(input);
}

bool GameManager::CheckExit()
{
	return exit;
}

void GameManager::SetMapElementInCurrentMap(MapElement* mapElement) {

	_currentMap->SetMapElement(mapElement);
}

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	this->_currentWorldMapCoordinates = nextMapCoordinates;
	this->_currentMap = _maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y];
	this->_currentMapElements = _currentMap->GetMapElements();	
	this->_portals = _currentMap->GetPortals();
	ConsoleControl::SetPosition(0, 0);
	this->_currentMap->Draw();
}

void GameManager::DrawMapElements() {

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			MapElement** mapElementPointer = _currentMap->SelectMapElementPointer(Coordinates(j, i));

			if (mapElementPointer[0]->GetMapElementType() != WALL
				&& mapElementPointer[0]->GetMapElementType() != PORTAL)
			{
				ConsoleControl::SetPosition(j, i);
				mapElementPointer[0]->Draw();
			}
		}
	}
}
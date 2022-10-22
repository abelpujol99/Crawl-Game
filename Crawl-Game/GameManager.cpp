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
	_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->SetMapElement(_player);
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

		auxMapElement = _maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]
			->CheckCollision(_player->GetTargetCoordinatesToMove());
		ActionDependOnMapElementType(auxMapElement);
	}
}

void GameManager::ActionDependOnMapElementType(MapElement* mapElement) {

	switch (mapElement->GetMapElementType())
	{
	case NONE:
	{
		_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->MoveCharacter(_player);
		mapElement->~MapElement();
		//std::pair<MapElement*, MapElement*> mapElementsToSwap{ _player, mapElement };
		//_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->SwapMapElementsInCurrentMap(mapElementsToSwap);
	}		
		break;

	/*case ENEMY:

		break;
	case CHEST:

		break;
	case POTION:

		break;
	case COIN:

		break;
	case WEAPON:

		break;
	case WALL:

		break;*/
	case PORTAL:
		for (int i = 0; i < _portals.size(); i++)
		{
			if (_portals[i]->GetCoordinates().x == _player->GetTargetCoordinatesToMove().x
				&& _portals[i]->GetCoordinates().y == _player->GetTargetCoordinatesToMove().y)
			{
				_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->SetEmptyBox(_player->GetCoordinates());
				Coordinates _portalCoordinates = _portals[i]->GetCoordinates();
				if (_portalCoordinates.x == 0)
				{
					_player->SetCoordinates(Coordinates(MAP_WIDTH - 2, floor(MAP_HEIGHT / 2)));
				}
				else if (_portalCoordinates.x == MAP_WIDTH - 1)
				{
					_player->SetCoordinates(Coordinates(1, floor(MAP_HEIGHT / 2)));
				}
				else if (_portalCoordinates.y == 0) 
				{
					_player->SetCoordinates(Coordinates(floor(MAP_WIDTH / 2), MAP_HEIGHT - 2));
				}
				else if (_portalCoordinates.y == MAP_HEIGHT - 1)
				{
					_player->SetCoordinates(Coordinates(floor(MAP_WIDTH / 2), 1));
				}
				SetCurrentMap(_portals[i]->Teleport(_currentWorldMapCoordinates));
				_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->SetMapElement(_player);
			}
		}
		break;
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

void GameManager::SetMapElementInCurrentMap(MapElement* mapElement) {

	_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->SetMapElement(mapElement);
}

void GameManager::SetCurrentMap(Coordinates nextMapCoordinates) {

	this->_currentWorldMapCoordinates = nextMapCoordinates;
	this->_currentMap = _maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->GetMapElements();
	this->_portals = _maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->GetPortals();
	ConsoleControl::SetPosition(0, 0);
	this->_maps[_currentWorldMapCoordinates.x][_currentWorldMapCoordinates.y]->Draw();
}

void GameManager::DrawMapElements() {

	for (int i = 0; i < MAP_HEIGHT; i++)
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
#pragma once
#include "Coordinates.h"
#include "ConsoleControl.h"

struct Coordinates;

enum MapElementType {PLAYER, ENEMY, CHEST, COIN, POTION, WEAPON, PORTAL, WALL, NONE};

class MapElement
{

protected:
	
	MapElementType _mapElementType;
	Coordinates _currentCoordinates;
	Coordinates _currentWorldMapCoordinates;

public:

	~MapElement();
	void SetCoordinates(Coordinates coordinates);
	Coordinates GetCoordinates();
	virtual void Draw() = 0;
	MapElementType GetMapElementType();
};


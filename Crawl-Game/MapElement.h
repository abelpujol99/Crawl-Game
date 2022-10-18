#pragma once
#include "Coordinates.h"

struct Coordinates;

enum MapElementType {PLAYER, ENEMY, CHEST, COIN, POTION, WEAPON, PORTAL, WALL, NONE};

class MapElement
{

protected:
	
	MapElementType _mapElementType;
	Coordinates _currentCoordinates;

public:
	
	void SetCoordinates(Coordinates coordinates);
	virtual void Draw() = 0;
	Coordinates GetCoordinates();
	MapElementType GetMapElementType();
};


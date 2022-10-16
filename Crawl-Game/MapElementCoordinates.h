#pragma once
#include "Coordinates.h"

struct Coordinates;

enum MapElementType {PLAYER, ENEMY, CHEST, COIN, POTION, WEAPON, PORTAL, WALL};

class MapElementCoordinates
{

protected:
	
	MapElementType _mapElementType;
	Coordinates _currentCoordinates;

public:
	
	void SetCoordinates(Coordinates coordinates);
	Coordinates GetCoordinates();
	virtual void Draw() = 0;

};


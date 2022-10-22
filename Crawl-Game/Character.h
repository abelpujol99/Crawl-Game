#pragma once
#include "MapElement.h"
#include "EntityLootable.h"
//#include "Chest.h"
//#include "Enemy.h"

class MapElement;

class Character : public MapElement
{

protected:

	//InventoryWeapon _currentWeapon;
	int _health;
	Coordinates _targetCoordinatesToMove;
	Coordinates _lastCoordinates;

public:

	Character();
	Character(Coordinates coordinates);
	virtual ~Character();
	virtual void Move() = 0;
	bool IsAlive();
	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);
	void SetTargetCoordinatesToMove(Coordinates coordinates);
	void SetLastCoordinates(Coordinates coordinates);
	//InventoryWeapon GetCurrentWeapon();
	Coordinates GetTargetCoordinatesToMove();
	Coordinates GetLastCoordinates();
};


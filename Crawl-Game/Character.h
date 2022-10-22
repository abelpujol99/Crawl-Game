#pragma once
#include "MapElement.h"
#include "EntityLootable.h"
#include "InventoryWeapon.h"

class MapElement;

class Character : public MapElement
{

protected:

	InventoryWeapon _currentWeapon;
	int _health;
	Coordinates _targetCoordinatesToMove;
	Coordinates _lastCoordinates;

public:

	Character();
	Character(Coordinates coordinates, Coordinates worldMapCoordinates);
	virtual ~Character();
	virtual void Move(int lastCommand) = 0;
	bool IsAlive();
	int GetHealth();
	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);
	void SetTargetCoordinatesToMove(Coordinates coordinates);
	InventoryWeapon GetCurrentWeapon();
	void SetLastCoordinates(Coordinates coordinates);
	Coordinates GetTargetCoordinatesToMove();
	Coordinates GetLastCoordinates();
};


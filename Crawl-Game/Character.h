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

public:

	Character();
	Character(Coordinates coordinates);
	virtual ~Character();
	virtual void Move() = 0;
	bool IsAlive();
	int GetHealth();
	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);
	void SetTargetCoordinatesToMove(Coordinates coordinates);
	InventoryWeapon GetCurrentWeapon();
	Coordinates GetTargetCoordinatesToMove();
};


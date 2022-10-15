#pragma once
#include "MapElementCoordinates.h"
//#include "InventoryWeapon.h"

class MapElementCoordinates;
class InventoryWeapon;

class Character : MapElementCoordinates
{

protected:

	//Weapon _currentWeapon;
	int _health;

	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);

public:

	Character(Coordinates coordinates);
	virtual void Move() = 0;
	void Attack(Character* characterToAttack);
};


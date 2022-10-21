#pragma once
#include "MapElement.h"
#include "EntityLootable.h"
//#include "Chest.h"
//#include "Enemy.h"

class MapElement;

class Character : public MapElement
{

protected:

	//Weapon _currentWeapon;
	int _health;
	Coordinates _targetCoordinatesToMove;

public:

	Character();
	Character(Coordinates coordinates);
	virtual ~Character();
	virtual void Move() = 0;
	void IsAlive();
	virtual void Die() = 0;
	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);
	//virtual void InteractWithEntityLootable(EntityLootable* entityLootable) = 0;
	void SetTargetCoordinatesToMove(Coordinates coordinates);
	Coordinates GetTargetCoordinatesToMove();
};


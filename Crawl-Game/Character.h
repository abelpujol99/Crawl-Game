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
	bool IsAlive();
	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);
	void SetTargetCoordinatesToMove(Coordinates coordinates);
	Coordinates GetTargetCoordinatesToMove();
};


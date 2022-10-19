#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "MapElement.h"
//#include "Player.h"
//#include "DropLootable.h"
#include "Potion.h"
#include "Coin.h"
#include "Weapon.h"

class MapElement;
class DropLootable;
class Potion;
class Coin;
class Weapon;

class EntityLootable : public MapElement
{

protected:
	
	DropLootable* _drop = nullptr;

	void Drop();

public:

	EntityLootable();
	virtual ~EntityLootable();
	void Spawn(Coordinates coordinate);
	//virtual void AcceptCharacter(Player* player) = 0;
};


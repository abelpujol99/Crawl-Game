#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "MapElement.h"
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


public:

	EntityLootable();
	virtual ~EntityLootable();
	void Drop();
	void Spawn(Coordinates coordinate);
};


#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "MapElementCoordinates.h"
#include "DropLootable.h"
#include "Potion.h"
#include "Coin.h"
#include "Weapon.h"

class MapElementCoordinates;
class DropLootable;
class Potion;
class Coin;
class Weapon;

class EntityLootable : public MapElementCoordinates
{

protected:
	
	DropLootable* _drop = nullptr;

public:

	EntityLootable();
	void Drop();
	void Spawn(Coordinates coordinate);
};


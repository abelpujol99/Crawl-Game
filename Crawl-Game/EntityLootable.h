#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "MapElement.h"
#include "Character.h"
#include "Potion.h"
#include "Coin.h"
#include "Weapon.h"

class Character;
class MapElement;
class DropLootable;
class Potion;
class Coin;
class Weapon;

class EntityLootable : public MapElement
{

protected:
	
	DropLootable* _drop = nullptr;
	void SetDrop();

public:

	EntityLootable();
	EntityLootable(Coordinates worldMapCoordinates);
	virtual ~EntityLootable();
	virtual void Drop(MapElement** mapElementPointer) = 0;
	Coordinates GetWorldMapCoordinates();
	void Spawn(Coordinates coordinate);
};


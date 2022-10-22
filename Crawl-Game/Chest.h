#pragma once
#include <iostream>
#include "EntityLootable.h"

class Chest : public EntityLootable
{
public:

	Chest(Coordinates coordinates, Coordinates worldMapCoordinates);
	void Drop(MapElement** mapElementPointer) override;
	void Draw() override;
};


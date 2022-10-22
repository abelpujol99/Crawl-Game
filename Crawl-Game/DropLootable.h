#pragma once
#include "MapElement.h"

class MapElementCooridnates;

class DropLootable : public MapElement {

	MapElement* ownerPointer;

public:

	DropLootable();
	void SetWorldMapCoordinates(Coordinates currentWorldMapCoordinates);
};


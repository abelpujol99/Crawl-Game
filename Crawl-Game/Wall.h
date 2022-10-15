#pragma once
#include <iostream>
#include "MapElementCoordinates.h"

class MapElementCoordinates;

class Wall : public MapElementCoordinates
{

public:

	Wall(Coordinates coordinates);
	void Draw() override;

};


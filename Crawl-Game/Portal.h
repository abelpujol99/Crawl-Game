#pragma once
#include <iostream>
#include "MapElementCoordinates.h"

class Portal : public MapElementCoordinates
{

public:

	Portal(Coordinates coordinates);
	void Teleport(Coordinates& currentPlayerMinimapCoordinates);
	void Draw() override;
};


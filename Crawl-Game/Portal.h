#pragma once
#include <iostream>
#include "MapElement.h"

class Portal : public MapElement
{

public:

	Portal(Coordinates coordinates);
	void Teleport(Coordinates& currentPlayerMinimapCoordinates);
	void Draw() override;
};
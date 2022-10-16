#pragma once
#include <iostream>
#include "MapElement.h"

class MapElement;

class Block : public MapElement
{

public:

	Block(Coordinates coordinates);
	void Draw() override;

};


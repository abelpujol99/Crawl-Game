#pragma once
#include <iostream>
#include "MapElement.h"

enum CardinalPoints {NORTH = 0, EAST = 1, WEST = 2, SOUTH = 3};

class Portal : public MapElement
{

private:

	CardinalPoints _cardinalPoint;


public:
	
	Portal(Coordinates coordinates);
	/////WHEN ALL WORKS FINE REDO PORTALS!!!!!
	//Portal(Coordinates coordinates, CardinalPoints cardinalPoint);
	Coordinates Teleport(Coordinates currentWorldMapCoordinates);
	void Draw() override;
};
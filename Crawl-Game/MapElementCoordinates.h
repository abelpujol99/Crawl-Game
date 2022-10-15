#pragma once
#include "Coordinates.h"

struct Coordinates;

class MapElementCoordinates
{

protected:

	Coordinates _currentCoordinates;

public:
	
	void SetCoordinates(Coordinates coordinates);
	Coordinates GetCoordinates();
	virtual void Draw() = 0;

};


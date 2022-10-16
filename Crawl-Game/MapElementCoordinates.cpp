#include "MapElementCoordinates.h"

void MapElementCoordinates::SetCoordinates(Coordinates coordinates) {

	this->_currentCoordinates = coordinates;
}

Coordinates MapElementCoordinates::GetCoordinates()
{
	return this->_currentCoordinates;
}

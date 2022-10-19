#include "MapElement.h"

MapElement::~MapElement()
{
}

void MapElement::SetCoordinates(Coordinates coordinates) {

	this->_currentCoordinates = coordinates;
}

Coordinates MapElement::GetCoordinates()
{
	return this->_currentCoordinates;
}

MapElementType MapElement::GetMapElementType() {
	return this->_mapElementType;
}
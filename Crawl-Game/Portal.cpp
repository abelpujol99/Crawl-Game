#include "Portal.h"

#define MAP_WIDTH 7
#define MAP_HEIGHT 7

Portal::Portal(Coordinates coordinates){

	this->SetCoordinates(coordinates);
	_mapElementType = PORTAL;
}

//Portal::Portal(Coordinates coordinates, CardinalPoints cardinalPoint) : _cardinalPoint(cardinalPoint) {
//
//	this->SetCoordinates(coordinates);
//	_mapElementType = PORTAL;
//}

Coordinates Portal::Teleport(Coordinates currentWorldMapCoordinates){

	if (_currentCoordinates.x == floor(MAP_WIDTH - 1) / 2)
	{
		switch (_currentCoordinates.y)
		{
		case 0:
			currentWorldMapCoordinates.y--;
			break;

		case MAP_HEIGHT - 1:
			currentWorldMapCoordinates.y++;
			break;
		}
	}
	else if (_currentCoordinates.y == floor(MAP_HEIGHT - 1) / 2)
	{
		switch (_currentCoordinates.x)
		{
		case 0:
			currentWorldMapCoordinates.x--;
			break;

		case MAP_WIDTH - 1:
			currentWorldMapCoordinates.x++;
			break;
		}
	}
	return currentWorldMapCoordinates;
}

void Portal::Draw() {

	std::cout << 'T';
}
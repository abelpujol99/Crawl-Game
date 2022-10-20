#include "Portal.h"

#define MAP_WIDTH 7
#define MAP_HEIGHT 7

Portal::Portal(Coordinates coordinates) {

	this->SetCoordinates(coordinates);
	_mapElementType = PORTAL;
}

void Portal::Teleport(Coordinates& currentPlayerMinimapCoordinates){

	if (_currentCoordinates.x == (MAP_WIDTH - 1) / 2)
	{
		switch (_currentCoordinates.y)
		{
		case 0:
			currentPlayerMinimapCoordinates.y--;
			return;

		case MAP_HEIGHT - 1:
			currentPlayerMinimapCoordinates.y++;
			return;
		}
	}
	else if (_currentCoordinates.y == (MAP_HEIGHT - 1) / 2)
	{
		switch (_currentCoordinates.x)
		{
		case 0:
			currentPlayerMinimapCoordinates.x--;
			return;

		case MAP_WIDTH - 1:
			currentPlayerMinimapCoordinates.x++;
			return;
		}
	}
}

void Portal::Draw() {

	std::cout << 'T';
}
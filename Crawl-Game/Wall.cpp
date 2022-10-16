#include "Wall.h"

Wall::Wall(Coordinates coordinates) {

	this->SetCoordinates(coordinates);
	_mapElementType = WALL;
}

void Wall::Draw() {

	std::cout << '#' << std::endl;
}


#include "Wall.h"

Wall::Wall(Coordinates coordinates) {

	this->SetCoordinates(coordinates);
}

void Wall::Draw() {

	std::cout << '#' << std::endl;
}


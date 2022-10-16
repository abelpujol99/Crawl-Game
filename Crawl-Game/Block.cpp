#include "Block.h"

Block::Block(Coordinates coordinates) {

	this->SetCoordinates(coordinates);
	_mapElementType = WALL;
}

void Block::Draw() {

	std::cout << '#' << std::endl;
}


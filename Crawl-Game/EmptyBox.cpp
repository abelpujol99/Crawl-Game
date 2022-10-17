#include "EmptyBox.h"

EmptyBox::EmptyBox(Coordinates coordinates) {

	this->SetCoordinates(coordinates);
	this->_mapElementType = NONE;
}

void EmptyBox::Draw() {

	std::cout << ' ';
}
#include "EmptyBox.h"

EmptyBox::EmptyBox(Coordinates coordinates) {

	this->SetCoordinates(coordinates);
	this->_mapElementType = NONE;
}

void EmptyBox::Draw() {
	
	ConsoleControl::SetPosition(this->GetCoordinates().x, this->GetCoordinates().y);
	std::cout << ' ';
}
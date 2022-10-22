#include "DropLootable.h"

DropLootable::DropLootable(){
}

void DropLootable::SetWorldMapCoordinates(Coordinates currentWorldMapCoordinates) {

	this->_currentWorldMapCoordinates = currentWorldMapCoordinates;
	ConsoleControl::SetPosition(this->GetCoordinates().x, this->GetCoordinates().y);
	this->Draw();
}
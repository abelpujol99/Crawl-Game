#include "Chest.h"

Chest::Chest(Coordinates coordinates, Coordinates worldMapCoordinates) : EntityLootable(worldMapCoordinates) {

	_mapElementType = CHEST;
	_currentCoordinates = coordinates;
}

void Chest::Drop(MapElement** mapElementPointer) {

	this->_drop->SetCoordinates(this->GetCoordinates());
	this->_drop->SetWorldMapCoordinates(this->GetWorldMapCoordinates());
	*mapElementPointer = _drop;
	this->~Chest();
}

void Chest::Draw() {

	ConsoleControl::SetPosition(this->GetCoordinates().x, this->GetCoordinates().y);
	std::cout << 'C';
}
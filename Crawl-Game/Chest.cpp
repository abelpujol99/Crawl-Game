#include "Chest.h"

Chest::Chest(Coordinates worldMapCoordinates) : EntityLootable(worldMapCoordinates) {
}

void Chest::Drop(MapElement** mapElementPointer) {

	this->_drop->SetCoordinates(this->GetCoordinates());
	this->_drop->SetWorldMapCoordinates(this->GetWorldMapCoordinates());
	*mapElementPointer = _drop;
	this->~Chest();
}

void Chest::Draw() {

	std::cout << 'C';
}
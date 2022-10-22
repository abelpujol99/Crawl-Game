#include "EntityLootable.h"

EntityLootable::EntityLootable() {

	SetDrop();
}

EntityLootable::EntityLootable(Coordinates currentWorldMapCoordinates) : MapElement(currentWorldMapCoordinates) {

	SetDrop();
}

EntityLootable::~EntityLootable() {
}

void EntityLootable::SetDrop() {

	srand(time(NULL));

	switch (rand() % 3)
	{
	case 0:
		this->_drop = new Potion();
		break;

	case 1:
		this->_drop = new Coin();
		break;

	case 2:
		this->_drop = new Weapon();
		break;

	default:
		break;
	}
}



Coordinates EntityLootable::GetWorldMapCoordinates() {

	return this->_currentWorldMapCoordinates;
}
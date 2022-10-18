#include "EntityLootable.h"

EntityLootable::EntityLootable() {

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

void EntityLootable::Drop() {

	this->_drop->SetCoordinates(this->GetCoordinates());
}

void EntityLootable::Spawn(Coordinates coordinate) {

	//TODO: Get free coordinates from Map through GameManager

}

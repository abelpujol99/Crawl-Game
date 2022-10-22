#include "Character.h"
//#include "Weapon.h"

Character::Character() {

	this->_health = 5;
}

Character::Character(Coordinates coordinates, Coordinates worldMapCoordinates) : MapElement(worldMapCoordinates) {
	
	this->_currentCoordinates = coordinates;
	//this->_currentWeapon = InventoryWeapon("Sword", 1);
	this->_health = 5;
}

Character::~Character() {
}

bool Character::IsAlive() {

	return _health > 0;
}

void Character::ModifyHealthValueOnTakeDamageOrHeal(int modifyValue) {

	this->_health += modifyValue;
}

void Character::SetTargetCoordinatesToMove(Coordinates coordinates) {

	this->_targetCoordinatesToMove = coordinates;
}

void Character::SetLastCoordinates(Coordinates coordinates) {

	this->_lastCoordinates = coordinates;
}

/*InventoryWeapon Character::GetCurrentWeapon() {

	return _currentWeapon;
}*/

Coordinates Character::GetTargetCoordinatesToMove() {

	return this->_targetCoordinatesToMove;
}

Coordinates Character::GetLastCoordinates() {

	return this->_lastCoordinates;
}
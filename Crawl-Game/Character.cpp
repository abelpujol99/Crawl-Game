#include "Character.h"
//#include "Weapon.h"

Character::Character(Coordinates coordinates) {
	
	this->_currentCoordinates = coordinates;
	//this->_currentWeapon = InventoryWeapon("Sword", 1);
	this->_health = 5;
}

void Character::ModifyHealthValueOnTakeDamageOrHeal(int modifyValue) {

	this->_health += modifyValue;
}

void Character::IsAlive() {

	if (this->_health <= 0)
	{
		this->Die();
	}
}

void Character::SetTargetCoordinatesToMove(Coordinates coordinates) {

	this->_targetCoordinatesToMove = coordinates;
}

Coordinates Character::GetTargetCoordinatesToMove() {

	return this->_targetCoordinatesToMove;
}
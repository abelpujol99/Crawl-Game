#include "Character.h"
//#include "Weapon.h"

Character::Character(Coordinates coordinates) {
	
	this->_currentCoordinates = coordinates;
	//this->_currentWeapon = InventoryWeapon("Sword", 1);
	this->_health = 5;
}

void Character::Attack(Character* characterToAttack) {

	characterToAttack->ModifyHealthValueOnTakeDamageOrHeal(1);
}

void Character::ModifyHealthValueOnTakeDamageOrHeal(int modifyValue) {

	this->_health += modifyValue;
}
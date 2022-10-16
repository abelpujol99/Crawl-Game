#include "Player.h"

Player::Player(Coordinates coordinates) : Character (coordinates) {

	//this->_inventory = Inventory();
	_mapElementType = PLAYER;
}

void Player::Move() {


}

//void Player::InteractWithEntityLootable(EntityLootable* entityLootable) {
//
//	entityLootable->AcceptCharacter(this);
//}

void Player::HealYourself() {

	//this->inventory.UsePotion();
}

/*void Player::ChangeCurrentWeapon(InventoryWeapon weaponOfInventory)
{
	this->_currentWeapon = weaponOfInventory;
}*/

void Player::Die() {

	//TODO: RESET THE GAME
}

void Player::Draw() {

	std::cout << 'P' << std::endl;
}
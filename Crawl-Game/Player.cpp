#include "Player.h"

Player::Player() : Character() {

	_mapElementType = PLAYER;
}

Player::Player(Coordinates coordinates) : Character (coordinates) {

	//this->_inventory = Inventory();
	_mapElementType = PLAYER;
}

void Player::Move() {


}

void Player::HealYourself() {

	//this->inventory.UsePotion();
}

/*Inventory Player::GetInventory() {

	return inventory;
}*/

/*void Player::ChangeCurrentWeapon(InventoryWeapon weaponOfInventory)
{
	this->_currentWeapon = weaponOfInventory;
}*/

void Player::Draw() {

	std::cout << 'P';
}
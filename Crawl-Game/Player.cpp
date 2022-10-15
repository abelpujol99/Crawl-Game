#include "Player.h"

Player::Player(Coordinates coordinates) : Character (coordinates) {

	//this->_inventory = Inventory();
}

void Player::HealYourself() {

	//this->inventory.UsePotion();
}

/*void Player::ChangeCurrentWeapon(InventoryWeapon weaponOfInventory)
{
	this->_currentWeapon = weaponOfInventory;
}*/

bool Player::IsAlive() {

	return this->_health >= 0;
}

void Player::Draw() {

	std::cout << 'P' << std::endl;
}

#include "Player.h"

Player::Player() : Character() {

	_mapElementType = PLAYER;
}

Player::Player(Coordinates coordinates) : Character (coordinates) {

	this->_inventory = Inventory();
	_mapElementType = PLAYER;
}

void Player::Move() {


}

void Player::HealYourself() {

	this->_inventory.UsePotion();
}

Inventory Player::GetInventory() {

	return _inventory;
}

void Player::ChangeCurrentWeapon(InventoryWeapon weaponOfInventory)
{
    _inventory.SwapWeapons();
    this->_currentWeapon = _inventory.GetWeapons().first;
}

void Player::Draw() {

	std::cout << 'P';
}

Player* Player::Parse(Json::Value jsonValue)
{
    Player* newPlayer = new Player();
    try
    {
        newPlayer->_currentCoordinates = *Coordinates::Parse(jsonValue);
        //TODO: current map
        newPlayer->_health = jsonValue["Health"].asInt();
        return newPlayer;
    }
    catch (const std::exception&)
    {
        delete newPlayer;
        return nullptr;
    }
}

Json::Value Player::ToJsonValue()
{
    Json::Value jsonValue = _currentCoordinates.ToJsonValue();
    //TODO: current map
    jsonValue["Health"] = _health;

    return jsonValue;
}

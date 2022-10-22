#include "Player.h"

Player::Player() : Character() {

	_mapElementType = PLAYER;
}

Player::Player(Coordinates coordinates, Coordinates worldMapCoordinates) : Character (coordinates, worldMapCoordinates) {

	//this->_inventory = Inventory();
	_mapElementType = PLAYER;
}

void Player::Move(int lastCommand) {

	if (lastCommand == KB_D)
	{
		this->SetTargetCoordinatesToMove(Coordinates(this->GetCoordinates().x + 1, this->GetCoordinates().y));
	}
	else if (lastCommand == KB_A)
	{
		this->SetTargetCoordinatesToMove(Coordinates(this->GetCoordinates().x - 1, this->GetCoordinates().y));
	}
	else if (lastCommand == KB_W)
	{
		this->SetTargetCoordinatesToMove(Coordinates(this->GetCoordinates().x, this->GetCoordinates().y - 1));
	}
	else if (lastCommand == KB_S)
	{
		this->SetTargetCoordinatesToMove(Coordinates(this->GetCoordinates().x, this->GetCoordinates().y + 1));
	}

	this->Draw();

}

void Player::SetWorldMapCoordinates(Coordinates coordinates) {

    this->_currentWorldMapCoordinates = coordinates;
}

Coordinates Player::GetWorldMapCoordinates() {

    return _currentWorldMapCoordinates;
}

void Player::HealYourself() {

	//this->inventory.UsePotion();
}

/*void Player::ModifyHealthValueOnTakeDamageOrHeal(int modifyValue) {

    this->_health += modifyValue;
}*/

/*Inventory Player::GetInventory() {

	return inventory;
}*/

/*void Player::ChangeCurrentWeapon(InventoryWeapon weaponOfInventory)
{
	this->_currentWeapon = weaponOfInventory;
}*/

void Player::Draw() {

    ConsoleControl::SetPosition(this->GetCoordinates().x, this->GetCoordinates().y);
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

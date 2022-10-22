#include "Player.h"

Player::Player() : Character() {

	_mapElementType = PLAYER;
}

Player::Player(Coordinates coordinates, Coordinates worldMapCoordinates) : Character (coordinates, worldMapCoordinates) {

	_health = 5;
	this->_inventory = new Inventory(_currentWeapon);
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
	if (this->_inventory.GetPotionAmount() > 0) {
		ModifyHealthValueOnTakeDamageOrHeal(this->_inventory.UsePotion());
	}
}

void Player::ModifyHealthValueOnTakeDamageOrHeal(int modifyValue) {

    this->_health += modifyValue;
	if (_health > MAX_HP) {
		_health = MAX_HP;
	}
}

Inventory* Player::GetInventory() {

	return _inventory;
}

void Player::ChangeCurrentWeapon()
{
    _inventory->SwapWeapons();
    this->_currentWeapon = _inventory->GetWeapons().first;
}

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
		newPlayer->_currentWorldMapCoordinates.x = jsonValue["GlobalPosX"].asInt();
		newPlayer->_currentWorldMapCoordinates.y = jsonValue["GlobalPosY"].asInt();
        newPlayer->_health = jsonValue["Health"].asInt();
		newPlayer->_inventory.ModifyCoins(jsonValue["Coins"].asInt());
		int potionAmount = jsonValue["Potions"].asInt();
		for (int i = 0; i < potionAmount; i++) {
			newPlayer->_inventory.AddPotion(Potion());
		}
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
	jsonValue["GlobalPosX"] = _currentWorldMapCoordinates.x;
	jsonValue["GlobalPosY"] = _currentWorldMapCoordinates.y;
    jsonValue["Health"] = _health;
    jsonValue["Coins"] = _inventory.GetCoins();
    jsonValue["Potions"] = _inventory.GetPotionAmount();

    return jsonValue;
}

#pragma once
#include <iostream>
#include "Character.h"
#include "Inventory.h"
#include "json/json.h"

class Player : public Character {

private: 

	Inventory _inventory;

public:

	Player();
	Player(Coordinates coodinates, Coordinates worldMapCoordinates);
	void Move(int lastCommand) override;
	void HealYourself();
	void ModifyHealthValueOnTakeDamageOrHeal(int modifyValue);
	Inventory GetInventory();
	void ChangeCurrentWeapon(InventoryWeapon weaponOfInventory);
	void SetWorldMapCoordinates(Coordinates coordinates);
	Coordinates GetWorldMapCoordinates();
	void Draw() override;

	static Player* Parse(Json::Value jsonValue);
	Json::Value ToJsonValue();
};
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
	Player(Coordinates coodinates);
	void Move() override;	
	void HealYourself();
	Inventory GetInventory();
	void ChangeCurrentWeapon(InventoryWeapon weaponOfInventory);
	void Draw() override;

	static Player* Parse(Json::Value jsonValue);
	Json::Value ToJsonValue();
};
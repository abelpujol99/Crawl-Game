#pragma once
#include <iostream>
#include "Character.h"
//#include "InventoryWeapon.h"
#include "json/json.h"
class InventoryWeapon;

class Player : public Character {

private: 

	//Inventory _inventory;

public:

	Player();
	Player(Coordinates coodinates);
	void Move() override;	
	void HealYourself();
	//Inventory GetInventory();
	//void ChangeCurrentWeapon(InventoryWeapon weaponOfInventory);
	void Draw() override;
	//void AcceptCharacter();

	static Player* Parse(Json::Value jsonValue);
	Json::Value ToJsonValue();
};
#pragma once
#include <iostream>
#include "Character.h"
//#include "InventoryWeapon.h"

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
};
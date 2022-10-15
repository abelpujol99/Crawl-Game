#pragma once
#include <iostream>
#include "Character.h"

class Player : public Character {

private: 

	//Inventory _inventory;

public:

	Player(Coordinates coodinates);
	void HealYourself();
	//void ChangeCurrentWeapon(InventoryWeapon weaponOfInventory);
	bool IsAlive();
	void Draw() override;
};
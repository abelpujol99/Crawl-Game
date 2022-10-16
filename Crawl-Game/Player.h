#pragma once
#include <iostream>
#include "Character.h"
#include "EntityLootable.h"
//#include "InventoryWeapon.h"

class InventoryWeapon;

class Player : public Character {

private: 

	//Inventory _inventory;

public:

	Player(Coordinates coodinates);
	void Move() override;
	//void InteractWithEntityLootable(EntityLootable* entityLootable) override;
	void HealYourself();
	//void ChangeCurrentWeapon(InventoryWeapon weaponOfInventory);
	void Die() override;
	void Draw() override;
	//void AcceptCharacter();
};
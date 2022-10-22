#pragma once
#include "InventoryWeapon.h" 
#include "Potion.h"
#include "Weapon.h"

#include <utility>

class Inventory
{
private:
	std::pair<InventoryWeapon,InventoryWeapon> _weaponsInInventory;
	Potion _potion;
	int _coins;
	int _Inventorycounter;
	InventoryWeapon ChangeWeapon(InventoryWeapon holding);
public:
	Inventory();

	std::pair<InventoryWeapon,InventoryWeapon> GetWeapons();

	void AddWeaponToInventory(InventoryWeapon weapon);

	int GetPotions();
	void ModifyPotions(int change);
	int UsePotion(int heal);

	int GetCoins();
	void ModifyCoins(int change);
};
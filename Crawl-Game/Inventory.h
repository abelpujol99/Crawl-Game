#pragma once
#include "InventoryWeapon.h" 
#include "Potion.h"
#include "Weapon.h"

#include <vector>
#include <utility>

class Inventory
{
private:
	std::pair<InventoryWeapon,InventoryWeapon> _weaponsInInventory;
	std::vector<Potion> _potion;
	int _coins;
	int _Inventorycounter;
	
	InventoryWeapon ChangeWeapon(InventoryWeapon holding);

public:
	Inventory();   

	std::pair<InventoryWeapon,InventoryWeapon> GetWeapons();

	void AddWeaponToInventory(InventoryWeapon weapon);

	int UsePotions();
	void AddPotion(Potion potion);

	int GetCoins();
	void ModifyCoins(int change);
};
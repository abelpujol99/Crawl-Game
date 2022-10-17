#pragma once
#include "InventoryWeapon.h" 
#include "Potion.h"
#include "Weapon 
#include <vector>

class Inventory
{
private:
	std::vector<InventoryWeapon> _weaponsInInventory;
	Potion _poition;
	int _coins;
public:
	Inventory();
	~Inventory();

	int UsePotion();
	int GetPotions();
	int GetCoins();

	Weapon 	ChangeWeapon();
	_weaponsInInventory GetWeapons();
	
	void AddWeaponToInventory(InventoryWeaponweapon);
	void ModifyPotions(int change);
	void  ModifyCoins(change : int);
}
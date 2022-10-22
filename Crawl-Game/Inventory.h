#pragma once
#include "InventoryWeapon.h" 
#include "Potion.h"
#include "Weapon.h"

#include <vector>
#include <queue>
#include <utility>

class Inventory
{
private:
	std::pair<InventoryWeapon,InventoryWeapon> _weaponsInInventory;
	std::queue<Potion> _potions;
	int _coins;

public:
	Inventory();   

	std::pair<InventoryWeapon,InventoryWeapon> GetWeapons();
	void AddWeaponToInventory(InventoryWeapon weapon);
	void SwapWeapons();

	int UsePotion();
	void AddPotion(Potion potion);
	int GetPotionAmount();

	int GetCoins();
	void ModifyCoins(int change);
};
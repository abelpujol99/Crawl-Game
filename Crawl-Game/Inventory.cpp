#include "Inventory.h"

Inventory::Inventory(InventoryWeapon weapon) {
	_weaponsInInventory.first = weapon;
	_coins = 0;
}

std::pair<InventoryWeapon, InventoryWeapon> Inventory::GetWeapons() {
	return _weaponsInInventory;
}

void Inventory::AddWeaponToInventory(InventoryWeapon weapon) {
	_weaponsInInventory.second = weapon;
}

void Inventory::SwapWeapons() {
	if (_weaponsInInventory.second.GetName() != "invalid")
	{
		InventoryWeapon temp = _weaponsInInventory.first;
		_weaponsInInventory.first = _weaponsInInventory.second;
		_weaponsInInventory.second = temp;
	}
}

int Inventory::UsePotion() {
	Potion usedPotion = _potions.front();
	_potions.pop();
	return usedPotion.GetHealValue();
}

void Inventory::AddPotion(Potion potion) {
	_potions.push(potion);

}

int Inventory::GetPotionAmount()
{
	return _potions.size();
}

int Inventory::GetCoins() {
	return _coins;
}

void Inventory::ModifyCoins(int change) {
	_coins += change; 
}
#include "Inventory.h"

Inventory::Inventory() {
	_coins = 0;
	_Inventorycounter = 0;
}

InventoryWeapon Inventory:: ChangeWeapon(InventoryWeapon holding) {
	InventoryWeapon holderWepon = holding;
	InventoryWeapon firstslot = _weaponsInInventory.first;
	_weaponsInInventory.first = _weaponsInInventory.second;
	_weaponsInInventory.second = holding;

	std::cout <<"this is range"<< _weaponsInInventory.first.GetRange() << std::endl;
	return firstslot;
}

std::pair<InventoryWeapon, InventoryWeapon> Inventory::GetWeapons() {
	return _weaponsInInventory;
}

void Inventory::AddWeaponToInventory(InventoryWeapon Weapon) {
	
	if (_Inventorycounter = 0 ) {
		_weaponsInInventory.first = Weapon;
		_Inventorycounter++;
	}
	else
	{
		ChangeWeapon(Weapon);
	}
}

int Inventory::UsePotions() {
	
	return _potion[1].GetHealValue();
}

void Inventory::AddPotion(Potion potion) {
	_potion.push_back(potion);

}

int Inventory::GetCoins() {
	return _coins;
}
void Inventory::ModifyCoins(int change) {
	_coins += change; 
}
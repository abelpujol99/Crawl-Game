#include "Inventory.h"
#include "Player.h"


class player; 

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

int Inventory::GetPotions() {
	return _potion.GetHealValue();
}

void Inventory::ModifyPotions(int change) {
	//else list of poisions 
}

int Inventory::UsePotion(int heal) {
	

	return heal;
}

int Inventory::GetCoins() {
	return _coins;
}
void Inventory::ModifyCoins(int change) {
	_coins += change; 
}
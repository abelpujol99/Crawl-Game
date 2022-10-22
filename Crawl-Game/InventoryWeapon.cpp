#include "InventoryWeapon.h"

InventoryWeapon::InventoryWeapon() {
	//welk wapen ik vast heb 
	// aangeven wat welk naam en damage het heeft 
}

std::string InventoryWeapon::GetName() {

	return _name;
}

int InventoryWeapon::GetDamage() {

	return _damage; 
}

int InventoryWeapon::GetRange() {

	return _range;
}
#include "InventoryWeapon.h"

InventoryWeapon::InventoryWeapon(/*std::string name, int damage, int range*/) {
	//_name = name;
	//_damage = damage;
	//_range = range; 
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
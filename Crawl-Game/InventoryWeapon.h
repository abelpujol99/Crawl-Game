#pragma once
#include <string>

class InventoryWeapon {
private:
	std::string _name;
	int _damage;
	int _range;
public:
	InventoryWeapon();
	std::string GetName();
	int GetDamage();
	int GetRange();
};

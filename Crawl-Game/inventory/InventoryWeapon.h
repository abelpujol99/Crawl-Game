#pragma once
#include <string>
class InventoryWeapon
{
private:
	std::string _name;
		int _damage;
		int _range;
public:
	Weapon();
	std::string GetName();
	int GetDamage();
	int GetRange();

}

#include "Weapon.h"

Weapon::Weapon() : DropLootable() {

	_mapElementType = WEAPON;
}

void Weapon::Draw() {

	std::cout << 'W';
}
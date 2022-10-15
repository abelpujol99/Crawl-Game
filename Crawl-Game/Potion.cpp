#include "Potion.h"

Potion::Potion() : DropLootable() {

	this->_healValue = 2;
}

int Potion::GetHealValue() {

	return this->_healValue;
}


void Potion::Draw() {
	
	std::cout << 'H' << std::endl;
}
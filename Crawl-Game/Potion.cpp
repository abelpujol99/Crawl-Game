#include "Potion.h"

Potion::Potion() : DropLootable() {

	this->_healValue = 2;
	_mapElementType = POTION;
}

int Potion::GetHealValue() {

	return this->_healValue;
}


void Potion::Draw() {
	
	std::cout << 'H';
}
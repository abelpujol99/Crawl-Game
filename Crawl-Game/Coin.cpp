#include "Coin.h"

Coin::Coin() {

	srand(time(NULL));

	this->_points = rand() % 10;
	_mapElementType = COIN;
}

int Coin::GetPoints() {

	return _points;
}

void Coin::Draw() {

	std::cout << 'M';
}
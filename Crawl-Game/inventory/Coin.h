#pragma once

#include "DropLootable.h"
class Coin : DropLootable
{
private:
	int _points;
public:
	int GetCoins();
	void override Draw();
}
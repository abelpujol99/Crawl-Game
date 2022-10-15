#pragma once
#include <iostream>
#include"DropLootable.h"

class DropLootable;

class Potion : public DropLootable
{

private:

	int _healValue;

public:

	Potion();
	int GetHealValue();
	void Draw() override;
};


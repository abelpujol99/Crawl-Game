#pragma once
#include <iostream>
#include "DropLootable.h"

class DropLootable;

class Weapon : public DropLootable {

public:
	
	Weapon();
	void Draw() override;
};
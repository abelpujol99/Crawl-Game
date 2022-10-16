#pragma once
#include <iostream>
#include "EntityLootable.h"

class Chest : public EntityLootable
{
public:

	Chest();
	void Draw() override;
	//void AcceptCharacter(Player* player) override;
};


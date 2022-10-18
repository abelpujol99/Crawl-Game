#pragma once
#include <iostream>
#include <thread>
#include "Character.h"
#include "EntityLootable.h"

class Enemy : public Character, public EntityLootable {

private:

	std::thread _movement;

public:

	Enemy(Coordinates coordinates);
	void Move() override;
	void Die() override;
	Coordinates GetCoordinates();
	void Draw() override;
};
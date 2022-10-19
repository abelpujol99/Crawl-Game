#pragma once
#include <iostream>
#include <thread>
#include "Character.h"
#include "EntityLootable.h"

class Enemy : public Character, public EntityLootable {

private:

	std::thread* _movement;
	void Die();

public:

	Enemy(Coordinates coordinates);
	~Enemy();
	void Move() override;
	Coordinates GetCoordinates();
	void Draw() override;
};
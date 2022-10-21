#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "Character.h"
#include "EntityLootable.h"

#define MAX_MOVE_TIME 6000
#define MIN_MOVE_TIME 4000

class Enemy : public Character, public EntityLootable {

private:

	std::thread* _enemyThread;
	std::mutex* _enemyMutex;
	clock_t _targetTime;

public:

	Enemy(Coordinates coordinates);
	~Enemy();
	void EnemyManager();
	void ResetMoveTimer();
	void Move() override;
	void Die() override;
	void Draw() override;
	Coordinates GetCoordinates();
};
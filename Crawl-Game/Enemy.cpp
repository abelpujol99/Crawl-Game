#include "Enemy.h"

Enemy::Enemy(Coordinates coordinates) : Character(coordinates), EntityLootable() {

	targetTime = 0;

	Character::_mapElementType = ENEMY;
	_enemyThread = new std::thread(&Enemy::EnemyManager, this);
	_enemyThread->detach();
}

Enemy::~Enemy()
{
	delete _enemyThread;
}

void Enemy::EnemyManager() {
	ResetMoveTimer();
	while (this->_health > 0) {
		if (clock() >= targetTime) {
			Move();
		}
	}
}

void Enemy::ResetMoveTimer() {
	targetTime = clock() + (rand() % (MAX_MOVE_TIME - MIN_MOVE_TIME)) + MIN_MOVE_TIME;
}

void Enemy::Move() {
	std::cout << "Enemy moved" << std::endl;
	ResetMoveTimer();
}

void Enemy::Die() {

	this->Drop();
}

void Enemy::Draw() {

	std::cout << 'E';
}

Coordinates Enemy::GetCoordinates() {
	return Character::GetCoordinates();
}
#include "Enemy.h"

Enemy::Enemy(Coordinates coordinates) : Character(coordinates), EntityLootable() {

	_targetTime = 0;
	Character::_mapElementType = ENEMY;

	_enemyMutex = new std::mutex();
	_enemyThread = new std::thread(&Enemy::EnemyManager, this);
	_enemyThread->detach();
}

Enemy::~Enemy()
{
	_enemyMutex->lock();
	delete _enemyThread;
	_enemyMutex->unlock();
	delete _enemyMutex;
}

void Enemy::EnemyManager() {
	ResetMoveTimer();
	while (this->_health > 0) {
		_enemyMutex->lock();
		if (clock() >= _targetTime) {
			Move();
		}
		_enemyMutex->unlock();
	}
}

void Enemy::ResetMoveTimer() {
	_targetTime = clock() + (rand() % (MAX_MOVE_TIME - MIN_MOVE_TIME)) + MIN_MOVE_TIME;
}

Enemy::~Enemy() {

	delete _movement;
}

void Enemy::Move() {
	std::cout << "Enemy moved" << std::endl;
	ResetMoveTimer();
}

void Enemy::Die() {

	this->Drop();
}

Coordinates Enemy::GetCoordinates() {

	return Character::GetCoordinates();
}

void Enemy::Draw() {

	std::cout << 'E';
}

Coordinates Enemy::GetCoordinates() {
	return Character::GetCoordinates();
}
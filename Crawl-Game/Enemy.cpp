#include "Enemy.h"

Enemy::Enemy(Coordinates coordinates, Coordinates worldMapCoordinates) : Character(coordinates, worldMapCoordinates) {

	_health = 2;
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

void Enemy::ModifyHealthValueOnTakeDamageOrHeal(int modifyValue, MapElement** mapElementPointer) {

	this->_health += modifyValue;
	if (this->IsAlive())
	{
		return;
	}
	this->Drop(mapElementPointer);
}

void Enemy::EnemyManager() {
	ResetMoveTimer();
	while (this->_health > 0) {
		_enemyMutex->lock();
		if (clock() >= _targetTime) {
			//Move(5);
		}
		_enemyMutex->unlock();
	}
}

void Enemy::ResetMoveTimer() {
	_targetTime = clock() + (rand() % (MAX_MOVE_TIME - MIN_MOVE_TIME)) + MIN_MOVE_TIME;
}

void Enemy::Move(int lastCommand) {
	//ResetMoveTimer();
	this->Draw();
}

Coordinates Enemy::GetCoordinates() {

	return Character::GetCoordinates();
}

void Enemy::Draw() {

	ConsoleControl::SetPosition(this->GetCoordinates().x, this->GetCoordinates().y);
	std::cout << 'E';
}

void Enemy::Drop(MapElement** mapElementPointer) {

	this->_drop->SetCoordinates(Character::GetCoordinates());
	this->_drop->SetWorldMapCoordinates(this->GetWorldMapCoordinates());
	*mapElementPointer = _drop;
	this->~Enemy();
}
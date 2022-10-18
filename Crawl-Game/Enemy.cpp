#include "Enemy.h"

Enemy::Enemy(Coordinates coordinates) : Character(coordinates), EntityLootable() {

	Character::_mapElementType = ENEMY;
}

void Enemy::Move() {


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
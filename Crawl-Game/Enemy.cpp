#include "Enemy.h"

Enemy::Enemy(Coordinates coordinates) : Character(coordinates), EntityLootable() {

	Character::_mapElementType = ENEMY;
}

//void Enemy::InteractWithEntityLootable(EntityLootable* entityLootable) {
//
//	entityLootable->AcceptCharacter(this);
//}

void Enemy::Move() {


}

void Enemy::Die() {

	this->Drop();
}

void Enemy::Draw() {

	std::cout << 'E' << std::endl;
}

//void Enemy::AcceptCharacter(Player* player) {
//
//	this->ModifyHealthValueOnTakeDamageOrHeal(-1);
//
//	this->IsAlive();
//}
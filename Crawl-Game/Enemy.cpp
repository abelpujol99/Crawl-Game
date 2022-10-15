#include "Enemy.h"

Enemy::Enemy(Coordinates coordinates) : EntityLootable(), Character(coordinates) {
}

void Enemy::Draw() {

	std::cout << 'E' << std::endl;
}
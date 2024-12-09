#include "BulletEntity.h"

BulletEntity::BulletEntity(float x, float y, sf::Texture* texture, float radius, float health, float attack)
	: CollidableEntity(x, y, texture, radius),
	AttackManager(attack) {
}

BulletEntity::BulletEntity(sf::Vector2f pos, sf::Texture* texture, float radius, float health, float attack)
	: CollidableEntity(pos, texture, radius),
	AttackManager(attack) {
}
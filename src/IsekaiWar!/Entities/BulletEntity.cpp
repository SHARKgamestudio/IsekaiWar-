#include "BulletEntity.h"

BulletEntity::BulletEntity(float x, float y, sf::Texture* texture, float radius, float attack)
	: CollidableEntity(x, y, texture, radius),
	AttackModule(attack) {
}

BulletEntity::BulletEntity(sf::Vector2f pos, sf::Texture* texture, float radius, float attack)
	: CollidableEntity(pos, texture, radius),
	AttackModule(attack) {
}
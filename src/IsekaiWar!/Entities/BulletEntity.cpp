#include "BulletEntity.h"

BulletEntity::BulletEntity(float x, float y, sf::Texture* texture, float radius, float attack)
	: CollidableEntity(x, y, texture, radius),
	AttackModule(attack) {
}

BulletEntity::BulletEntity(sf::Vector2f position, sf::Texture* texture, float radius, float attack)
	: CollidableEntity(position, texture, radius),
	AttackModule(attack) {
}
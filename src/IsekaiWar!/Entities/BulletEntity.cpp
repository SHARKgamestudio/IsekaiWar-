#include "BulletEntity.h"

BulletEntity::BulletEntity(float x, float y, float w, float h, sf::Texture* texture, float radius, float attack)
	: CollidableEntity(x, y, h, w, texture, radius),
	AttackModule(attack) {
}

BulletEntity::BulletEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float attack)
	: CollidableEntity(position, scale, texture, radius),
	AttackModule(attack) {
}
#include "Bullet.h"

Bullet::Bullet(float x, float y, sf::Texture* texture, float radius, float health, float attack)
	: CollidableEntity(x, y, texture, radius),
	AttackManager(attack) {
};

Bullet::Bullet(sf::Vector2f pos, sf::Texture* texture, float radius, float health, float attack)
	: CollidableEntity(pos, texture, radius),
	AttackManager(attack) {
};
#include "LivingEntity.h"

LivingEntity::LivingEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: CollidableEntity(x, y, texture, columns, rows, radius),
	HealthModule(health) {
}

LivingEntity::LivingEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: CollidableEntity(position, texture, split, radius),
	HealthModule(health) {
}
#include "LivingEntity.h"

LivingEntity::LivingEntity(float x, float y, sf::Texture* texture, float radius, float health)
	: CollidableEntity(x, y, texture, radius),
	HealthModule(health) {
}

LivingEntity::LivingEntity(sf::Vector2f position, sf::Texture* texture, float radius, float health)
	: CollidableEntity(position, texture, radius),
	HealthModule(health) {
}
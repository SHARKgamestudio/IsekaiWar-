#include "LivingEntity.h"

LivingEntity::LivingEntity(float x, float y, float w, float h, sf::Texture* texture, float radius, float health)
	: CollidableEntity(x, y, w, h, texture, radius),
	HealthModule(health) {
}

LivingEntity::LivingEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float health)
	: CollidableEntity(position, scale, texture, radius),
	HealthModule(health) {
}
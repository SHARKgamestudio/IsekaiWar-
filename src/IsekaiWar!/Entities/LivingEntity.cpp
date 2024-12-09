#include "LivingEntity.h"

LivingEntity::LivingEntity(float x, float y, sf::Texture* texture, float radius, float health)
	: CollidableEntity(x, y, texture, radius),
	LifeManager(health) {
}

LivingEntity::LivingEntity(sf::Vector2f pos, sf::Texture* texture, float radius, float health)
	: CollidableEntity(pos, texture, radius),
	LifeManager(health) {
}
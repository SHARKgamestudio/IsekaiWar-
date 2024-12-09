#include "CollidableEntity.h"

CollidableEntity::CollidableEntity(float x, float y, sf::Texture* texture, float radius) 
	: Entity(x, y, texture), 
	HitboxModule(x, y, radius) {
}

CollidableEntity::CollidableEntity(sf::Vector2f pos, sf::Texture* texture, float radius)
	: Entity(pos, texture),
	HitboxModule(pos, radius) {
}

bool CollidableEntity::IsColliding(CollidableEntity* entity) {
	sf::Vector2f difference = pos - entity->pos;
	float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

	return distance < radius + entity->radius;
}
#include "CollidableEntity.h"

CollidableEntity::CollidableEntity(float x, float y, sf::Texture* texture, float radius) 
	: Entity(x, y, texture), 
	HitboxModule(x, y, radius) {
}

CollidableEntity::CollidableEntity(sf::Vector2f position, sf::Texture* texture, float radius)
	: Entity(position, texture),
	HitboxModule(position, radius) {
}

bool CollidableEntity::IsColliding(CollidableEntity* entity) {
	sf::Vector2f difference = position - entity->position;
	float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

	return distance < radius + entity->radius;
}
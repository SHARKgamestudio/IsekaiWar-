#include "CollidableEntity.h"

CollidableEntity::CollidableEntity(float x, float y, float w, float h, sf::Texture* texture, float radius)
	: Entity(x, y, w, h, texture), 
	HitboxModule(x, y, radius) {
}

CollidableEntity::CollidableEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius)
	: Entity(position, scale, texture),
	HitboxModule(position, radius) {
}

bool CollidableEntity::IsColliding(CollidableEntity* entity) {
	sf::Vector2f difference = position - entity->position;
	float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

	return distance < radius + entity->radius;
}
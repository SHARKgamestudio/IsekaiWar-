#include "CollidableEntity.h"

CollidableEntity::CollidableEntity(float x, float y, sf::Texture* texture, float radius) 
	: Entity(x, y, texture), 
	Hitbox(x, y, radius) {};

CollidableEntity::CollidableEntity(sf::Vector2f pos, sf::Texture* texture, float radius) : Entity(pos, texture), Hitbox(pos, radius) {};
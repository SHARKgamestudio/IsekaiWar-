#include "CollidableEntity.h"

#define SHOW_GIZMOS	0b11 // hitbox | lines

CollidableEntity::CollidableEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius)
	: Entity(x, y, texture, columns, rows),
	HitboxModule(this, radius, SHOW_GIZMOS) {
}

CollidableEntity::CollidableEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius)
	: Entity(position, texture, split),
	HitboxModule(this, radius, SHOW_GIZMOS){
}

void CollidableEntity::Update(float deltaTime) {
	Entity::Update(deltaTime);
	
	if (statut & 0b01) {
		UpdateLines();
	}
}

void CollidableEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	Entity::draw(target, states);
	states.transform.combine(getTransform());

	if (statut & 0b10) {
		target.draw(apparence, states);
	}

	if (statut & 0b01) {
		for (const sf::Vertex* line : lines) {
			target.draw(line, 2, sf::Lines);
		}
	}
}
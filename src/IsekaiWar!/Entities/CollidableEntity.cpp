#include "CollidableEntity.h"

CollidableEntity::CollidableEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius)
	: Entity(x, y, texture, columns, rows),
	HitboxModule(x, y, radius, 0b10) {
}

CollidableEntity::CollidableEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius)
	: Entity(position, texture, split),
	HitboxModule(position, radius, 0b01) {
}

void CollidableEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	Entity::draw(target, states);
	states.transform.combine(getTransform());

	if (statut & 0b10) {
		target.draw(hitboxApparence, states);
	}

	if (statut & 0b01) {
		for (const sf::Vertex* line : checkCollisions) {
			target.draw(line, 2, sf::Lines);
		}
	}
}
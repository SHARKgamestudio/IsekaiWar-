#include "CollidableEntity.h"

CollidableEntity::CollidableEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius)
	: Entity(x, y, texture, columns, rows) 
{
	hitbox = new HitboxModule(this, radius, 0b11);
}

CollidableEntity::CollidableEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius)
	: Entity(position, texture, split) 
{
	hitbox = new HitboxModule(this, radius, 0b11);
}

void CollidableEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	Entity::draw(target, states);
	states.transform.combine(getTransform());

	if (hitbox->statut & 0b10) {
		target.draw(hitbox->apparence, states);
	}

	if (hitbox->statut & 0b01) {
		for (const sf::Vertex* line : hitbox->lines) {
			hitbox->UpdateLines();
			target.draw(line, 2, sf::Lines);
		}
	}
}
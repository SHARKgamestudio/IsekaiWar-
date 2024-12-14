#include "Entity.h"

Entity::Entity(float x, float y, sf::Texture* texture, int columns, int rows) : spritesheet(texture, columns, rows) {
	setPosition(x, y);
	toDisable = false;
	toDestroy = false;
}

Entity::Entity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split) : spritesheet(texture, split.x, split.y) {
	setPosition(position);
	toDisable = false;
	toDestroy = false;
}

void Entity::Die() {
	toDisable = true;
}

void Entity::Update(float deltaTime) {
	if (toDestroy) {
		Despawn();
	}

	if (toDisable) {
		toDestroy = true;
	}

	sf::Vector2f pos = getPosition();
	if (-10 > pos.x || pos.x > 810 || -10 > pos.y || pos.y > 610) {
		toDisable = true;
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(spritesheet, states);
}
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

void Entity::Update(float deltaTime) {
	if (toDisable) {
		toDestroy = true;
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(spritesheet, states);
}
#include "Entity.h"

Entity::Entity(float x, float y, sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setPosition(x, y);
	toDisable = false;
	toDestroy = false;
}

Entity::Entity(sf::Vector2f pos, sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setPosition(pos);
	toDisable = false;
	toDestroy = false;
}

void Entity::Update(float dt) {
	if (toDisable)
	{
		toDestroy = true;
		return;
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());

	target.draw(sprite, states);
}
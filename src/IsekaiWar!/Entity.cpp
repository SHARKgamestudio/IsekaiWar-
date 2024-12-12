#include "Entity.h"

Entity::Entity(float x, float y, float w, float h, sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setPosition(x, y);
	toDisable = false;
	toDestroy = false;
}

Entity::Entity(sf::Vector2f pos, sf::Vector2f scale, sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(pos.x, pos.y, scale.x, scale.y));
	sprite.setPosition(pos);
	toDisable = false;
	toDestroy = false;
}

void Entity::Update(float dt) {
	if (toDisable)
	{
		toDestroy = true;
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}
#include "Entity.h"

Entity::Entity(float x, float y, sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setPosition(x, y);
	toDestroy = false;
}

Entity::Entity(sf::Vector2f pos, sf::Texture* texture) {
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setPosition(pos);
	toDestroy = false;
}
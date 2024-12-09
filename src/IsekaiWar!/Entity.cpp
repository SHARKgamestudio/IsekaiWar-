#include "pch.h"
#include "Entity.h"

Entity::Entity(float x, float y, sf::Texture* texture)
{
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setPosition(x, y);
}

Entity::Entity(sf::Vector2f pos, sf::Texture* texture)
{
	this->texture = texture;
	sprite.setTexture(*(this->texture));
	sprite.setPosition(pos);
}
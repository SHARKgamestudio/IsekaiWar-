#include "pch.h"
#include "SpriteBackground.h"

SpriteBackground::SpriteBackground(float x, float y, sf::Texture* texture, float speed) : Entity(x, y, texture), TravelingTexture(sf::Vector2f(0, 1), speed)
{
	this->texture->setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 2000));
}
SpriteBackground::SpriteBackground(sf::Vector2f pos, sf::Texture* texture, float speed) : Entity(pos, texture), TravelingTexture(sf::Vector2f(0, 1), speed)
{
	this->texture->setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
}

void SpriteBackground::Traveling(float dt)
{
	u = u - normalisedDirection.x * dt * speed;
	v = v - normalisedDirection.y * dt * speed;
	sprite.setTextureRect(sf::IntRect(int(u), int(v), 800, 600));
}

void SpriteBackground::Update(float dt)
{
	Traveling(dt);
}

void SpriteBackground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(sprite, states);
}
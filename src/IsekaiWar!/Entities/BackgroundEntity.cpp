#include "BackgroundEntity.h"

BackgroundEntity::BackgroundEntity(float x, float y, sf::Texture* texture, float speed)
	: Entity(x, y, texture),
	TravelingTexture(sf::Vector2f(0, 1), speed) {
	this->texture->setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 2000));
}
BackgroundEntity::BackgroundEntity(sf::Vector2f pos, sf::Texture* texture, float speed)
	: Entity(pos, texture),
	TravelingTexture(sf::Vector2f(0, 1), speed) {
	this->texture->setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
}

void BackgroundEntity::Traveling(float deltaTime) {
	u = u - normalisedDirection.x * deltaTime * speed;
	v = v - normalisedDirection.y * deltaTime * speed;
	sprite.setTextureRect(sf::IntRect(int(u), int(v), 800, 600));
}

void BackgroundEntity::Update(float deltaTime) {
	Traveling(deltaTime);
}

void BackgroundEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(this->getTransform());
	target.draw(sprite, states);
}
#include "BackgroundEntity.h"

BackgroundEntity::BackgroundEntity(sf::Texture* texture)
	: Entity(0.f, 0.f, 800.f, 600.f, texture),
	TravellingModule(sf::Vector2f(0, 1), 20.f) {
	this->texture->setRepeated(true);
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
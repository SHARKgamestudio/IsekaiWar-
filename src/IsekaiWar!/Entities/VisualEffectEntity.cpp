#include "VisualEffectEntity.h"

VisualEffectEntity::VisualEffectEntity(float x, float y, sf::Texture* texture, float speed)
	: Entity(x, y, texture),
	MoveModule(sf::Vector2f(0, 1), speed) {
}

VisualEffectEntity::VisualEffectEntity(sf::Vector2f position, sf::Texture* texture, float speed)
	: Entity(position, texture),
	MoveModule(sf::Vector2f(0, 1), speed) {
}

void VisualEffectEntity::Move(float deltaTime) {
	sprite.move(direction);
}

void VisualEffectEntity::Update(float deltaTime) {
	Move(deltaTime);
}
#include "VisualEffectEntity.h"

VisualEffectEntity::VisualEffectEntity(float x, float y, float w, float h, sf::Texture* texture, float speed)
	: Entity(x, y, w, h, texture),
	MoveModule(sf::Vector2f(0, 1), speed) {
}

VisualEffectEntity::VisualEffectEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float speed)
	: Entity(position, scale, texture),
	MoveModule(sf::Vector2f(0, 1), speed) {
}

void VisualEffectEntity::Move(float deltaTime) {
	sprite.move(direction);
}

void VisualEffectEntity::Update(float deltaTime) {
	Move(deltaTime);
}
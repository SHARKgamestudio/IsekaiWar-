#include "VisualEffectEntity.h"

VisualEffectEntity::VisualEffectEntity(float x, float y, sf::Texture* texture, int columns, int rows, float speed)
	: Entity(x, y, texture, columns, rows),
	MoveModule(sf::Vector2f(0, 1), speed) {
}

VisualEffectEntity::VisualEffectEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float speed)
	: Entity(position, texture, split),
	MoveModule(sf::Vector2f(0, 1), speed) {
}

void VisualEffectEntity::Move(float deltaTime) {
	spritesheet.move(direction);
}

void VisualEffectEntity::UpdateLogic(float deltaTime) {
	Move(deltaTime);
}
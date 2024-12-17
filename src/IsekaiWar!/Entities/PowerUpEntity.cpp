#include "PowerUpEntity.h"
#include "../Managers.h"

#include <iostream>

PowerUpEntity::PowerUpEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed)
	: CollidableEntity(x, y, texture, columns, rows, radius),
	MoveModule(direction, speed) {
}

PowerUpEntity::PowerUpEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed)
	: CollidableEntity(position, texture, split, radius),
	MoveModule(direction, speed) {
}

void PowerUpEntity::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}

void PowerUpEntity::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnEntity(this);
}

void PowerUpEntity::UpdateLogic(float deltaTime) {
	CollidableEntity::UpdateLogic(deltaTime);

	Move(deltaTime);
	spritesheet.rotate(100 * deltaTime);
	CheckCollisions();

	if (!entitiesHit.empty()) {
		Action();
		Die();
	}

	sf::Vector2f pos = getPosition();
	if (-10 > pos.x || pos.x > 810 || -10 > pos.y || pos.y > 610) {
		Die();
	}
}
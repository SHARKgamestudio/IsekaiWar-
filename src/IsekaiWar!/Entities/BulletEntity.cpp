#include "BulletEntity.h"
#include "../Managers.h"

BulletEntity::BulletEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed)
	: CollidableEntity(x, y, texture, columns, rows, radius),
	AttackModule(attack),
	MoveModule(direction, speed) {
}

BulletEntity::BulletEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed)
	: CollidableEntity(position, texture, split, radius),
	AttackModule(attack),
	MoveModule(direction, speed) {
}

void BulletEntity::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}

void BulletEntity::UpdateLogic(float deltaTime) {
	CollidableEntity::UpdateLogic(deltaTime);

	Move(deltaTime);

	CheckCollisions();

	sf::Vector2f pos = getPosition();
	if (-10 > pos.x || pos.x > 810 || -10 > pos.y || pos.y > 610) {
		Die();
	}
}
#include "BulletEntity.h"
#include "../Managers.h"

BulletEntity::BulletEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack)
	: CollidableEntity(x, y, texture, columns, rows, radius),
	AttackModule(attack) {
}

BulletEntity::BulletEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack)
	: CollidableEntity(position, texture, split, radius),
	AttackModule(attack) {
}

void BulletEntity::Update(float deltaTime) {
	CollidableEntity::Update(deltaTime);

	CheckCollisions();

	sf::Vector2f pos = getPosition();
	if (-10 > pos.x || pos.x > 810 || -10 > pos.y || pos.y > 610) {
		toDisable = true;
	}
}
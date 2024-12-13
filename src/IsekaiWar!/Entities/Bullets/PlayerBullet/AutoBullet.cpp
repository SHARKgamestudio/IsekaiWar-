#include "AutoBullet.h"

AutoBullet::AutoBullet(float x, float y, sf::Texture* texture, int columns, int rows)
	: PlayerBullet(x, y, texture, columns, rows, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

AutoBullet::AutoBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split)
	: PlayerBullet(position, texture, split, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

void AutoBullet::Move(float deltaTime) {
	spritesheet.move(normalisedDirection);
}

void AutoBullet::Update(float deltaTime, std::vector<CollidableEntity*> entities) {
	Move(deltaTime);

	if (hitbox->hasCollided) {
		toDisable = true;
	}
}
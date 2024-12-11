#include "AutoBullet.h"

AutoBullet::AutoBullet(float x, float y, float w, float h, sf::Texture* texture)
	: PlayerBullet(x, y, w, h, texture, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

AutoBullet::AutoBullet(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture)
	: PlayerBullet(position, scale, texture, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

void AutoBullet::Move(float deltaTime) {
	sprite.move(normalisedDirection);
}

void AutoBullet::Update(float deltaTime, std::vector<CollidableEntity*> entities) {
	Move(deltaTime);

	if (hasCollided) {
		toDisable = true;
	}
}
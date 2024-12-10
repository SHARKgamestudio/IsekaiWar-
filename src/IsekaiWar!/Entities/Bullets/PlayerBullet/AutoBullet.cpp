#include "AutoBullet.h"

AutoBullet::AutoBullet(float x, float y, sf::Texture* texture)
	: PlayerBullet(x, y, texture, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

AutoBullet::AutoBullet(sf::Vector2f position, sf::Texture* texture)
	: PlayerBullet(position, texture, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {
}

void AutoBullet::Move(float deltaTime) {
	sprite.move(normalisedDirection);
}

void AutoBullet::Update(float deltaTime, std::vector<Entity*> entities) {
	Move(deltaTime);

	if (hasCollided) {
		toDestroy = true;
	}
}
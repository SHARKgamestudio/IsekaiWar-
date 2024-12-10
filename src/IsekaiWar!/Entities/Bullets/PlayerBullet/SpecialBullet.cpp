#include "SpecialBullet.h"

SpecialBullet::SpecialBullet(float x, float y, sf::Texture* texture)
	: PlayerBullet(x, y, texture, 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) {
}

SpecialBullet::SpecialBullet(sf::Vector2f position, sf::Texture* texture)
	: PlayerBullet(position, texture, 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) {
}

void SpecialBullet::Move(float deltaTime) {
	sprite.move(normalisedDirection);
}

void SpecialBullet::Update(float deltaTime, std::vector<Entity*> entities) {
	Move(deltaTime);

	for (LivingEntity*& entityHit : entitiesHit) {
		Attack(entityHit, deltaTime);
	}
}
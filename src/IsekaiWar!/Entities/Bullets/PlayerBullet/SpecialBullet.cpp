#pragma region Local Dependencies

#include "SpecialBullet.h"
#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion
SpecialBullet::SpecialBullet(float x, float y, float w, float h)
	: PlayerBullet(x, y, w, h, Managers::GetInstance()->ResourceManager.GetTexture("fireball"), 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) {
}

SpecialBullet::SpecialBullet(sf::Vector2f position, sf::Vector2f scale)
	: PlayerBullet(position, scale, Managers::GetInstance()->ResourceManager.GetTexture("fireball"), 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) {
}

void SpecialBullet::Move(float deltaTime) {
	sprite.move(normalisedDirection * deltaTime * speed);
}

void SpecialBullet::Update(float deltaTime) {
	Move(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {
		if (LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit)) {
			Attack(castEntity, deltaTime);
		}
		else {
			toDisable = true;
		}
	}
}
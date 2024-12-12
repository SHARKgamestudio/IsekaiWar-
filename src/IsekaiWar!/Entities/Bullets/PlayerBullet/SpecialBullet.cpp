#pragma region Local Dependencies

#include "SpecialBullet.h"
#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion
SpecialBullet::SpecialBullet(float x, float y)
	: PlayerBullet(x, y, 300.f, 300.f, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), 50.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) 
{
	sprite.setOrigin(300.f / 2, 300.f / 2);
	sprite.setRotation(-90);
}

SpecialBullet::SpecialBullet(sf::Vector2f position)
	: PlayerBullet(position, sf::Vector2f(300.f, 300.f), Managers::GetInstance()->ResourceManager->GetTexture("fireball"), 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) {
	sprite.setOrigin(300.f / 2, 300.f / 2);
	sprite.setRotation(-90);
}

void SpecialBullet::Move(float deltaTime) {
	sprite.move(normalisedDirection * deltaTime * speed);
	hitboxApparence.move(normalisedDirection* deltaTime* speed);
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

void SpecialBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(sprite, states);
	target.draw(hitboxApparence, states);
}
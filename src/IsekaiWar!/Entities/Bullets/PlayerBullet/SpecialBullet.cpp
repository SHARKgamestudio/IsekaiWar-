#include "SpecialBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

SpecialBullet::SpecialBullet(float x, float y, int columns, int rows)
	: PlayerBullet(x, y, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), columns, rows, 50.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) 
{
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);
}

SpecialBullet::SpecialBullet(sf::Vector2f position, sf::Vector2i split)
	: PlayerBullet(position, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), split, 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 20.f) {
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);
}

void SpecialBullet::Move(float deltaTime) {
	spritesheet.move(normalisedDirection * deltaTime * speed);
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
	target.draw(spritesheet, states);
	target.draw(hitboxApparence, states);
}
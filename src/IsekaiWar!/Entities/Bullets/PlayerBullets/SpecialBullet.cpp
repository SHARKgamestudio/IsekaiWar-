#include "SpecialBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

SpecialBullet::SpecialBullet(float x, float y, int columns, int rows)
	: PlayerBullet(x, y, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), columns, rows, 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 700.f) ,
	animator(&spritesheet, { new Animation("forward", 0, 5, 2) })
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

SpecialBullet::SpecialBullet(sf::Vector2f position, sf::Vector2i split)
	: PlayerBullet(position, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), split, 10.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 700.f),
	animator(&spritesheet, { new Animation("forward", 0, 5, 2) })
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

void SpecialBullet::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}	

void SpecialBullet::Update(float deltaTime) {
	BulletEntity::Update(deltaTime);

	Move(deltaTime);

	animator.Update(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {
		if (LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit)) {
			Attack(castEntity, deltaTime);
		}
	}
}
#include "AutoBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

AutoBullet::AutoBullet(float x, float y, int columns, int rows)
	: PlayerBullet(x, y, Managers::GetInstance()->ResourceManager->GetTexture("waterball"), columns, rows, 28.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 700.f),
	animator(&spritesheet, { new Animation("forward", 0, 5, 2) })
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setPosition(-67.f, 90.f);
	spritesheet.setRotation(90);

	animator.Play("forward");
}

AutoBullet::AutoBullet(sf::Vector2f position, sf::Vector2i split)
	: PlayerBullet(position, Managers::GetInstance()->ResourceManager->GetTexture("waterball"), split, 28.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 700.f),
	animator(&spritesheet, { new Animation("forward", 0, 5, 2) })
{
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setPosition(-67.f, 90.f);
	spritesheet.setRotation(90);

	animator.Play("forward");
}

void AutoBullet::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}

void AutoBullet::Update(float deltaTime) {
	BulletEntity::Update(deltaTime);

	Move(deltaTime);

	animator.Update(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {

		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit);

		if (!castEntity) {
			continue;
		}

		if (toDisable || toDestroy) {
			return;
		}

		std::cout << "collision" << std::endl;
		Attack(castEntity, deltaTime);
		toDisable = true;
		return;
	}
}
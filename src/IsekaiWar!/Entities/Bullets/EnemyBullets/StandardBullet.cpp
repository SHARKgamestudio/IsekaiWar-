#include "StandardBullet.h"

#pragma region Local Dependencies

#include "../../../Managers.h"

#pragma endregion

StandardBullet::StandardBullet(float x, float y)
	: EnemyBullet(x, y, Managers::GetInstance()->ResourceManager->GetTexture("laser"), 1, 1, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {

	spritesheet.setScale(0.5f, 0.5f);
	spritesheet.setOrigin(64 / 2, 64 / 2);
	spritesheet.setRotation(90);
}

StandardBullet::StandardBullet(sf::Vector2f position)
	: EnemyBullet(position, Managers::GetInstance()->ResourceManager->GetTexture("laser"), sf::Vector2i(1, 1), 5.f, 5.f),
	MoveModule(sf::Vector2f(0.0f, 1.0f), 800.0f) {

	spritesheet.setScale(0.5f, 0.5f);
	spritesheet.setOrigin(64 / 2, 64 / 2);
	spritesheet.setRotation(90);
}

void StandardBullet::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}

void StandardBullet::Update(float deltaTime) {
	BulletEntity::Update(deltaTime);

	Move(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {
		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit);

		if (!castEntity) {
			continue;
		}

		if (toDisable || toDestroy) {
			return;
		}

		Attack(castEntity, deltaTime);
		toDisable = true;
		return;
	}
}
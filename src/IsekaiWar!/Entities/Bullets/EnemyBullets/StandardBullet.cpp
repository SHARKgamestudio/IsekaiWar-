#include "StandardBullet.h"

#pragma region Local Dependencies

#include "../../../Managers.h"

#pragma endregion

StandardBullet::StandardBullet(float x, float y)
	: EnemyBullet(x, y, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), 6, 1, 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {

	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setPosition(-67.f, 90.f);
	spritesheet.setRotation(90);
}

StandardBullet::StandardBullet(sf::Vector2f position)
	: EnemyBullet(position, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), sf::Vector2i(6, 1), 5.f, 5.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 30.f) {

	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setPosition(-67.f, 90.f);
	spritesheet.setRotation(90);
}

void StandardBullet::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}

void StandardBullet::Update(float deltaTime) {
	BulletEntity::Update(deltaTime);

	for (CollidableEntity* entityHit : hitbox->entitiesHit) {

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
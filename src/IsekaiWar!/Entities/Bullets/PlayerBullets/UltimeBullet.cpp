#include "UltimeBullet.h"

#include <cmath>

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

UltimeBullet::UltimeBullet(float x, float y, int columns, int rows)
	: PlayerBullet(x, y, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), columns, rows, 30.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 700.f),
	animatorHead(&spritesheet, { new Animation("forward", 0, 5, 2) })
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);

	animatorHead.Play("forward");
}

UltimeBullet::UltimeBullet(sf::Vector2f position, sf::Vector2i split)
	: PlayerBullet(position, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), split, 30.f, 2.f),
	MoveModule(sf::Vector2f(0.f, -1.f), 700.f),
	animatorHead(&spritesheet, { new Animation("forward", 0, 5, 2) })
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);

	animatorHead.Play("forward");
}

void UltimeBullet::Update(float deltaTime) {
	BulletEntity::Update(deltaTime);

	Move(deltaTime);

	//animatorBody.Update(deltaTime);
	animatorHead.Update(deltaTime);

	if (!entitiesHit.empty()) {
		Attack(dynamic_cast<LivingEntity*>(entitiesHit[0]), deltaTime);
	}
}

void UltimeBullet::Move(float deltaTime) {
	if (!entitiesHit.empty()) {
		setPosition(sf::Vector2f(entity->getPosition().x, entitiesHit[0]->getPosition().y));
		return;
	}

	setPosition(sf::Vector2f(entity->getPosition().x, -9));
}

void UltimeBullet::UpdateLines() {
	for (int i = 0; i < lines.size(); i++) {
		lines[i][0].position = getPosition();
		lines[i][1].position = collisionsToCheck[i]->getPosition();
	}
}

void UltimeBullet::CheckCollisions() {
	entitiesHit.clear();

	for (CollidableEntity* otherEntity : collisionsToCheck) {

		float difference = getPosition().x - otherEntity->getPosition().x;

		if (std::abs(difference) >= radius + otherEntity->radius) continue;

		if (otherEntity->getPosition().y < -9.f) continue;

		if (entitiesHit.empty()) {
			entitiesHit.push_back(otherEntity);
			continue;
		}
		
		if (getPosition().y < entitiesHit[0]->getPosition().y) {
			entitiesHit[0] = otherEntity;
			continue;
		}
	}
}
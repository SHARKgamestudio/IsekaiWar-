#include "UltimeBullet.h"

#pragma region External Dependencies

#include <cmath>

#pragma endregion

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("fireAuto")
#define COLUMNS 6
#define ROWS 1
#define RADIUS 30.f
#define ATTACK 2.f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f

UltimeBullet::UltimeBullet(float x, float y)
	: PlayerBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS, SPEED_ANIMATION) })
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

UltimeBullet::UltimeBullet(sf::Vector2f position)
	: PlayerBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS, SPEED_ANIMATION) })
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setScale(0.8f, 0.8f);
	spritesheet.setOrigin(300.f / 2, 300.f / 2);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

void UltimeBullet::Update(float deltaTime) {
	PlayerBullet::Update(deltaTime);

	//animatorBody.Update(deltaTime);
	animator.Update(deltaTime);

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
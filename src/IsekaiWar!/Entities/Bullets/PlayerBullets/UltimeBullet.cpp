#include "UltimeBullet.h"

#pragma region External Dependencies

#include <cmath>

#pragma endregion

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE_FIRE Managers::GetInstance()->ResourceManager->GetTexture("fireUltime")
#define TEXTURE_LASER Managers::GetInstance()->ResourceManager->GetTexture("laserUltime")
#define COLUMNS 4
#define ROWS 2
#define RADIUS 30.f
#define ATTACK 2.f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f
#define POSITION_X 0
#define POSITION_Y 60

UltimeBullet::UltimeBullet(float x, float y)
	: PlayerBullet(x, y, TEXTURE_FIRE, COLUMNS, ROWS, RADIUS, ATTACK, SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS - 1, SPEED_ANIMATION) }),
	spriteLaser(sf::Sprite())
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(1.5f, 1.5f);
	spritesheet.setRotation(180);

	TEXTURE_LASER->setRepeated(true);
	spriteLaser.setTexture(*TEXTURE_LASER);

	animator.Play("forward");
}

UltimeBullet::UltimeBullet(sf::Vector2f position)
	: PlayerBullet(position, TEXTURE_FIRE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS - 1, SPEED_ANIMATION) })
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(1.5f, 1.5f);
	spritesheet.setRotation(180);

	animator.Play("forward");
}

void UltimeBullet::UpdateLogic(float deltaTime) {
	PlayerBullet::UpdateLogic(deltaTime);

	//animatorBody.Update(deltaTime);
	animator.UpdateLogic(deltaTime);

	if (!entitiesHit.empty()) {
		Attack(dynamic_cast<LivingEntity*>(entitiesHit[0]), deltaTime);
	}
}

void UltimeBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	Entity::draw(target, states);

	states.transform.combine(getTransform());
	target.draw(spriteLaser, states);
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
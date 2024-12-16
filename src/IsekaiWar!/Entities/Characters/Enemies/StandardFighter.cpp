#include "StandardFighter.h"

#include "../../../Managers.h"
#include "../../Bullets/EnemyBullets/StandardBullet.h"
#include "../../../Managers.h"
#include "../../../Utils/Maths.h"

#define CIRCLE_RADIUS 256
#define START_DISTANCE 25

StandardFighter::StandardFighter(float x, float y)
	: EnemyEntity(x, -256, Managers::GetInstance()->ResourceManager->GetTexture("enemy"), 5, 4, 64, 2) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = sf::Vector2f(x, y);
	this->spritesheet.setOrigin(256 / 2, 256 / 2);
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

StandardFighter::StandardFighter(sf::Vector2f position)
	: EnemyEntity(sf::Vector2f(position.x, -256), Managers::GetInstance()->ResourceManager->GetTexture("enemy"), sf::Vector2i(5, 4), 64, 2) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = position;
	this->spritesheet.setOrigin(256 / 2, 256 / 2);
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

IntervalClock shootClock(0.5f);
void StandardFighter::Update(float deltaTime) {
	EnemyEntity::Update(deltaTime);

	animator->Update(deltaTime);

	time += deltaTime;
	
	if (!spawned) {
		setPosition(getPosition().x, Maths::Lerp(getPosition().y, spawn.y, deltaTime));
		if (Maths::Equals(getPosition().y, spawn.y, START_DISTANCE)) spawned = true;
	}
	else {
		setPosition(Maths::Lerp(getPosition().x, spawn.x + std::cos(time) * CIRCLE_RADIUS, deltaTime), Maths::Lerp(getPosition().y, spawn.y + std::sin(time) * CIRCLE_RADIUS, deltaTime));

		if (shootClock.Update(deltaTime)) {
			(new StandardBullet(getPosition() + sf::Vector2f(0, 128)))->Spawn();
		}
	}

	if(GetHealth() <= 0) Die();
}
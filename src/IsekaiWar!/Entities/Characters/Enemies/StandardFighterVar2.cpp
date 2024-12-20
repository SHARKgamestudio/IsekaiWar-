#include "StandardFighterVar2.h"

#include "../../../Managers.h"
#include "../../Bullets/EnemyBullets/StandardBullet.h"
#include "../../../Utils/Maths.h"
#include "../../../Utils/IntervalClock.h"

// behaviour
#define CIRCLE_RADIUS 256
#define START_DISTANCE 25

// constructor
#define INITIAL_POSITION_Y -256
#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("standard-fighter-var2")
#define COLUMNS 5
#define ROWS 4
#define RADIUS 64
#define HEALTH 2

StandardFighterVar2::StandardFighterVar2(float x, float y, float birth)
	: EnemyEntity(x, INITIAL_POSITION_Y, TEXTURE, birth, COLUMNS, ROWS, RADIUS, HEALTH), shootClock(0.2f) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = sf::Vector2f(x, y);
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

StandardFighterVar2::StandardFighterVar2(sf::Vector2f position, float birth)
	: EnemyEntity(sf::Vector2f(position.x, -256), Managers::GetInstance()->ResourceManager->GetTexture("enemy"), birth, sf::Vector2i(5, 4), 64, 2), shootClock(0.2f) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = position;
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

void StandardFighterVar2::UpdateLogic(float deltaTime) {
	EnemyEntity::UpdateLogic(deltaTime);

	animator->UpdateLogic(deltaTime);

	time += deltaTime;
	
	if (!spawned) {
		setPosition(getPosition().x, Maths::Lerp(getPosition().y, spawn.y, deltaTime));
		if (Maths::Equals(getPosition().y, spawn.y, START_DISTANCE)) spawned = true;
	}

	if (shootClock.UpdateLogic(deltaTime)) {
		(new StandardBullet(getPosition() + sf::Vector2f(-16, 128), sf::Vector2f(0, 1)))->Spawn();
	}

	if(GetHealth() <= 0) Die();
}
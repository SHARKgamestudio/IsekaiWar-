#include "StandardFighter.h"

#include "../../../Managers.h"
#include "../../Bullets/EnemyBullets/StandardBullet.h"
#include "../../../Managers.h"

StandardFighter::StandardFighter(float x, float y, float radius, float health)
	: EnemyEntity(x, -256, Managers::GetInstance()->ResourceManager->GetTexture("enemy"), 5, 4, radius, health) {
	
	this->spawn = sf::Vector2f(x, y);
	this->shoot = new ShootModule(sf::Vector2f(0, 1));
	
	this->spritesheet.setOrigin(256 / 2, 256 / 2);

	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

StandardFighter::StandardFighter(sf::Vector2f position, float radius, float health)
	: EnemyEntity(sf::Vector2f(position.x, -256), Managers::GetInstance()->ResourceManager->GetTexture("enemy"), sf::Vector2i(5, 4), radius, health) {
	
	this->spawn = position;

	this->shoot = new ShootModule(sf::Vector2f(0, 1));

	
	this->spritesheet.setOrigin(256 / 2, 256 / 2);

	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

void StandardFighter::Update(float deltaTime) {

	animator->Update(deltaTime);

	if (GetHealth() <= 0) { Managers::GetInstance()->SceneManager->currentLevel->DespawnEntity(this); }

	if (!spawned) {
		if (getPosition().y < spawn.y) {
			setPosition(getPosition().x, getPosition().y + 100 * deltaTime);
		}
		else { setPosition(getPosition().x, spawn.y); }
	}

	if (getPosition() == spawn) {
		if (!spawned) {
			spawned = true;
		}
	}

	if (spawned) {
		test+=deltaTime;

		float x = std::cos(test) * 256;
		float y = std::sin(test) * 256;
		
		setPosition(sf::Vector2f(spawn.x + x - (256/2), spawn.y + y - (256 / 2)));

		//shoot->Shoot(new StandardBullet(getPosition(), Managers::GetInstance()->ResourceManager.GetTexture("player"), sf::Vector2i(1, 1)));
	}
}
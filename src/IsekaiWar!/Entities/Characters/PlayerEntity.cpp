#include "PlayerEntity.h"

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Utils/Maths.h"
#include "../Bullets/PlayerBullets/SpecialBullet.h"
#include "../Bullets/PlayerBullets/AutoBullet.h"

#pragma endregion

PlayerEntity::PlayerEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: CharacterEntity(x, y, texture, columns, rows, radius, health),
	ShootModule(sf::Vector2f(0, -1)) {

	this->spritesheet.setOrigin(256/2, 256/2);
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;

	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

PlayerEntity::PlayerEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: CharacterEntity(position, texture, split, radius, health),
	ShootModule(sf::Vector2f(0, -1)) {
	this->spritesheet.setOrigin(256 / 2, 256 / 2);
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

void PlayerEntity::Update(float deltaTime) {
	float horizontal = inputs->GetAxis("Horizontal");
	float vertical = inputs->GetAxis("Vertical");

	sf::Vector2f inputs(horizontal, vertical);

	float magnitude = Maths::Clamp((float)sqrt(pow(inputs.x, 2) + pow(inputs.y, 2)), 0, 1) * 512;

	sf::Vector2f direction = inputs * magnitude;

	float positive = (inputs.x * (float)std::pow(angle / 25 - 1, 2));
	float negative = (inputs.x * (float)std::pow(angle / 25 + 1, 2));

	if (horizontal > 0) {
		angle += positive * deltaTime * 90;
	}
	else if (horizontal < 0) {
		angle += negative * deltaTime * 90;
	}
	else {
		if (angle > 0) { angle += (-std::pow(angle / 25, 0.5f)) * deltaTime * 512; }
		else if (angle < 0) { angle += (std::pow(-angle / 25, 0.5f)) * deltaTime * 512; }
	}

	animator->Update(deltaTime);

	if (this->inputs->GetKey("Auto")) {
		(new AutoBullet(this->getPosition()))->Spawn();
	}

	if (this->inputs->GetKeyDown("Special")) {
		(new SpecialBullet(this->getPosition()))->Spawn();
	}

	this->move(direction * deltaTime);
	this->spritesheet.setRotation(angle);
}
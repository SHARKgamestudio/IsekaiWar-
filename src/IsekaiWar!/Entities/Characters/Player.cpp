#include "Player.h"

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Utils/Maths.h"
#include "../Bullets/PlayerBullet/SpecialBullet.h"

#pragma endregion

Player::Player(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: CharacterEntity(x, y, texture, columns, rows, radius, health) {
	this->spritesheet.setOrigin(256/2, 256/2);
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;

	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 2) });
	this->animator->Play("idle");

	this->shoot = new ShootModule(new SpecialBullet(0, 0), sf::Vector2f(0, -1));
}

Player::Player(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: CharacterEntity(position, texture, split, radius, health) {
	this->spritesheet.setOrigin(256 / 2, 256 / 2);
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 2) });
	this->animator->Play("idle");
}

void Player::Update(float deltaTime) {
	float horizontal = inputs->GetAxis("Horizontal");
	float vertical = inputs->GetAxis("Vertical");

	sf::Vector2f inputs(horizontal, vertical);

	float magnitude = Maths::Clamp(sqrt(pow(inputs.x, 2) + pow(inputs.y, 2)), 0, 1) * 512;

	sf::Vector2f direction = inputs * magnitude;

	/*float test = (inputs.x * (-std::sqrt(angle / 25) + 1));
	angle += horizontal ? test * deltaTime * 60 : 0;*/

	animator->Update(deltaTime);

	if (this->inputs->GetKeyDown("")) {
		shoot->Shoot();
	}

	this->move(direction * deltaTime);
	this->spritesheet.setRotation(angle);
}
#include "Player.h"

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Utils/Maths.h"

#pragma endregion

Player::Player(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: CharacterEntity(x, y, texture, columns, rows, radius, health) {
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;
}

Player::Player(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: CharacterEntity(position, texture, split, radius, health) {
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;
}

void Player::Update(float deltaTime) {
	float horizontal = inputs->GetAxis("Horizontal");
	float vertical = inputs->GetAxis("Vertical");

	sf::Vector2f inputs(horizontal, vertical);

	float magnitude = Maths::Clamp(sqrt(pow(inputs.x, 2) + pow(inputs.y, 2)), 0, 1) * 512;

	sf::Vector2f direction = inputs * magnitude;

	float test = (inputs.x * (-std::sqrt(angle / 25) + 1));

	angle += horizontal ? test * deltaTime * 60 : 0;

	this->move(direction * deltaTime);
	this->spritesheet.setRotation(angle);
}
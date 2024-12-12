#include "Player.h"

Player::Player(float x, float y, float w, float h, sf::Texture* texture, float radius, float health)
	: CharacterEntity(x, y, w, h, texture, radius, health) {
}

Player::Player(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float health)
	: CharacterEntity(position, scale, texture, radius, health) {
}

void Player::Update(float deltaTime) {
}
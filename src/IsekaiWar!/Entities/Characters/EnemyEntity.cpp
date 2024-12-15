#include "EnemyEntity.h"

EnemyEntity::EnemyEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: CharacterEntity(x, y, texture, columns, rows, radius, health) {
}

EnemyEntity::EnemyEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: CharacterEntity(position, texture, split, radius, health) {
}

void EnemyEntity::Update(float deltaTime) {
	// LOGIC GOES HERE //
}
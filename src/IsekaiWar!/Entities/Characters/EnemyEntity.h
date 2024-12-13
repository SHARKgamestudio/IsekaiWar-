#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"

#pragma endregion

class EnemyEntity : public CharacterEntity {
private:

public:
	EnemyEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	EnemyEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);

	void Update(float deltaTime);
};
#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class EnemyEntity : public CharacterEntity {
public:
	float birth = 0;

	EnemyEntity(float x, float y, sf::Texture* texture, float birth = 0, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	EnemyEntity(sf::Vector2f position, sf::Texture* texture, float birth = 0, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);

	void UpdateLogic(float deltaTime) override;
};
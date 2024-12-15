#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/AttackModule.h"

#pragma endregion

class BulletEntity : public CollidableEntity, public AttackModule {
public:
	BulletEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float attack = 1);
	BulletEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float attack = 1);

	virtual void Update(float deltaTime) override;
};
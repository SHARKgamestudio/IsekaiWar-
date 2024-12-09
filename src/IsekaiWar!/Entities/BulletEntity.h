#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/AttackManager.h"

#pragma endregion

class BulletEntity : public CollidableEntity, public AttackManager {
public:
	BulletEntity(float x, float y, sf::Texture* texture, float radius, float health, float attack);
	BulletEntity(sf::Vector2f pos, sf::Texture* texture, float radius, float health, float attack);
};
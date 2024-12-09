#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/AttackModule.h"

#pragma endregion

class BulletEntity : public CollidableEntity, public AttackModule {
public:
	BulletEntity(float x, float y, sf::Texture* texture, float radius, float health, float attack);
	BulletEntity(sf::Vector2f pos, sf::Texture* texture, float radius, float health, float attack);
};
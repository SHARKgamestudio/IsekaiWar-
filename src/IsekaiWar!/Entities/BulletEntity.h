#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/AttackModule.h"

#pragma endregion

class BulletEntity : public CollidableEntity, public AttackModule {
public:
	BulletEntity(float x, float y, float w, float h, sf::Texture* texture, float radius, float attack);
	BulletEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float attack);
};
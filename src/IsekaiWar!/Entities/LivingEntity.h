#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/HealthModule.h"

#pragma endregion

class LivingEntity : public CollidableEntity, public HealthModule {
public:
	LivingEntity(float x, float y, sf::Texture* texture, float radius, float health);
	LivingEntity(sf::Vector2f position, sf::Texture* texture, float radius, float health);
};
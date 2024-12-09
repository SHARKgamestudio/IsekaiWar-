#pragma once
#include "CollidableEntity.h"
#include "LifeManager.h"

class LivingEntity : public CollidableEntity, public LifeManager
{
public:

	LivingEntity(float x, float y, sf::Texture* texture, float radius, float health);
	LivingEntity(sf::Vector2f pos, sf::Texture* texture, float radius, float health);
};


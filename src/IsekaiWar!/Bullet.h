#pragma once

#include "CollidableEntity.h"
#include "AttackManager.h"

class Bullet : public CollidableEntity, public AttackManager
{
public:

	Bullet(float x, float y, sf::Texture* texture, float radius, float health, float attack);
	Bullet(sf::Vector2f pos, sf::Texture* texture, float radius, float health, float attack);
};
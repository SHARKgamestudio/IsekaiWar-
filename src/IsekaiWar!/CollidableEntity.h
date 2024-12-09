#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/Entity.h"
#include "Hitbox.h"

class CollidableEntity : public Entity, public Hitbox
{
public:

	CollidableEntity(float x, float y, sf::Texture* texture, float radius);
	CollidableEntity(sf::Vector2f pos, sf::Texture* texture, float radius);
};
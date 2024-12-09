#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Movable.h"

class VFX : public Entity, public Movable
{
public:
		
	VFX(float x, float y, sf::Texture* texture, float speed);
	VFX(sf::Vector2f pos, sf::Texture* texture, float speed);

	void virtual Move(float dt);

	void virtual Update(float dt);
};


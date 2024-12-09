#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/Hitbox.h"

#pragma endregion

class CollidableEntity : public Entity, public Hitbox {
public:
	CollidableEntity(float x, float y, sf::Texture* texture, float radius);
	CollidableEntity(sf::Vector2f pos, sf::Texture* texture, float radius);
};
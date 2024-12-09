#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/HitboxModule.h"

#pragma endregion

class CollidableEntity : public Entity, public HitboxModule {
public:
	CollidableEntity(float x, float y, sf::Texture* texture, float radius);
	CollidableEntity(sf::Vector2f pos, sf::Texture* texture, float radius);
};
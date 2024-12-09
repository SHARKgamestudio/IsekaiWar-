#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class CollidableEntity;

class HitboxModule {
protected:
	sf::Vector2f pos;
	float radius;

public:
	HitboxModule(float x, float y, float radius);
	HitboxModule(sf::Vector2f position, float radius);

	bool virtual IsColliding(CollidableEntity* hitbox) = 0;
};
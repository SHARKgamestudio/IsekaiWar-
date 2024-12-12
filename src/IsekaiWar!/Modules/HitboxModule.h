#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class CollidableEntity;

class HitboxModule {
protected:
	sf::Vector2f position;
	sf::CircleShape hitboxApparence;
	float radius;
	bool hasCollided;

public:
	HitboxModule(float x, float y, float radius);
	HitboxModule(sf::Vector2f position, float radius);

	bool virtual IsColliding(CollidableEntity* hitbox) = 0;
};
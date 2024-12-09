#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class HitboxModule {
private:
	sf::Vector2f pos;
	float radius;

public:
	HitboxModule(float x, float y, float radius);
	HitboxModule(sf::Vector2f position, float radius);

	bool IsColliding(HitboxModule hitbox);
};
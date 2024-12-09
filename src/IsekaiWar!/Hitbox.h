#pragma once
#include <SFML/Graphics.hpp>

class TangibleEntity;

class Hitbox
{
private:

	sf::Vector2f pos;
	float radius;

public:

	Hitbox(sf::Vector2f pos, float radius);
	Hitbox(float x, float y, float radius);

	bool IsColliding(Hitbox hitbox);
};


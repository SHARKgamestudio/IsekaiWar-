#pragma once
#include <SFML/Graphics.hpp>

class TravelingTexture
{
protected:

	sf::Vector2f direction;
	sf::Vector2f normalisedDirection;
	float speed;
	float u;
	float v;

	TravelingTexture(sf::Vector2f direction, float speed);

	void virtual SetDirection(sf::Vector2f direction);
	void virtual SetSpeed(float speed);
	void virtual Traveling(float dt) = 0;
};
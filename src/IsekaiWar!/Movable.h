#pragma once
#include <SFML/Graphics.hpp>

class Movable
{
protected:

	sf::Vector2f direction;
	sf::Vector2f normalisedDirection;
	float speed;

	Movable(sf::Vector2f direction, float speed);

	void virtual SetDirection(sf::Vector2f direction);
	void virtual SetSpeed(float speed);
	void virtual Move(float dt) = 0;
};
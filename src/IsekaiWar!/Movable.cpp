#include "pch.h"
#include "Movable.h"

Movable::Movable(sf::Vector2f direction, float speed)
{
	SetDirection(direction);
	SetSpeed(speed);
}

void Movable::SetDirection(sf::Vector2f direction)
{
	this->direction = direction;

	float normalCoeff = sqrt(direction.x * direction.x + direction.y * direction.y);
	normalisedDirection = sf::Vector2f(direction.x / normalCoeff, direction.y / normalCoeff);
}

void Movable::SetSpeed(float speed)
{
	this->speed = speed;
}
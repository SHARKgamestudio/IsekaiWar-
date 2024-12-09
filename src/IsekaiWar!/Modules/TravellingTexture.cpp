#include "TravelingTexture.h"
#include <math.h>

TravelingTexture::TravelingTexture(sf::Vector2f direction, float speed)
{
	SetDirection(direction);
	SetSpeed(speed);

	u = 0;
	v = 0;
}

void TravelingTexture::SetDirection(sf::Vector2f direction)
{
	this->direction = direction;

	float normalCoeff = sqrt(direction.x * direction.x + direction.y * direction.y);
	normalisedDirection = sf::Vector2f(direction.x / normalCoeff, direction.y / normalCoeff);
}

void TravelingTexture::SetSpeed(float speed)
{
	this->speed = speed;
}
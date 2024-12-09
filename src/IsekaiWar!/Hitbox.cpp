#include "pch.h"
#include "Hitbox.h"
#include <math.h>

Hitbox::Hitbox(sf::Vector2f pos, float radius)
{
	this->radius = radius;
	this->pos = pos;
}

Hitbox::Hitbox(float x, float y, float radius) : pos(sf::Vector2f(x, y))
{
	this->radius = radius;
}

bool Hitbox::IsColliding(Hitbox hitbox)
{
	sf::Vector2f diff = pos - hitbox.pos;
	float distance = sqrtf(diff.y * diff.y + diff.x * diff.x);

	if (distance < radius + hitbox.radius)
	{
		return true;
	}
	return false;
}
#include "HitboxModule.h"

#pragma region External Dependencies

#include <math.h>

#pragma endregion

HitboxModule::HitboxModule(sf::Vector2f pos, float radius) {
	this->radius = radius; this->pos = pos;
}

HitboxModule::HitboxModule(float x, float y, float radius)
	: pos(sf::Vector2f(x, y)) {
	this->radius = radius;
}

bool HitboxModule::IsColliding(HitboxModule hitbox) {
	sf::Vector2f difference = pos - hitbox.pos;
	float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

	return distance < radius + hitbox.radius;
}
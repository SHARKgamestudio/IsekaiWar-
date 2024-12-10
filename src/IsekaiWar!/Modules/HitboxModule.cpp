#include "HitboxModule.h"

#pragma region External Dependencies

#include <math.h>

#pragma endregion

HitboxModule::HitboxModule(sf::Vector2f pos, float radius) {
	this->radius = radius; this->pos = pos;
	hasCollided = false;
}

HitboxModule::HitboxModule(float x, float y, float radius)
	: pos(sf::Vector2f(x, y)) {
	this->radius = radius;
	hasCollided = false;
}
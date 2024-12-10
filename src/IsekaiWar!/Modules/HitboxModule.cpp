#include "HitboxModule.h"

#pragma region External Dependencies

#include <math.h>

#pragma endregion

HitboxModule::HitboxModule(sf::Vector2f position, float radius) {
	this->radius = radius; this->position = position;
	hasCollided = false;
}

HitboxModule::HitboxModule(float x, float y, float radius)
	: position(sf::Vector2f(x, y)) {
	this->radius = radius;
	hasCollided = false;
}
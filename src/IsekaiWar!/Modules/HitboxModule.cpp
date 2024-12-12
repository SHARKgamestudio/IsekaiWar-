#include "HitboxModule.h"

#pragma region External Dependencies

#include <math.h>

#pragma endregion

HitboxModule::HitboxModule(sf::Vector2f position, float radius) {
	this->position = position;
	this->radius = radius;
	hasCollided = false;

	hitboxApparence.setOrigin(radius, radius);
	hitboxApparence.setPosition(position);
	hitboxApparence.setRadius(radius);
	hitboxApparence.setOutlineThickness(4.f);
	hitboxApparence.setFillColor(sf::Color(0, 0, 0, 0));
	hitboxApparence.setOutlineColor(sf::Color(100, 250, 50));
}

HitboxModule::HitboxModule(float x, float y, float radius) {
	this->position = sf::Vector2f(x, y);
	this->radius = radius;
	hasCollided = false;

	hitboxApparence.setOrigin(radius, radius);
	hitboxApparence.setPosition(x, y);
	hitboxApparence.setRadius(radius);
	hitboxApparence.setOutlineThickness(4.f);
	hitboxApparence.setFillColor(sf::Color(0, 0, 0, 0));
	hitboxApparence.setOutlineColor(sf::Color(100, 250, 50));
}

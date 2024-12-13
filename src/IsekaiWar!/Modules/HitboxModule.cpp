#include "HitboxModule.h"
#include "../Entities/CollidableEntity.h"

#pragma region External Dependencies

#include <math.h>

#pragma endregion

HitboxModule::HitboxModule(sf::Vector2f position, float radius, char statut) {
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

HitboxModule::HitboxModule(float x, float y, float radius, char statut) {
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

bool HitboxModule::IsColliding(CollidableEntity* entity) {

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(position)),
		sf::Vertex(sf::Vector2f(entity->position))
	};

	checkCollisions.push_back(line);

	sf::Vector2f difference = position - entity->position;
	float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

	return distance < radius + entity->radius;
}
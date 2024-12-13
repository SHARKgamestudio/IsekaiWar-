#include "HitboxModule.h"
#include "../Entities/CollidableEntity.h"
#include "../Entities/CollidableEntity.h"

#pragma region External Dependencies

#include <cmath>

#pragma endregion

HitboxModule::HitboxModule(CollidableEntity* entity, float radius, char statut) {
	this->entity = entity;
	this->radius = radius;
	this->statut = statut;
	hasCollided = false;

	apparence.setOrigin(radius, radius);
	apparence.setRadius(radius);
	apparence.setOutlineThickness(4.f);
	apparence.setFillColor(sf::Color(0, 0, 0, 0));
	apparence.setOutlineColor(sf::Color(100, 250, 50));
}

bool HitboxModule::IsColliding(CollidableEntity* otherEntity) {
	sf::Vertex* line = new sf::Vertex[2]
	{
		sf::Vertex(sf::Vector2f(entity->getPosition())),
		sf::Vertex(sf::Vector2f(otherEntity->getPosition()))
	};

	checkCollisions.push_back(line);

	sf::Vector2f difference = entity->getPosition() - otherEntity->getPosition();
	float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

	return distance < radius + entity->hitbox->radius;
}
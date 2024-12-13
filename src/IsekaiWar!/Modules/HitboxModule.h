#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>

#pragma endregion

class CollidableEntity;

class HitboxModule {
public:

	CollidableEntity* entity;
	sf::CircleShape apparence;
	std::vector<const sf::Vertex*> checkCollisions;
	float radius;
	bool hasCollided;

	char statut; // collisions, hitbox

	HitboxModule(CollidableEntity* entity, float radius, char statut);

	bool virtual IsColliding(CollidableEntity* hitbox);
};
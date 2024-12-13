#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>

#pragma endregion

class CollidableEntity;

class HitboxModule {
protected:
	sf::Vector2f position;
	sf::CircleShape hitboxApparence;
	std::vector<const sf::Vertex*> checkCollisions;
	float radius;
	bool hasCollided;
	char statut; // collisions, hitbox

public:
	HitboxModule(float x, float y, float radius, char statut);
	HitboxModule(sf::Vector2f position, float radius, char statut);

	bool virtual IsColliding(CollidableEntity* hitbox);
};
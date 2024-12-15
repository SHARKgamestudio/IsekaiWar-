#pragma once

#include "../EnemyEntity.h"

class StandardFighter : public EnemyEntity {
private:
	sf::Vector2f spawn;
	float test = 0;
	bool spawned = false;
	Animator* animator;
public:
	StandardFighter(float x, float y, float radius = 8, float health = 1);
	StandardFighter(sf::Vector2f position, float radius = 8, float health = 1);

	void Update(float deltaTime);
};
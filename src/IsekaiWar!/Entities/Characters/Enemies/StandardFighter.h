#pragma once

#include "../EnemyEntity.h"
#include "../../../Modules/ShootModule.h"

class StandardFighter : public EnemyEntity {
private:
	sf::Vector2f spawn;
	bool spawned;
	float time;

	ShootModule* shoot;
	Animator* animator;
public:
	StandardFighter(float x, float y);
	StandardFighter(sf::Vector2f position);

	void Update(float deltaTime) override;
};
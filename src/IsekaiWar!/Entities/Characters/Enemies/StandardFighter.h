#pragma once

#include "../EnemyEntity.h"
#include "../../../Modules/ShootModule.h"

class StandardFighter : public EnemyEntity {
private:
	sf::Vector2f spawn;
	bool spawned;
	float time;

	Animator* animator;
public:
	StandardFighter(float x, float y, float birth = 0);
	StandardFighter(sf::Vector2f position, float birth = 0);

	void UpdateLogic(float deltaTime) override;
};
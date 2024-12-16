#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include "../LevelScene.h"


#pragma endregion

class Clock;

class Level1 : public LevelScene {
public:
	Clock* clock;

	std::vector<EnemyEntity*> ennemiesPool;

	void Load();
	void Update(float deltaTime) override;
};
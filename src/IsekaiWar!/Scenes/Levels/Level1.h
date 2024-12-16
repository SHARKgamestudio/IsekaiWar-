#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../LevelScene.h"

#pragma endregion

class Clock;

class Level1 : public LevelScene {
public:
	enum LevelState {
		Playing,
		Win,
		Lose
	};

	LevelState state;

	Clock* clock;
	float highest;

	std::vector<EnemyEntity*> ennemiesPool;

	void Load();
	void End();
	void Update(float deltaTime) override;
};
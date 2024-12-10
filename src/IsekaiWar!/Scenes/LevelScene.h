#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"
#include "../Entities/CollidableEntity.h"
#include "../Entities/BackgroundEntity.h"
#include "../Entities/VisualEffectEntity.h"
#include "../Utils/Clock.h"

#pragma endregion

class LevelScene : public Scene {
protected:

	Clock clock;
	//Player player;
	std::vector<BackgroundEntity> backgrounds;
	std::vector<CollidableEntity> entities;
	std::vector<VisualEffectEntity> visualEffects;

	void virtual Update(float dt);
	void virtual Draw(sf::RenderWindow& window);

public:

	void Pause();
	void Resume();
};

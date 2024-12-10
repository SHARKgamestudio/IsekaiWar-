#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>
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
	void virtual Draw(sf::RenderTarget& target, sf::RenderStates states);

public:

	void Pause();
	void Resume();
};

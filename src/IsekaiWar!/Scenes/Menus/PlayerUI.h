#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"
#include "../../UI/Components/ProgressBar.h"

#pragma endregion

class PlayerUI : public MenuScene {
public:
	float value;
	ProgressBar* healthbar;

	PlayerUI();

	void Load();

	void UpdateLogic(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};
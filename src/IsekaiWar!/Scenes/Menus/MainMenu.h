#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class Slider;

class MainMenu : public MenuScene {
public:
	Slider* slider;

	void Load();

	void Update(float deltaTime) override;

	void virtual Draw(sf::RenderWindow& window) override;

};
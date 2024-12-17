#pragma once

#pragma region External Dependencies

#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"

#pragma endregion

class MenuScene : public Scene {
public:
	void virtual Load();
	void virtual Draw(sf::RenderWindow& window) override;
};
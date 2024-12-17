#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class MainMenu : public MenuScene {
public:
	void Load();

	void Update(float deltaTime) override;
};
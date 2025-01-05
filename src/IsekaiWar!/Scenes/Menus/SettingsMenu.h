#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class SettingsMenu : public MenuScene {
public:
	bool resetCursor;

	SettingsMenu();

	void Load();

	void UpdateLogic(float dt) override;
};
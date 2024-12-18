#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class PlayerUI : public MenuScene {
public:


	PlayerUI();

	void Load();

	void UpdateLogic(float dt) override;
};
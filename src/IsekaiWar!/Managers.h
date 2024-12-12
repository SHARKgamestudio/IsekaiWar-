#pragma once

#pragma region Local Dependencies

#include "Managers/GameManager.h"
#include "Managers/InputManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/SceneManager.h"

#pragma endregion

class Managers {
private:
	static Managers* Instance;
public:
	Managers();

	GameManager* GameManager;
	InputManager* InputManager;
	ResourceManager* ResourceManager;
	SceneManager* SceneManager;

	static Managers* GetInstance();
};
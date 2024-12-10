#pragma once

#pragma region External Dependencies

#include "../Scene.h"
#include "../Scenes/LevelScene.h"

#include <string>
#include <map>

#pragma endregion

class Scene;

class SceneManager {
public:

	std::map<std::string, Scene> mainMenu;
	std::map<std::string, Scene> pauseMenu;
	std::map<std::string, Scene> levels;

	LevelScene currentLevel;
	Scene currentScene;

	void Pause();
	void Resume();

	void BackToMainMenu();
	void NavigateInMenu(std::string name);

	void LoadLevel(std::string name);
};
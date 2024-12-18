#pragma once

#pragma region External Dependencies

#include <string>
#include <map>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"
#include "../Scenes/LevelScene.h"

#pragma endregion

class Scene;

class SceneManager {
public:

	std::map<std::string, Scene*> scenes;
	std::map<std::string, LevelScene*> levels;

	sf::View viewMenu;
	sf::View viewLevel;

	LevelScene* currentLevel;
	Scene* currentScene;

	SceneManager();

	void SetViewMenu();
	void SetViewLevel();

	void Pause();
	void Resume();

	void UpdateLogic(float deltaTime);
	void Draw(sf::RenderWindow& window);

	void BackToMainMenu();
	void NavigateInMenu(std::string name);

	void LoadLevel(std::string name);
	void LoadMenu(std::string name);
};
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

	std::map<std::string, Scene*> mainMenu;
	std::map<std::string, LevelScene*> levels;

	LevelScene* currentLevel;
	Scene* currentScene;

	SceneManager();

	void Pause();
	void Resume();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	void BackToMainMenu();
	void NavigateInMenu(std::string name);

	void LoadLevel(std::string name);
};
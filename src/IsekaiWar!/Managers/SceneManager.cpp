#include "SceneManager.h"

void SceneManager::Pause() {
	currentLevel.Pause();
	currentScene = pauseMenu["pause"];
	currentScene.Load();
}

void SceneManager::Resume() {
	currentScene = currentLevel;
	(*dynamic_cast<LevelScene*>(&currentScene)).Resume();
}

void SceneManager::BackToMainMenu() {
	currentScene = mainMenu["mainMenu"];
	currentScene.Load();
}

void SceneManager::NavigateInMenu(std::string name) {
	currentScene = mainMenu[name];
	currentScene.Load();
}

void SceneManager::LoadLevel(std::string name) {
	currentScene = mainMenu[name];
	currentScene.Load();
}
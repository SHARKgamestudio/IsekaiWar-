#include "SceneManager.h"

#pragma region Local Dependencies

#include "../Scenes/Levels/Level1.h"
#include "../Scenes/Menus/MainMenu.h"
#include "../Scenes/MenuScene.h"

#pragma endregion

SceneManager::SceneManager() {
	levels["Level1"] = new Level1();
	scenes["MainMenu"] = new MainMenu();
}

void SceneManager::Pause() {
	currentScene = scenes["pause"];
	currentScene->Load();
}

void SceneManager::Resume() {
	currentScene = currentLevel;
}

void SceneManager::BackToMainMenu() {
	currentScene = scenes["mainMenu"];
	currentScene->Load();
}

void SceneManager::NavigateInMenu(std::string name) {
	currentScene = scenes[name];
	currentScene->Load();
}

void SceneManager::LoadMenu(std::string name) {
	currentScene = scenes[name];
	currentScene->Load();
}

void SceneManager::LoadLevel(std::string name) {
	currentLevel = levels[name];
	currentScene = currentLevel;
	currentScene->Load();
}

void SceneManager::UpdateLogic(float deltaTime) {
	currentScene->UpdateLogic(deltaTime);
}
void SceneManager::Draw(sf::RenderWindow& window) {
	currentScene->Draw(window);
}
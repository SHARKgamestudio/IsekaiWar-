#include "SceneManager.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../Scenes/Levels/Level1.h"

#pragma endregion

SceneManager::SceneManager() {
	levels["Level1"] = new Level1();
	currentLevel = levels["Level1"];
	currentScene = levels["Level1"];
}

void SceneManager::Pause() {
	currentScene = mainMenu["pause"];
	currentScene->Load();
}

void SceneManager::Resume() {
	currentScene = currentLevel;
}

void SceneManager::BackToMainMenu() {
	currentScene = mainMenu["mainMenu"];
	currentScene->Load();
}

void SceneManager::NavigateInMenu(std::string name) {
	currentScene = mainMenu[name];
	currentScene->Load();
}

void SceneManager::LoadLevel(std::string name) {
	currentLevel = levels[name];
	currentScene = currentLevel;
	currentScene->Load();
}

void SceneManager::Update(float deltaTime) {
	currentScene->Update(deltaTime);
}
void SceneManager::Draw(sf::RenderWindow& window) {
	currentScene->Draw(window);
}
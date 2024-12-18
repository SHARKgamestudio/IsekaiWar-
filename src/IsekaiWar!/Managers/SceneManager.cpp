#include "SceneManager.h"

#pragma region Local Dependencies

#include "../Managers.h"
#include "../Scenes/Levels/Level1.h"
#include "../Scenes/Menus/MainMenu.h"
#include "../Scenes/MenuScene.h"

#pragma endregion

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
SceneManager::SceneManager() :
	viewMenu(sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT))),
	viewLevel(sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT))) {
	levels["Level1"] = new Level1();
	scenes["MainMenu"] = new MainMenu();

	viewLevel.move(-WINDOW_WIDTH / 4, 0);
}

void SceneManager::SetViewMenu() {
	Managers::GetInstance()->GameManager->window.setView(viewMenu);
}

void SceneManager::SetViewLevel() {
	Managers::GetInstance()->GameManager->window.setView(viewLevel);
}

void SceneManager::Pause() {
	SetViewMenu();
	currentScene = scenes["pause"];
	currentScene->Load();
}

void SceneManager::Resume() {
	SetViewLevel();
	currentScene = currentLevel;
}

void SceneManager::BackToMainMenu() {
	SetViewMenu();
	currentScene = scenes["mainMenu"];
	currentScene->Load();
}

void SceneManager::NavigateInMenu(std::string name) {
	SetViewMenu();
	currentScene = scenes[name];
	currentScene->Load();
}

void SceneManager::LoadMenu(std::string name) {
	SetViewMenu();
	currentScene = scenes[name];
	currentScene->Load();
}

void SceneManager::LoadLevel(std::string name) {
	SetViewLevel();
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
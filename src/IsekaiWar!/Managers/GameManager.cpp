#include "GameManager.h"

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Managers.h"

#pragma endregion

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
GameManager::GameManager() {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!", sf::Style::Fullscreen);
}

void GameManager::Run() {
	//Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");
	Managers::GetInstance()->SceneManager->LoadLevel("Level1");
	while (window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		HandleEvents();
		UpdateLogic(deltaTime.asSeconds());
		Render();
	}
}

void GameManager::HandleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		Managers::GetInstance()->InputManager->UpdateEvents(&event);
		if (Managers::GetInstance()->InputManager->GetKeyDown("Pause"))
			window.close();
	}
}

void GameManager::UpdateLogic(float deltaTime) {
	// LOGIC GOES HERE //
	Managers::GetInstance()->SceneManager->UpdateLogic(deltaTime);
	Managers::GetInstance()->InputManager->UpdateInputs();
}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager->Draw(window);

	window.display();
}
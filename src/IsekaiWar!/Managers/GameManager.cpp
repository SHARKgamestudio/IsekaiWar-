#include "GameManager.h"

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Managers.h"
#include <iostream>

#pragma endregion

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

GameManager::GameManager() {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!");
}

void GameManager::Run() {
	Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");
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
		if (event.type == sf::Event::Closed)
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
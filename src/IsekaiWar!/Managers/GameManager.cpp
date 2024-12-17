#include "GameManager.h"

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Managers.h"
#include <iostream>

#pragma endregion

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

GameManager::GameManager() : view(sf::View(sf::FloatRect(0, 0, 1920 / 2, 1080))) {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!", sf::Style::Fullscreen);
}

void GameManager::Run() {
	Managers::GetInstance()->SceneManager->LoadLevel("Level1");
	while (window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		HandleEvents();
		Update(deltaTime.asSeconds());
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

void GameManager::Update(float deltaTime) {

	// LOGIC GOES HERE //
	Managers::GetInstance()->SceneManager->Update(deltaTime);
	Managers::GetInstance()->InputManager->UpdateInputs();
	view.setViewport(sf::FloatRect(1920 / 4, 1080, 1920 / 2, 1080));
}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager->Draw(window);

	window.display();
}
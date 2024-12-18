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

GameManager::GameManager() : view(sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT))) {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!", sf::Style::Fullscreen);
	view.move(-WINDOW_WIDTH / 4, 0);
	window.setView(view);
}

void GameManager::Run() {
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
	view.setViewport(sf::FloatRect(1920 / 4, 1080, 1920 / 2, 1080));
}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager->Draw(window);

	window.display();
}
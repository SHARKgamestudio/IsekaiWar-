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
	Managers::GetInstance()->SceneManager.LoadLevel("Level1");
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
		Managers::GetInstance()->InputManager.UpdateEvents(&event);
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void GameManager::Update(float deltaTime) {

	Managers::GetInstance()->SceneManager.Update(deltaTime);

	Managers::GetInstance()->InputManager.UpdateInputs();

	std::cout << Managers::GetInstance()->InputManager.GetAxis("Vertical") << std::endl;

	if (Managers::GetInstance()->InputManager.GetKeyDown("Shoot")) {
		std::cout << "Pressed" << std::endl;
	}
	if (Managers::GetInstance()->InputManager.GetKeyUp("Shoot")) {
		std::cout << "Released" << std::endl;
	}
}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager.Draw(window);

	window.display();
}
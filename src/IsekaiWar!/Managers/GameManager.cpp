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
		if (event.type == sf::Event::Closed)
			window.close();

		Managers::GetInstance()->InputManager.Update(&event);

		if (event.type == sf::Event::JoystickButtonPressed) {
			//std::cout << event.joystickButton.button << std::endl;
		}
	}
}

void GameManager::Update(float deltaTime) {

	// LOGIC GOES HERE //
	Managers::GetInstance()->SceneManager.Update(deltaTime);
	//std::cout << Managers::GetInstance()->InputManager.GetAxis("Horizontal") << std::endl;
	//std::cout << Managers::GetInstance()->InputManager.GetKey("Shoot") << std::endl;

}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager.Draw(window);

	window.display();
}
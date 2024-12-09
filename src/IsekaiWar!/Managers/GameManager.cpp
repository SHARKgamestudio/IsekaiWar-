#include "GameManager.h"

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

GameManager::GameManager() {
	window.create(sf::VideoMode(800, 600), "IsekaiWar!");
}

void GameManager::Run() {
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
	}
}

void GameManager::Update(float deltaTime) {

	// LOGIC GOES HERE //

}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //

	window.display();
}
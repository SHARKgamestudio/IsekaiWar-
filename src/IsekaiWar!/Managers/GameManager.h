#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class GameManager {
private:
	sf::RenderWindow window;
	sf::Clock clock;

	void UpdateLogic(float deltaTime);
	void HandleEvents();
	void Render();

	GameManager();

public:
	void Run();

	friend class Managers;
};
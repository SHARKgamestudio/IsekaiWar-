#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class GameManager {
private:
	sf::RenderWindow window;
	sf::Clock clock;

	void Update(float deltaTime);
	void HandleEvents();
	void Render();

	GameManager();

public:
	void Run();

	friend class Managers;
};
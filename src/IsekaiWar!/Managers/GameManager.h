#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class GameManager {
private:
	bool running;

	sf::RenderWindow window;
	sf::Clock clock;

	void DisplayLoadingScreen();

	void UpdateLogic(float deltaTime);
	bool HandleEvents();
	void Render();

	GameManager();

public:
	void Run();
	void Stop();

	friend class Managers;
	friend class SceneManager;
};
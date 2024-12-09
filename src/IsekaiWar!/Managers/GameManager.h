#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Utils/Resources.h"
#include "../SpriteBackground.h"

#pragma endregion

class GameManager {
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
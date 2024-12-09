#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "SpriteBackground.h"

class GameManager
{
	sf::RenderWindow window;
	sf::Clock clock;

	Data data;
	SpriteBackground* background;

	static GameManager* mInstance;
	GameManager();

	void HandleInput();
	void Update(float dt);
	void Display();
		
public:

	static GameManager* GetInstance();
	void Run();
};


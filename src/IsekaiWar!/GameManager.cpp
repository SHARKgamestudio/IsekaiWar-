#include "pch.h"
#include "GameManager.h"
#include "string"
#include "vector"

const std::string beginPath = "../../../src/IsekaiWar!/";

GameManager* GameManager::mInstance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}

	return mInstance;
}

GameManager::GameManager() : data()
{
	window.create(sf::VideoMode(800, 600), "enêtre");

	std::vector<std::string> namesTexture = {
		"water"
	};

	std::vector<std::string> pathsTexture = {
		beginPath + "water.jpg"
	};

	for (int i = 0; i < 1; i++)
	{
		data.SetTexture(namesTexture[i], pathsTexture[i]);
	}

	background = new SpriteBackground(0, 0, data.getTexture("water"), 20.f);
}

void GameManager::Run()
{
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		HandleInput();
		Update(dt.asSeconds());
		Display();
	}
}

void GameManager::HandleInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void GameManager::Update(float dt)
{
	background->Update(dt);
}

void GameManager::Display()
{
	window.clear();

	window.draw(*background);

	window.display();
}
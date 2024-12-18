#include "GameManager.h"

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Managers.h"
#include "../Utils/OS.h"

#pragma endregion

const std::string DEBUG_PATH = "../../../src/IsekaiWar!/";

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

GameManager::GameManager() {
	running = false;
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!", sf::Style::Fullscreen);
}

void GameManager::Run() {
	running = true;
	DisplayLoadingScreen();

	Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");

	while (window.isOpen() && running) {
		sf::Time deltaTime = clock.restart();
		HandleEvents();
		UpdateLogic(deltaTime.asSeconds());
		Render();
	}

	window.close();
}

void GameManager::Stop() {
	running = false;
}

void GameManager::HandleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		Managers::GetInstance()->InputManager->UpdateEvents(&event);
		if (event.type == sf::Event::Closed) { Stop(); }
	}
}

void GameManager::DisplayLoadingScreen() {
	std::string path = "";

	#ifdef _DEBUG
		path = OS::GetAbsolutePath(DEBUG_PATH) + "Assets/";
	#else
		path = OS::GetExecutablePath() + "/resourcepacks/";
	#endif

	sf::Texture engineLogoTexture;
	engineLogoTexture.loadFromFile(path + "engine-logo.png");

	sf::Sprite engineLogo;
	engineLogo.setTexture(engineLogoTexture);
	engineLogo.setOrigin(engineLogo.getLocalBounds().width / 2, engineLogo.getLocalBounds().height / 2);
	engineLogo.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);


	sf::Font font;
	font.loadFromFile(path + "font.ttf");

	sf::Text loadingText;
	loadingText.setFont(font);
	loadingText.setString("loading resources..");
	loadingText.setCharacterSize(48);
	loadingText.setFillColor(sf::Color::White);
	loadingText.setOrigin(loadingText.getLocalBounds().width / 2, loadingText.getLocalBounds().height / 2);
	loadingText.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 1.2f);
	
	window.clear();

	window.draw(engineLogo);
	window.draw(loadingText);

	window.display();

	Managers::GetInstance()->ResourceManager->LoadResources();
}

void GameManager::UpdateLogic(float deltaTime) {
	// LOGIC GOES HERE //
	Managers::GetInstance()->SceneManager->UpdateLogic(deltaTime);
	Managers::GetInstance()->InputManager->UpdateInputs();
}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager->Draw(window);

	window.display();
}
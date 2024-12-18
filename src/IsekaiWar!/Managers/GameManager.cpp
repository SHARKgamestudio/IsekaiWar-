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
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!", sf::Style::Fullscreen);
}

void GameManager::Run() {
	DisplayLoadingScreen();

	Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");
	//Managers::GetInstance()->SceneManager->LoadLevel("Level1");
	while (window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		HandleEvents();
		UpdateLogic(deltaTime.asSeconds());
		Render();
	}
}

void GameManager::HandleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		Managers::GetInstance()->InputManager->UpdateEvents(&event);
		if (Managers::GetInstance()->InputManager->GetKey("Pause"))
			window.close();
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void GameManager::DisplayLoadingScreen() {
	std::string path = "";

	#ifdef _DEBUG
		path = OS::GetAbsolutePath(DEBUG_PATH) + "Assets/";
	#else
		path = OS::GetExecutablePath() + "/resourcepacks/";
	#endif

	sf::Font font;
	font.loadFromFile(path);

	sf::Text loadingText;
	loadingText.setFont(font);
	loadingText.setString("Loading Resources..");
	loadingText.setCharacterSize(24);
	loadingText.setFillColor(sf::Color::Red);
	loadingText.setOrigin(loadingText.getLocalBounds().width / 2, loadingText.getLocalBounds().height / 2);
	loadingText.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	
	window.clear();

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
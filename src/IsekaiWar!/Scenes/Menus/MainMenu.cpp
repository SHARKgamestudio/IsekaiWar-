#include "MainMenu.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"

#pragma endregion

void MainMenu::Load() {
	std::cout << "Main Menu Loaded" << std::endl;

	Spritesheet* play_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("button"), 1, 4);
	sf::Text* play_text = new sf::Text();
	play_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	play_text->setString("Play");
	play_text->setCharacterSize(30);
	Button* play_button = new Button(play_text, play_spritesheet);
	play_button->SetScale(0.25f, 0.25f);
	play_button->setPosition(1920 / 2, 300);
	elements.push_back(play_button);

	Spritesheet* settings_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("button"), 1, 4);
	sf::Text* settings_text = new sf::Text();
	settings_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	settings_text->setString("Settings");
	settings_text->setCharacterSize(30);
	Button* settings_button = new Button(settings_text, settings_spritesheet);
	settings_button->SetScale(0.25f, 0.25f);
	settings_button->setPosition(1920 / 2, 400);
	elements.push_back(settings_button);

	Spritesheet* quit_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("button"), 1, 4);
	sf::Text* quit_text = new sf::Text();
	quit_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	quit_text->setString("Quit");
	quit_text->setCharacterSize(30);
	Button* quit_button = new Button(quit_text, quit_spritesheet);
	quit_button->SetScale(0.25f, 0.25f);
	quit_button->setPosition(1920/2, 500);
	elements.push_back(quit_button);
}

void MainMenu::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	//Button* button = (Button*)elements[0];
	//if (button->IsPressed()) {
	//	button->Disable();
	//}
}
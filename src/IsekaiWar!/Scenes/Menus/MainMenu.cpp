#include "MainMenu.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"
#include "../../UI/Components/Image.h"

#pragma endregion

void MainMenu::Load() {
	std::cout << "Main Menu Loaded" << std::endl;

	Spritesheet* background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("background"), 1, 1);
	Image* background_image = new Image(background_spritesheet);
	background_image->setScale(1, 1);
	background_image->setPosition(1920/2, 1080/2);
	elements.push_back(background_image);

	Spritesheet* logo_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("logo"), 1, 1);
	Image* logo_image = new Image(logo_spritesheet);
	logo_image->setScale(1, 1);
	logo_image->setPosition(1920 / 2, 284);
	elements.push_back(logo_image);

	Spritesheet* play_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("play-button"), 1, 4);
	sf::Text* play_text = new sf::Text();
	play_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	play_text->setString("");
	play_text->setCharacterSize(30);
	Button* play_button = new Button(play_text, play_spritesheet);
	play_button->SetScale(1, 1);
	play_button->setPosition(1920 / 2, 598);
	elements.push_back(play_button);

	Spritesheet* settings_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("settings-button"), 1, 4);
	sf::Text* settings_text = new sf::Text();
	settings_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	settings_text->setString("");
	settings_text->setCharacterSize(30);
	Button* settings_button = new Button(settings_text, settings_spritesheet);
	settings_button->SetScale(1, 1);
	settings_button->setPosition(1920 / 2, 748);
	elements.push_back(settings_button);

	Spritesheet* quit_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("quit-button"), 1, 4);
	sf::Text* quit_text = new sf::Text();
	quit_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	quit_text->setString("");
	quit_text->setCharacterSize(30);
	Button* quit_button = new Button(quit_text, quit_spritesheet);
	quit_button->SetScale(1, 1);
	quit_button->setPosition(1920/2, 898);
	elements.push_back(quit_button);
}

void MainMenu::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	Button* button = (Button*)elements[2];
	if (button->IsPressed()) {
		button->Disable();
		Managers::GetInstance()->SceneManager->LoadLevel("Level1");
	}
}
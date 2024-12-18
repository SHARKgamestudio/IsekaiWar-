#include "PlayerUI.h"

#pragma region External Dependencies

#include <iostream>
#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"
#include "../../UI/Components/Image.h"

#pragma endregion

PlayerUI::PlayerUI() {
}

void PlayerUI::Load() {
	Spritesheet* background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("border"), 1, 1);
	Image* left_background_image = new Image(background_spritesheet);
	left_background_image->setScale(1.3f, 1.35f);
	left_background_image->setPosition(150, 538);
	elements.push_back(left_background_image);

	Image* right_background_image = new Image(background_spritesheet);
	right_background_image->setScale(1.3f, 1.35f);
	right_background_image->setPosition(1760, 538);
	elements.push_back(right_background_image);

	Spritesheet* play_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("play-button"), 1, 4);
	sf::Text* play_text = new sf::Text();
	play_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	play_text->setString("");
	play_text->setCharacterSize(30);
	Button* play_button = new Button(play_text, play_spritesheet);
	play_button->SetScale(1, 1);
	play_button->setPosition(1920 / 2, 598);
	elements.push_back(play_button);

	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);
	cursor->setPosition(2000, 2000);
}

void PlayerUI::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	//Button* play_button = (Button*)elements[2];
	//if (play_button->IsPressed()) {
	//	play_button->Disable();
	//	Managers::GetInstance()->SceneManager->LoadLevel("Level1");
	//}
}
#include "SettingsMenu.h"

#pragma region External Dependencies

#include <iostream>
#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"
#include "../../UI/Components/Image.h"
#include "../../UI/Components/Label.h"

#pragma endregion

SettingsMenu::SettingsMenu() {
	resetCursor = true;
}

void SettingsMenu::Load() {
	Spritesheet* background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("background"), 1, 1);
	Image* background_image = new Image(background_spritesheet);
	background_image->setScale(1, 1);
	background_image->setPosition(1920/2, 1080/2);
	elements.push_back(background_image);

	Label* gameover_label = new Label("SETTINGS");
	gameover_label->SetCharSize(64);
	gameover_label->setPosition(151, 256);
	elements.push_back(gameover_label);

	Spritesheet* audio_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* audio_text = new sf::Text();
	audio_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	audio_text->setString("AUDIO");
	audio_text->setCharacterSize(8);
	audio_text->setScale(0.55f, 0.55f);
	Button* audio_button = new Button(audio_text, audio_spritesheet);
	audio_button->SetScale(1, 1);
	audio_button->setPosition(256+32, 452);
	elements.push_back(audio_button);
	audio_text->setOrigin(audio_text->getLocalBounds().width / 2, audio_text->getLocalBounds().height / 1.1f);

	Spritesheet* keybinds_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* keybinds_text = new sf::Text();
	keybinds_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	keybinds_text->setString("KEYBINDS");
	keybinds_text->setCharacterSize(8);
	keybinds_text->setScale(0.55f, 0.55f);
	Button* keybinds_button = new Button(keybinds_text, keybinds_spritesheet);
	keybinds_button->SetScale(1, 1);
	keybinds_button->setPosition(256 + 32, 602);
	elements.push_back(keybinds_button);
	keybinds_text->setOrigin(keybinds_text->getLocalBounds().width / 2, keybinds_text->getLocalBounds().height / 1.1f);

	Spritesheet* back_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* back_text = new sf::Text();
	back_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	back_text->setString("BACK");
	back_text->setCharacterSize(8);
	back_text->setScale(0.55f, 0.55f);
	Button* back_button = new Button(back_text, back_spritesheet);
	back_button->SetScale(1, 1);
	back_button->setPosition(256 + 32, 752);
	elements.push_back(back_button);
	back_text->setOrigin(back_text->getLocalBounds().width / 2, back_text->getLocalBounds().height / 1.1f);





	Label* horizontal_label = new Label("Horizontal");
	horizontal_label->SetCharSize(28);
	horizontal_label->setPosition(570, 735);
	elements.push_back(horizontal_label);

	Spritesheet* neg_kbrd_horizontal_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* neg_kbrd_horizontal_text = new sf::Text();
	neg_kbrd_horizontal_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	neg_kbrd_horizontal_text->setString("Q");
	neg_kbrd_horizontal_text->setCharacterSize(8);
	neg_kbrd_horizontal_text->setScale(0.55f, 0.55f);
	Button* neg_kbrd_horizontal_button = new Button(neg_kbrd_horizontal_text, neg_kbrd_horizontal_spritesheet);
	neg_kbrd_horizontal_button->SetScale(0.75f, 0.75f);
	neg_kbrd_horizontal_button->setPosition(910, 752);
	elements.push_back(neg_kbrd_horizontal_button);
	neg_kbrd_horizontal_text->setOrigin(neg_kbrd_horizontal_text->getLocalBounds().width / 2, neg_kbrd_horizontal_text->getLocalBounds().height / 1.1f);

	Spritesheet* pos_kbrd_horizontal_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* pos_kbrd_horizontal_text = new sf::Text();
	pos_kbrd_horizontal_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	pos_kbrd_horizontal_text->setString("D");
	pos_kbrd_horizontal_text->setCharacterSize(8);
	pos_kbrd_horizontal_text->setScale(0.55f, 0.55f);
	Button* pos_kbrd_horizontal_button = new Button(pos_kbrd_horizontal_text, pos_kbrd_horizontal_spritesheet);
	pos_kbrd_horizontal_button->SetScale(0.75f, 0.75f);
	pos_kbrd_horizontal_button->setPosition(1280, 752);
	elements.push_back(pos_kbrd_horizontal_button);
	pos_kbrd_horizontal_text->setOrigin(pos_kbrd_horizontal_text->getLocalBounds().width / 2, pos_kbrd_horizontal_text->getLocalBounds().height / 1.1f);

	Spritesheet* gmpd_horizontal_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* gmpd_horizontal_text = new sf::Text();
	gmpd_horizontal_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	gmpd_horizontal_text->setString("D");
	gmpd_horizontal_text->setCharacterSize(8);
	gmpd_horizontal_text->setScale(0.55f, 0.55f);
	Button* gmpd_horizontal_button = new Button(gmpd_horizontal_text, gmpd_horizontal_spritesheet);
	gmpd_horizontal_button->SetScale(0.75f, 0.75f);
	gmpd_horizontal_button->setPosition(1650, 752);
	elements.push_back(gmpd_horizontal_button);
	gmpd_horizontal_text->setOrigin(gmpd_horizontal_text->getLocalBounds().width / 2, gmpd_horizontal_text->getLocalBounds().height / 1.1f);











	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);

	resetCursor = true;
}

void SettingsMenu::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	Button* back_button = (Button*)elements[4];
	if (back_button->IsPressed()) {
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");
	}

	if (Managers::GetInstance()->InputManager->isJoystickConnected()) {
		if (resetCursor) { cursor->setPosition(256 + 32, 752); resetCursor = false; }
		cursor->move(Managers::GetInstance()->InputManager->GetAxis("Horizontal") * dt * 512, Managers::GetInstance()->InputManager->GetAxis("Vertical") * dt * 512);
	}
	else {
		cursor->setPosition(2000, 2000);
		resetCursor = true;
	}
}
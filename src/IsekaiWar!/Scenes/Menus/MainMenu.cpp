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

	Spritesheet* spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("button"), 1, 4);

	sf::Text* text = new sf::Text();
	text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	text->setString("Go fuck yourself");
	text->setCharacterSize(30);

	Button* button = new Button(text, spritesheet);
	button->SetScale(0.25f, 0.25f);
	button->setPosition(400, 300);

	elements.push_back(button);
}

void MainMenu::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	Button* button = (Button*)elements[0];

	if (button->IsPressed()) {
		button->Disable();
	}
}
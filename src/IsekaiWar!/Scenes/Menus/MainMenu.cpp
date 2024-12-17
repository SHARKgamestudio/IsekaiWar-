#include "MainMenu.h"

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"

#include <iostream>

void MainMenu::Load() {
	std::cout << "Main Menu Loaded" << std::endl;

	Spritesheet* spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("button"), 1, 4);

	sf::Text* text = new sf::Text();
	text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	text->setString("Go fuck yourself");
	text->setCharacterSize(30);

	Button* button = new Button(text, spritesheet);
	button->setScale(0.5f, 0.5f);
	button->setPosition(400, 300);

	elements.push_back(button);
}
#include "MainMenu.h"

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"

#include <iostream>

void MainMenu::Load() {
	std::cout << "Main Menu Loaded" << std::endl;

	Spritesheet* spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("button"), 1, 4);
	spritesheet->setOrigin(1024/2, 256/2);

	sf::Text* text = new sf::Text();
	text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	text->setString("Hello World");
	text->setCharacterSize(30);

	Button* button = new Button(text, spritesheet);
	button->setPosition(800/2, 600/2);

	elements.push_back(button);
}
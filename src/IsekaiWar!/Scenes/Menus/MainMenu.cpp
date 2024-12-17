#include "MainMenu.h"

#include <iostream>

#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Slider.h"
#include "../../Managers.h"

void MainMenu::Load() {
	std::cout << "Main Menu Loaded" << std::endl;

	Spritesheet background = Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("water"), 1, 1);
	background.setScale(0.15f, 0.15f);

	Spritesheet handle = Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("water"), 1, 1);
	handle.setScale(0.15f, 0.15f);

	slider = new Slider(&handle, &background);

	slider->setPosition(400, 300);

}

void MainMenu::Update(float deltaTime) {
	std::cout << "Main Menu Update" << std::endl;

}

void MainMenu::Draw(sf::RenderWindow& window) {

	slider->Update(window);
}
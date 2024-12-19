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
#include "../../UI/Components/Label.h"
#include "../../UI/Components/ProgressBar.h"

#pragma endregion

PlayerUI::PlayerUI() {
}

void PlayerUI::Load() {
	Spritesheet* left_background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-background"), 1, 1);
	left_background_spritesheet->sprite.setOrigin(0, 0);
	Image* left_background_image = new Image(left_background_spritesheet);
	left_background_image->setScale(1, 1);
	left_background_image->setPosition(-55, 0);
	elements.push_back(left_background_image);

	Spritesheet* right_background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-background"), 1, 1);
	right_background_spritesheet->sprite.setOrigin(0, 0);
	Image* right_background_image = new Image(right_background_spritesheet);
	right_background_image->setScale(1, 1);
	right_background_image->setPosition(1400, 0);
	elements.push_back(right_background_image);

	Spritesheet* maxine_title_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("maxine-title"), 1, 1);
	maxine_title_spritesheet->sprite.setOrigin(0, 0);
	Image* maxine_title_image = new Image(maxine_title_spritesheet);
	maxine_title_image->setScale(1, 1);
	maxine_title_image->setPosition(62, 159);
	elements.push_back(maxine_title_image);

	Label* score_label = new Label("1536", Center);
	score_label->setPosition(1570, 350);
	score_label->SetCharSize(128);
	elements.push_back(score_label);

	Label* xp_label = new Label("XP", Center);
	xp_label->setPosition(1775, 470);
	xp_label->SetCharSize(48);
	elements.push_back(xp_label);

	Spritesheet* score_title_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("score-title"), 1, 1);
	score_title_spritesheet->sprite.setOrigin(0, 0);
	Image* score_title_image = new Image(score_title_spritesheet);
	score_title_image->setScale(1, 1);
	score_title_image->setPosition(1510, 159);
	elements.push_back(score_title_image);

	Spritesheet* left_healthbar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-health-progress"), 1, 1);
	Spritesheet* middle_healthbar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-health-progress"), 1, 1);
	Spritesheet* right_healthbar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-health-progress"), 1, 1);

	Spritesheet* left_healthbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-health-background"), 1, 1);
	Spritesheet* middle_healthbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-health-background"), 1, 1);
	Spritesheet* right_healthbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-health-background"), 1, 1);

	ProgressBar* healthbar = new ProgressBar(left_healthbar_spritesheet, middle_healthbar_spritesheet, right_healthbar_spritesheet, left_healthbackground_spritesheet, middle_healthbackground_spritesheet, right_healthbackground_spritesheet, 296);
	healthbar->SetFactors(6, 9, 18);
	healthbar->setPosition(100, 500);
	healthbar->SetValue(50);
	elements.push_back(healthbar);

	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);
	cursor->setPosition(2000, 2000);
}

void PlayerUI::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

}
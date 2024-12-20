#include "Level1.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../../Entities/Characters/Enemies/StandardFighterVar0.h"
#include "../../Entities/Characters/Enemies/StandardFighterVar1.h"
#include "../../Entities/Characters/Enemies/StandardFighterVar2.h"
#include "../../Entities/Characters/Enemies/LightFighter.h"
#include "../../Entities/Characters/Enemies/HeavyFighter.h"

#include "../../Utils/Clock.h"

#pragma endregion

Level1::Level1() {
	current = LevelState::Playing;
	clock = new Clock();
	highest = 0;
	score = 0;
	multiplicator = 1.f;
}

void Level1::Load() {
	LevelScene::Load();

	Managers::GetInstance()->SoundManager->PlayMusic("soundtrack");

	clock = new Clock(true);

	ennemiesPool = {
		//// WAVE 1
		//new StandardFighter(196, 125, 0.0f),

		//// WAVE 2
		//new StandardFighter(640, 300, 2.f),
		//new StandardFighter(300, 500, 2.f),
		//new StandardFighter(196, 125, 2.f),

		//// WAVE 3
		//new StandardFighter(150, 300, 4.f),
		//new StandardFighter(300, 400, 4.f),
		//new StandardFighter(450, 300, 4.f),
		//new StandardFighter(600, 400, 4.f),
		//new StandardFighter(750, 300, 4.f),

		//// WAVE 3
		//new StandardFighter(150, 300, 6.f),
		//new StandardFighter(300, 400, 6.f),
		//new StandardFighter(450, 300, 6.f),
		//new StandardFighter(600, 400, 6.f),
		//new StandardFighter(750, 300, 6.f),
		//new StandardFighter(150, 500, 6.f),
		//new StandardFighter(300, 600, 6.f),
		//new StandardFighter(450, 500, 6.f),
		//new StandardFighter(600, 600, 6.f),
		//new StandardFighter(750, 500, 6.f),

		new StandardFighterVar0(400, 250, 0.0f),
		new StandardFighterVar1(600, 500, 0.0f),
		//new StandardFighterVar2(100, 700, 0.0f),
		//new LightFighter(650, 700, 0.0f),
		//new HeavyFighter(400, 250, 0.0f),
	};

	for (int i = 0; i < ennemiesPool.size(); i++) {
		if (ennemiesPool[i]->birth > highest) highest = ennemiesPool[i]->birth;
	}

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("forest"), sf::Vector2f(600, 800), sf::Vector2f(1400, 1200)));
	player = new PlayerEntity();
	current = Playing;
}

void Level1::End() {
	// EXECUTE AT THE END OF THE LEVEL //

	if (current == Lose) {
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("GameOver");
	}
	else if (current == Win) {
		Managers::GetInstance()->SceneManager->currentLevel->score = score;
		//Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenuAsync("Win");
	}
	
	//Managers::GetInstance()->SceneManager->LoadLevelAsync("Level1");
}

void Level1::UpdateLogic(float deltaTime) {
	LevelScene::UpdateLogic(deltaTime);

	clock->UpdateLogic(deltaTime);

	float time = clock->GetTime();

	for (int i = 0; i < ennemiesPool.size(); i++) {
		if (time >= float(ennemiesPool[i]->birth)) {
			SpawnEnnemy(ennemiesPool[i]);
			ennemiesPool.erase(ennemiesPool.begin() + i);
		}
	}

	if (player->IsDead()) {
		current = Lose;
		End();
	}

	if (ennemies.size() == 0) {
		if (time >= highest) {
			current = Win;
			End();	
		}

		clock->Resume();
	}
	else { clock->Pause(); }
}
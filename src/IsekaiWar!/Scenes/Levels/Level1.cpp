#include "Level1.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../../Entities/Characters/Enemies/StandardFighter.h"
#include "../../Entities/PowerUps/FirePowerUp.h"
#include "../../Entities/PowerUps/WaterPowerUp.h"

#include "../../Utils/Clock.h"

#pragma endregion

Level1::Level1() {
	current = LevelState::Playing;
	clock = new Clock();
	highest = 0;
}

void Level1::Load() {
	Managers::GetInstance()->SoundManager->PlayMusic("music");

	clock = new Clock(true);

	ennemiesPool = {
		// WAVE 1
		new StandardFighter(196, 125, 0.0f),

		// WAVE 2
		new StandardFighter(640, 300, 2.f),
		new StandardFighter(300, 500, 2.f),
		new StandardFighter(196, 125, 2.f),

		// WAVE 3
		new StandardFighter(150, 300, 4.f),
		new StandardFighter(300, 400, 4.f),
		new StandardFighter(450, 300, 4.f),
		new StandardFighter(600, 400, 4.f),
		new StandardFighter(750, 300, 4.f),

		// WAVE 3
		new StandardFighter(150, 300, 6.f),
		new StandardFighter(300, 400, 6.f),
		new StandardFighter(450, 300, 6.f),
		new StandardFighter(600, 400, 6.f),
		new StandardFighter(750, 300, 6.f),
		new StandardFighter(150, 500, 6.f),
		new StandardFighter(300, 600, 6.f),
		new StandardFighter(450, 500, 6.f),
		new StandardFighter(600, 600, 6.f),
		new StandardFighter(750, 500, 6.f),
	};

	for (int i = 0; i < ennemiesPool.size(); i++) {
		if (ennemiesPool[i]->birth > highest) highest = ennemiesPool[i]->birth;
	}

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("water")));
	player = new PlayerEntity();
	SpawnEntity(new FirePowerUp(200, 0));
	SpawnEntity(new WaterPowerUp(600, 0));
	current = Playing;
}

void Level1::End() {
	// EXECUTE AT THE END OF THE LEVEL //

	std::cout << "Level Ended" << std::endl;
	std::cout << "State: " << current << std::endl;
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
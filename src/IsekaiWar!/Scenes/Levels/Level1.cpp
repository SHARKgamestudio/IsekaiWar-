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
	state = LevelState::Playing;
	clock = new Clock();
	highest = 0;
}

void Level1::Load() {
	Managers::GetInstance()->SoundManager->PlayMusic("music");

	clock = new Clock(true);

	ennemiesPool = {
		new StandardFighter(196, 125, 0.0f),
		new StandardFighter(640, 300, 10.0f),
		new StandardFighter(196, 125, 10.0f),
		new StandardFighter(640, 300, 20.0f)
	};

	for (int i = 0; i < ennemiesPool.size(); i++) {
		if (ennemiesPool[i]->birth > highest) highest = ennemiesPool[i]->birth;
	}

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("water")));
	player = new PlayerEntity();
	SpawnEntity(new FirePowerUp(200, 0));
	SpawnEntity(new WaterPowerUp(600, 0));
	state = Playing;
}

void Level1::End() {
	// EXECUTE AT THE END OF THE LEVEL //

	std::cout << "Level Ended" << std::endl;
	std::cout << "State: " << state << std::endl;
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
		state = Lose;
		End();
	}

	if (ennemies.size() == 0) {
		if (time >= highest) {
			state = Win;
			End();	
		}

		clock->Resume();
	}
	else { clock->Pause(); }
}
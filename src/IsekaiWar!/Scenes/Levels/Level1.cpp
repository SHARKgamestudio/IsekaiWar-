#include "Level1.h"

#pragma region External Dependencies

#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../../Entities/Characters/Enemies/StandardFighter.h"
#include "../../Utils/Clock.h"
#include <iostream>

#pragma endregion

void Level1::Load() {
	clock = new Clock(true);

	ennemiesPool = {
		new StandardFighter(196, 125, 0.0f),
		new StandardFighter(640, 300, 10.0f),
		new StandardFighter(196, 125, 10.0f),
		new StandardFighter(640, 300, 20.0f)
	};

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("water")));

	//for (EnemyEntity* ennemy : newEnnemies) {
	//	SpawnEnnemy(ennemy);
	//}

	player = new PlayerEntity(800/2, 600/2, Managers::GetInstance()->ResourceManager->GetTexture("player"), 5, 4, 32.f, 100.f);
}

void Level1::Update(float deltaTime) {
	LevelScene::Update(deltaTime);

	clock->Update(deltaTime);

	float time = clock->GetTime();

	for (int i = 0; i < ennemiesPool.size(); i++) {
		std::cout << time << std::endl;
		if (time >= float(ennemiesPool[i]->birth)) {
			SpawnEnnemy(ennemiesPool[i]);
			ennemiesPool.erase(ennemiesPool.begin() + i);
		}
	}

	if (ennemies.size() == 0) {
		clock->Resume();
	}
	else { clock->Pause(); }
}
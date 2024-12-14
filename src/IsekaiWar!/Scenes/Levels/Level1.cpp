#pragma region External Dependencies

#include "Level1.h"
#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullet/SpecialBullet.h"
#include "../../Entities/Characters/EnemyEntity.h"

#pragma endregion

void Level1::Load() {
	clock.Start();

	std::vector<BackgroundEntity*> newBackgrounds = {
		new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("water"))
	};

	std::vector<CollidableEntity*> newEntities = {
		new EnemyEntity(800 / 2, 150, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), 6, 1, 8, 1)
	};

	std::vector<VisualEffectEntity*> newVisualEffects;

	for (BackgroundEntity* background : newBackgrounds) {
		backgrounds.push_back(background);
	}

	for (CollidableEntity* entity : newEntities) {
		SpawnEntity(entity);
	}

	player = new Player(800/2, 600/2, Managers::GetInstance()->ResourceManager->GetTexture("player"), 5, 4, 32.f, 100.f);
}
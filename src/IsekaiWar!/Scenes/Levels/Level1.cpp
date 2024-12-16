#include "Level1.h"

#pragma region External Dependencies

#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../../Entities/Characters/Enemies/StandardFighter.h"

#pragma endregion

void Level1::Load() {

	std::vector<BackgroundEntity*> newBackgrounds = {
		new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("water"))
	};

	std::vector<CollidableEntity*> newEntities = {};

	std::vector<EnemyEntity*> newEnnemies = {
		new StandardFighter(196, 125),
		new StandardFighter(640, 300)
	};

	for (BackgroundEntity* background : newBackgrounds) {
		backgrounds.push_back(background);
	}

	for (CollidableEntity* entity : newEntities) {
		SpawnEntity(entity);
	}

	for (EnemyEntity* ennemy : newEnnemies) {
		SpawnEnnemy(ennemy);
	}

	player = new PlayerEntity(800/2, 600/2, Managers::GetInstance()->ResourceManager->GetTexture("player"), 5, 4, 32.f, 100.f);
}
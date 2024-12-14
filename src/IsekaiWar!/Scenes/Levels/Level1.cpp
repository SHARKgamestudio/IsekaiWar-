#pragma region External Dependencies

#include "Level1.h"
#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../../Entities/Characters/EnemyEntity.h"

#pragma endregion

void Level1::Load() {
	clock.Start();

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("water")));

	entities.push_back(new EnemyEntity(800/2, 150, Managers::GetInstance()->ResourceManager->GetTexture("fireball"), 6, 1, 8, 1));

	player = new PlayerEntity(800/2, 600/2, Managers::GetInstance()->ResourceManager->GetTexture("player"), 5, 4, 32.f, 100.f);
}
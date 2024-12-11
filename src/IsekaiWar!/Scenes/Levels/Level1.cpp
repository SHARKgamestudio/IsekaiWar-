#pragma region External Dependencies

#include "Level1.h"
#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullet/SpecialBullet.h"

#pragma endregion

void Level1::Load() {
	clock.Start();

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager.GetTexture("water")));
	entities.push_back(new SpecialBullet(150.f, 300.f, 150.f, 150.f));
}
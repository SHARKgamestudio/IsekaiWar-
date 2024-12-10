#include "Level1.h"
#include "../../Managers.h"

void Level1::Load() {
	clock.Start();

	backgrounds.push_back(BackgroundEntity(0.f, 1.f, Managers::GetInstance()->ResourceManager.GetTexture("water"), 20.f));
}
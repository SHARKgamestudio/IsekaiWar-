#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/Characters/PlayerEntity.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullet.h"
#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Entities/Bullets/PlayerBullets/UltimeBullet.h"

#pragma endregion

ShootModule::ShootModule() {
	currentBullet = 0;
}

void ShootModule::ShootAuto() {
	switch (currentBullet) {

	case StateAuto::Neutral:
		(new AutoBullet(player->getPosition()))->Spawn();

	case StateAuto::Fire:
		(new AutoBullet(player->getPosition()))->Spawn();

	case StateAuto::Water:
		(new AutoBullet(player->getPosition()))->Spawn();

	case StateAuto::FireAndWater:
		(new AutoBullet(player->getPosition()))->Spawn();
	}
}

void ShootModule::ShootSpecial() {
	(new SpecialBullet(player->getPosition()))->Spawn();
}

void ShootModule::ShootUltime() {
	(new UltimeBullet(player->getPosition()))->Spawn();
}
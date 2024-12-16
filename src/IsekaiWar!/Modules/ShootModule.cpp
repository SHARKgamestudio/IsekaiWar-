#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/Characters/PlayerEntity.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/FireAuto.h"
#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Entities/Bullets/PlayerBullets/UltimeBullet.h"

#pragma endregion

ShootModule::ShootModule(PlayerEntity* player) {
	currentBullet = 0;
	this->ultimeBullet = nullptr;
	this->player = player;

	this->canAuto = true;
	this->canSpecial = true;
	this->canUltime = true;
}

void ShootModule::ShootAuto() {
	switch (currentBullet) {

	case StateAuto::Neutral:
		(new FireAuto(player->getPosition()))->Spawn();

	case StateAuto::Fire:
		(new FireAuto(player->getPosition()))->Spawn();

	case StateAuto::Water:
		(new FireAuto(player->getPosition()))->Spawn();

	case StateAuto::FireAndWater:
		(new FireAuto(player->getPosition()))->Spawn();
	}
}

void ShootModule::ShootSpecial() {
	(new SpecialBullet(player->getPosition()))->Spawn();
}

void ShootModule::StartUltime() {
	(ultimeBullet = new UltimeBullet(player->getPosition()))->Spawn();
}

void ShootModule::StopUltime() {
	ultimeBullet->Die();
	ultimeBullet = nullptr;
}
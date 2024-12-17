#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/Characters/PlayerEntity.h"

#include "../Entities/Bullets/PlayerBullets/AutoBullets/NeutralAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/FireAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/WaterAuto.h"

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Entities/Bullets/PlayerBullets/UltimeBullet.h"

#pragma endregion

// behaviour
#define RELOAD_AUTO 0.3f
#define RELOAD_SPECIAL 1.f
#define RELOAD_ULTIME 1.f

ShootModule::ShootModule(PlayerEntity* player)
	: clockAuto(IntervalClock(RELOAD_AUTO)),
	clockSpecial(IntervalClock(RELOAD_SPECIAL)),
	clockUltime(IntervalClock(RELOAD_ULTIME))
{
	this->isFire = false;
	this->isWater = false;

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
		(new NeutralAuto(player->getPosition()))->Spawn();
		return;
	case StateAuto::Fire:
		(new FireAuto(player->getPosition()))->Spawn();
		return;
	case StateAuto::Water:
		(new WaterAuto(player->getPosition()))->Spawn();
		return;
	case StateAuto::FireAndWater:
		(new FireAuto(player->getPosition()))->Spawn();
		return;
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

void ShootModule::Update(float deltaTime) {
	canAuto = clockAuto.Update(deltaTime) ? true : canAuto;
	canSpecial = clockSpecial.Update(deltaTime) ? true : canSpecial;
	canUltime = clockUltime.Update(deltaTime) ? true : canUltime;
}

void ShootModule::UpdateBullets() {
	if (isFire and isWater) {
		currentBullet = StateAuto::FireAndWater;
		clockAuto.maxTime = 0.2f;
	} 
	else if (isFire) {
		currentBullet = StateAuto::Fire;
	}
	else if (isWater) {
		currentBullet = StateAuto::Water;
	}
	else {
		currentBullet = StateAuto::Neutral;
	}
}
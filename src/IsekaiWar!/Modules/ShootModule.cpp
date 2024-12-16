#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/Characters/PlayerEntity.h"

#include "../Entities/Bullets/PlayerBullets/AutoBullets/NeutralAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/FireAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/WaterAuto.h"

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Entities/Bullets/PlayerBullets/UltimeBullet.h"

#pragma endregion

#include <iostream>

ShootModule::ShootModule(PlayerEntity* player)
	: clockAuto(IntervalClock(0.2f)),
	clockSpecial(IntervalClock(1.f)),
	clockUltime(IntervalClock(1.f)) 
{
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
	std::cout << "test" << std::endl;
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
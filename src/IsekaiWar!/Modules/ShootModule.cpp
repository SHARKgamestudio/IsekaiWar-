#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/BulletEntity.h"
#include "../Entities/Bullets/PlayerBullet.h"

#include "../Managers.h"

#pragma endregion

ShootModule::ShootModule(sf::Vector2f directionShoot) {
	this->directionShoot = directionShoot;
}

void ShootModule::Shoot(BulletEntity* bullet) {
	if (dynamic_cast<PlayerBullet*>(bullet)) {
		Managers::GetInstance()->SceneManager->currentLevel->SpawnPlayerBullet(bullet);
		return;
	}
	/*
	if (dynamic_cast<EnnemyBullet*>(bullet)) {
		Managers::GetInstance()->SceneManager->currentLevel->SpawnPlayerBullet(bullet);
		return;
	}
	*/
}
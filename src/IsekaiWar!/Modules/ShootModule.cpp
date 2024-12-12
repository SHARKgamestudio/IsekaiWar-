#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/BulletEntity.h"
#include "../Managers.h"

#pragma endregion

ShootModule::ShootModule(BulletEntity* bullet, sf::Vector2f directionShoot) {
	this->bullet = bullet;
	this->directionShoot = directionShoot;
}

void ShootModule::Shoot() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnBullet(bullet);
}
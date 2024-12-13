#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/BulletEntity.h"
#include "../Managers.h"

#pragma endregion

ShootModule::ShootModule(sf::Vector2f directionShoot) {
	this->directionShoot = directionShoot;
}

void ShootModule::Shoot(BulletEntity* bullet) {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnBullet(bullet);
}
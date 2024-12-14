#include "PlayerBullet.h"

#pragma region Local Dependencies

#include "../LivingEntity.h"
#include "../../Managers.h"

#pragma endregion

PlayerBullet::PlayerBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack)
	: BulletEntity(x, y, texture, columns, rows, radius, attack) {
}

PlayerBullet::PlayerBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack)
	: BulletEntity(position, texture, split, radius, attack) {
}

void PlayerBullet::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnPlayerBullet(this);
}


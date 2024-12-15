#include "EnemyBullet.h"

#pragma region Local Dependencies

#include "../../Managers.h"

#pragma endregion

EnemyBullet::EnemyBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack)
	: BulletEntity(x, y, texture, columns, rows, radius, attack) {
}

EnemyBullet::EnemyBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack)
	: BulletEntity(position, texture, split, radius, attack) {
}

void EnemyBullet::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnEnnemyBullet(this);
}
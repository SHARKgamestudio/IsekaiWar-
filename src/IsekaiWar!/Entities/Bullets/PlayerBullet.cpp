#include "PlayerBullet.h"

#pragma region Local Dependencies

#include "../../Managers.h"

#pragma endregion

#define DIRECTION_X  0.f
#define DIRECTION_Y -1.f

PlayerBullet::PlayerBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, float speed)
	: BulletEntity(x, y, texture, columns, rows, radius, attack, sf::Vector2f(DIRECTION_X, DIRECTION_Y), speed) {
}

PlayerBullet::PlayerBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, float speed)
	: BulletEntity(position, texture, split, radius, attack, sf::Vector2f(DIRECTION_X, DIRECTION_Y), speed) {
}

void PlayerBullet::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnPlayerBullet(this);
}
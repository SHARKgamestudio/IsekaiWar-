#pragma once

#pragma region Local Dependencies

#include "../BulletEntity.h"
#include "../../Modules/MoveModule.h"

#pragma endregion

class PlayerBullet : public BulletEntity {
public:
	PlayerBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, float speed);
	PlayerBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, float speed);

	void Spawn();
};
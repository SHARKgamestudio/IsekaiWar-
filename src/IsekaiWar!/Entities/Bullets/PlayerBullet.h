#pragma once

#pragma region Extrenal Dependencies

#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../BulletEntity.h"
#include "../../Modules/MoveModule.h"

#pragma endregion

class PlayerBullet : public BulletEntity {
public:
	PlayerBullet(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float attack = 1);
	PlayerBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float attack = 1);
};
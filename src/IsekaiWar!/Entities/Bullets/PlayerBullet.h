#pragma once

#pragma region Local Dependencies

#include "../BulletEntity.h"
#include "../../Modules/MoveModule.h"

#pragma endregion

class PlayerBullet : public BulletEntity {
public:

	PlayerBullet(float x, float y, sf::Texture* texture, float radius, float attack);
	PlayerBullet(sf::Vector2f pos, sf::Texture* texture, float radius, float attack);

	void virtual Update(float dt, std::vector<Entity*> entities);
};
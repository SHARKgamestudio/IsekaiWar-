#pragma once

#pragma region Extrenal Dependencies

#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../BulletEntity.h"
#include "../../Modules/MoveModule.h"

#pragma endregion

class PlayerBullet : public BulletEntity {
protected:

	std::vector<LivingEntity*> entitiesHit;

public:
	PlayerBullet(float x, float y, float w, float h, sf::Texture* texture, float radius, float attack);
	PlayerBullet(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float attack);

	void virtual Update(float deltaTime);
};
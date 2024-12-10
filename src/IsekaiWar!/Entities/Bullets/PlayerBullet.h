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
	PlayerBullet(float x, float y, sf::Texture* texture, float radius, float attack);
	PlayerBullet(sf::Vector2f position, sf::Texture* texture, float radius, float attack);

	void virtual Update(float deltaTime, std::vector<Entity*> entities);
};
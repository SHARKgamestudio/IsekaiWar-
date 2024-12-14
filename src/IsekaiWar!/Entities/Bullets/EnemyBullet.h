#pragma once

#pragma region Local Dependencies

#include "../BulletEntity.h"

#pragma endregion

class EnemyBullet : public BulletEntity {
protected:
	std::vector<LivingEntity*> entitiesHit;

public:
	EnemyBullet(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float attack = 1);
	EnemyBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float attack = 1);

	void virtual Update(float deltaTime);
};
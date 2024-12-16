#pragma once

#pragma region Local Dependencies

#include "../EnemyBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class StandardBullet : public EnemyBullet {
public:
	StandardBullet(float x, float y);
	StandardBullet(sf::Vector2f position);

	void Update(float deltaTime);
};
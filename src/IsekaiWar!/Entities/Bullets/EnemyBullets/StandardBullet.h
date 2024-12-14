#pragma once

#pragma region Local Dependencies

#include "../EnemyBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class StandardBullet : public EnemyBullet, public MoveModule {
public:
	StandardBullet(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1);
	StandardBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1));

	void Move(float deltaTime);
	void virtual Update(float deltaTime, std::vector<CollidableEntity*> entities);
};
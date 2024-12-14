#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class AutoBullet : public PlayerBullet, public MoveModule {
	public:
	AutoBullet(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1);
	AutoBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1));

	void Move(float deltaTime);
	void virtual Update(float deltaTime, std::vector<CollidableEntity*> entities);
};
#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class AutoBullet : public PlayerBullet, public MoveModule {
	public:
	AutoBullet(float x, float y, float w, float h, sf::Texture* texture);
	AutoBullet(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture);

	void Move(float deltaTime);
	void virtual Update(float deltaTime, std::vector<CollidableEntity*> entities);
};
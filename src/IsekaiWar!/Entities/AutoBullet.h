#pragma once

#pragma region Local Dependencies

#include "PlayerBullet.h"
#include "../../Modules/MoveModule.h"

#pragma endregion

class AutoBullet : public PlayerBullet, public MoveModule {
	public:

	AutoBullet(float x, float y, sf::Texture* texture);
	AutoBullet(sf::Vector2f pos, sf::Texture* texture);

	void Move(float dt);
	void Update(float dt, std::vector<Entity*> entities) override;
};

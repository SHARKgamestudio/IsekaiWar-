#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class SpecialBullet : public PlayerBullet, public MoveModule {
	public:
		SpecialBullet(float x, float y, int columns = 1, int rows = 1);
		SpecialBullet(sf::Vector2f position, sf::Vector2i split = sf::Vector2i(1, 1));

		void Move(float deltaTime);
		void Update(float deltaTime) override;
};
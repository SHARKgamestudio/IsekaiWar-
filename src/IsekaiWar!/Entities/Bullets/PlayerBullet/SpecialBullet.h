#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class SpecialBullet : public PlayerBullet, public MoveModule {
	public:
		SpecialBullet(float x, float y);
		SpecialBullet(sf::Vector2f position);

		void Move(float deltaTime);
		void Update(float deltaTime) override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
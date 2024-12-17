#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class WaterPowerUp : public PowerUpEntity {
	private:
		Animator animator;
	public:
		WaterPowerUp(float x, float y);
		WaterPowerUp(sf::Vector2f position);

		void Action();
};
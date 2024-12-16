#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class FirePowerUp : public PowerUpEntity {
	private:
		Animator animator;
	public:
		FirePowerUp(float x, float y);
		FirePowerUp(sf::Vector2f position);

		void Action();
};
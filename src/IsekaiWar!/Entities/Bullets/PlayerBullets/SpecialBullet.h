#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class SpecialBullet : public PlayerBullet, public MoveModule {
	private:
		Animator animator;
	public:
		SpecialBullet(float x, float y, int columns = 6, int rows = 1);
		SpecialBullet(sf::Vector2f position, sf::Vector2i split = sf::Vector2i(6, 1));

		void Move(float deltaTime);
		void Update(float deltaTime) override;
};
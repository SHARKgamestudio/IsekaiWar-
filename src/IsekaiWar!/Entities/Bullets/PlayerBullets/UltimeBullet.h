#pragma once

#pragma region Local Dependencies

#include "../../CollidableEntity.h"
#include "../../../Modules/AttackModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class UltimeBullet : public Entity, public AttackModule {
	private:
		Animator animatorBody;
		Animator animatorHead;
	public:
		UltimeBullet(float x, float y, int columns = 6, int rows = 1);
		UltimeBullet(sf::Vector2f position, sf::Vector2i split = sf::Vector2i(6, 1));

		void Move(float deltaTime);
		void Update(float deltaTime) override;
};
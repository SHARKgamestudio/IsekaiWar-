#pragma once

#pragma region Local Dependencies

#include "../AutoBullet.h"
#include "../../../../Rendering/Animator.h"

#pragma endregion

class NeutralAuto : public AutoBullet {
	public:
		NeutralAuto(float x, float y);
		NeutralAuto(sf::Vector2f position);
};
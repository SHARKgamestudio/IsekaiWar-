#pragma once

#pragma region Local Dependencies

#include "../AutoBullet.h"
#include "../../../../Rendering/Animator.h"

#pragma endregion

class WaterAuto : public AutoBullet {
	public:
		WaterAuto(float x, float y);
		WaterAuto(sf::Vector2f position);
};
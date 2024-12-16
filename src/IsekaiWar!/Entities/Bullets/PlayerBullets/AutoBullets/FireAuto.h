#pragma once

#pragma region Local Dependencies

#include "../AutoBullet.h"
#include "../../../../Rendering/Animator.h"

#pragma endregion

class FireAuto : public AutoBullet {
	public:
		FireAuto(float x, float y);
		FireAuto(sf::Vector2f position);
};
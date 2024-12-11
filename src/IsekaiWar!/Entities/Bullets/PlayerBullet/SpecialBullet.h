#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class SpecialBullet : public PlayerBullet, public MoveModule {
	public:

	SpecialBullet(float x, float y, float w, float h);
	SpecialBullet(sf::Vector2f position, sf::Vector2f scale);

	void Move(float deltaTime);
	void Update(float deltaTime) override;
};
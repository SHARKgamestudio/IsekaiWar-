#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class SpecialBullet : public PlayerBullet, public MoveModule {
	public:

	SpecialBullet(float x, float y, sf::Texture* texture);
	SpecialBullet(sf::Vector2f position, sf::Texture* texture);

	void Move(float deltaTime);
	void Update(float deltaTime, std::vector<Entity*> entities) override;
};
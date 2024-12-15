#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class UltimeBullet : public PlayerBullet, public MoveModule {
private:
	Animator animatorHead;
public:
	UltimeBullet(float x, float y, int columns = 6, int rows = 1);
	UltimeBullet(sf::Vector2f position, sf::Vector2i split = sf::Vector2i(6, 1));

	void Move(float deltaTime);
	void Update(float deltaTime) override;
	void UpdateLines();
	void CheckCollisions();
};
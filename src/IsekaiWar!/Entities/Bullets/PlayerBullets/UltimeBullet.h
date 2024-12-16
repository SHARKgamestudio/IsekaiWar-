#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class UltimeBullet : public PlayerBullet {
protected:
	Animator animator;

public:
	UltimeBullet(float x, float y);
	UltimeBullet(sf::Vector2f position);

	void Move(float deltaTime);
	void Update(float deltaTime) override;
	void UpdateLines();
	void CheckCollisions();
};
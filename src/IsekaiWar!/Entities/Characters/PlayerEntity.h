#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"
#include "../../Rendering/Animator.h"
#include "../../Modules/ShootModule.h"

#pragma endregion

class InputManager;
class UltimeBullet;

class PlayerEntity : public CharacterEntity, public ShootModule {
private:

	Animator* animator;
	float angle;
	InputManager* inputs;
public:
	PlayerEntity();

	void UpdateLogic(float deltaTime);
};
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
	PlayerEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	PlayerEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);

	void Update(float deltaTime);
};
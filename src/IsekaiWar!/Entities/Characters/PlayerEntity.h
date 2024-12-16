#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"
#include "../../Rendering/Animator.h"
#include "../../Modules/ShootModule.h"
#include "../../Utils/IntervalClock.h"

#pragma endregion

class InputManager;
class UltimeBullet;

class PlayerEntity : public CharacterEntity, public ShootModule {
private:
	IntervalClock clockAuto;
	IntervalClock clockSpecial;
	IntervalClock clockUltime;
	bool canAuto;
	bool canSpecial;
	bool canUltime;

	UltimeBullet* ultimeBullet;

	Animator* animator;
	float angle;
	InputManager* inputs;
public:
	PlayerEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	PlayerEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);

	void Update(float deltaTime);
};
#pragma once

#pragma region Local Dependencies
	#include "LivingEntity.h"
	#include "../Modules/MoveModule.h"
#pragma endregion

class CharacterEntity : public LivingEntity, public MoveModule {
public:
	CharacterEntity(float x, float y, float w, float h, sf::Texture* texture, float radius, float health);
	CharacterEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float health);
	virtual void Update(float deltaTime) = 0;
	
	void Move(float deltaTime);
};
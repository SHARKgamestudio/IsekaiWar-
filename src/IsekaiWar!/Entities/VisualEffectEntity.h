#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/MoveModule.h"

#pragma endregion

class VisualEffectEntity : public Entity, public MoveModule {
public:
	VisualEffectEntity(float x, float y, float w, float h, sf::Texture* texture, float speed);
	VisualEffectEntity(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float speed);

	void virtual Update(float deltaTime);
	void virtual Move(float deltaTime);
};
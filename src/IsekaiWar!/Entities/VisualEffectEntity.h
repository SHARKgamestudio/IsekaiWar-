#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/Movable.h"

#pragma endregion

class VisualEffectEntity : public Entity, public Movable {
public:
	VisualEffectEntity(float x, float y, sf::Texture* texture, float speed);
	VisualEffectEntity(sf::Vector2f pos, sf::Texture* texture, float speed);

	void virtual Update(float dt);
	void virtual Move(float dt);
};
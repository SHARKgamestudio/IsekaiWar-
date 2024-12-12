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
	VisualEffectEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float speed = 1);
	VisualEffectEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float speed = 1);

	void virtual Update(float deltaTime);
	void virtual Move(float deltaTime);
};
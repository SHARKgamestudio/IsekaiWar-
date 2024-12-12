#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"

#pragma endregion

class InputManager;

class Player : public CharacterEntity {
private:
	float angle;
	InputManager* inputs;
public:
	Player(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	Player(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);

	void Update(float deltaTime);
	//void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
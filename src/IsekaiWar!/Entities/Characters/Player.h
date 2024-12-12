#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"

#pragma endregion

class Player : public CharacterEntity {
private:
public:
	Player(float x, float y, float w, float h, sf::Texture* texture, float radius, float health);
	Player(sf::Vector2f position, sf::Vector2f scale, sf::Texture* texture, float radius, float health);

	void Update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
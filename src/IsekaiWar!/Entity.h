#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class Entity : public sf::Transformable, public sf::Drawable {
protected:
	sf::Texture* texture;
	sf::Sprite sprite;
	bool toDisable;
	bool toDestroy;

public:
	Entity(float x, float y, sf::Texture* texture);
	Entity(sf::Vector2f position, sf::Texture* texture);
	
	void virtual Update(float deltaTime);
	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Transformable, public sf::Drawable
{
protected:

	sf::Texture* texture;
	sf::Sprite sprite;

public:

	Entity(float x, float y, sf::Texture* texture);
	Entity(sf::Vector2f pos, sf::Texture* texture);
	
	void virtual Update(float dt) = 0;
};


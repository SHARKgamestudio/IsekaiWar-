#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class Spritesheet : public sf::Drawable, public sf::Transformable {
private:
	int columns, rows;
	int hres, vres;

	sf::Sprite sprite;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

	int current;
	Spritesheet();
	Spritesheet(sf::Texture* texture, int columns, int rows);

	void SetTexture(sf::Texture* texture, int columns, int rows);
	void SetTextureRect(sf::IntRect rect);

	void UpdateViewport();
};
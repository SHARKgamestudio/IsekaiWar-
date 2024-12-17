#pragma once

#include "../UIComponent.h"

class Spritesheet;

class Button : public UIComponent {
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	int state;
	sf::Text* text;
	Spritesheet* spritesheet;
public:
	Button(sf::Text* text, Spritesheet* spritesheet, Anchor anchor = Center);
	void Update(const sf::RenderWindow& window);

	bool IsPressed();
};
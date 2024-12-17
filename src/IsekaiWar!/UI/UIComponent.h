#pragma once

#include <SFML/Graphics.hpp>

enum Anchor {
	TopLeft,
	TopCenter,
	TopRight,
	CenterLeft,
	Center,
	CenterRight,
	BottomLeft,
	BottomCenter,
	BottomRight
};

class UIComponent : public sf::Drawable, public sf::Transformable {
public:
	Anchor anchor = Center;
	virtual void Update(const sf::RenderWindow& window) = 0;
};
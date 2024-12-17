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
	virtual void UpdateCursor(const sf::RenderWindow& window) = 0;
	virtual void Update(float deltaTime) = 0;
};
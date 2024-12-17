#pragma once

#pragma region Local Dependencies

#include "../UIComponent.h"

#pragma endregion

class Spritesheet;
class Text;

class Button : public UIComponent {
private:
	enum State {
		Normal,
		Hovered,
		Pressed,
		Disabled
	};

	sf::Text* text;
	Spritesheet* spritesheet;

	float animatedValue;
	sf::Vector2f baseScale;

	State state;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	void Enable();
	void Disable();

	void UpdateCursor(const sf::RenderWindow& window);
	void UpdateLogic(float deltaTime);

	void SetScale(float x, float y);

	Button(sf::Text* text, Spritesheet* spritesheet, Anchor anchor = Center);
	bool IsPressed();
};
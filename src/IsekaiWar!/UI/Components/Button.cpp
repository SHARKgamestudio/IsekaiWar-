#include "Button.h"

#pragma region Local Dependencies

#include "../../Rendering/Spritesheet.h"

#pragma endregion

Button::Button(sf::Text* text, Spritesheet* spritesheet, Anchor anchor) {
	this->text = text;
	this->enabled = true;
	this->state = State::Normal;
	this->anchor = anchor;
	this->animatedValue = 0;
	this->spritesheet = spritesheet;

	// TEMP //
	text->setCharacterSize(64);
	text->setOrigin(text->getLocalBounds().width / 2.0f, text->getLocalBounds().height / 1.5f);
}

void Button::UpdateCursor(const sf::RenderWindow& window) {
	if (!enabled) return;

	sf::FloatRect bounds = getTransform().transformRect(spritesheet->sprite.getGlobalBounds());

	bool inBounds = bounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	state = inBounds ? (isPressed ? State::Pressed : State::Hovered) : State::Normal;

	spritesheet->current = state;
	spritesheet->UpdateViewport();
}

void Button::UpdateLogic(float deltaTime) {
	if (!enabled) return;

	if (state == 1 && animatedValue < 1) { animatedValue += deltaTime * 4; }
	else if (animatedValue > 0.0f) { animatedValue -= deltaTime * 4; }

	float scale = std::pow(animatedValue, 2) / 64;
	setScale(baseScale.x + scale, baseScale.y + scale);
}

void Button::SetScale(float x, float y) {
	baseScale = sf::Vector2f(x, y);
	setScale(x, y);
}

void Button::Enable() {
	enabled = true;
	state = State::Normal;
}

void Button::Disable() {
	enabled = false;
	state = State::Normal;
}

bool Button::IsPressed() {
	return state == State::Pressed;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (!enabled) return;

	states.transform.combine(getTransform());
	target.draw(*spritesheet, states);
	target.draw(*text, states);
}
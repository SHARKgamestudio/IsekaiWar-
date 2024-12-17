#include "Button.h"

#include "../../Rendering/Spritesheet.h"

Button::Button(sf::Text* text, Spritesheet* spritesheet, Anchor anchor) {
	this->state = 0;
	this->text = text;
	this->anchor = anchor;
	this->spritesheet = spritesheet;

	// TEMP //
	text->setCharacterSize(64);
	text->setOrigin(text->getLocalBounds().width / 2.0f, text->getLocalBounds().height / 1.5f);
}

void Button::Update(const sf::RenderWindow& window) {
	sf::FloatRect bounds = getTransform().transformRect(spritesheet->sprite.getGlobalBounds());

	bool inBounds = bounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	state = inBounds ? (isPressed ? 2 : 1) : 0;

	spritesheet->current = state;
	spritesheet->UpdateViewport();
}

bool Button::IsPressed() {
	return state == 2;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(*spritesheet, states);
	target.draw(*text, states);
}
#include "InputManager.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../Utils/Maths.h"

#pragma endregion

Key::Key() {
	this->value = 0;
	this->type = Keycode;
}

Key::Key(int value, Type type) {
	this->value = value;
	this->type = type;
}

Action::Action(Key keyboard, Key joystick) {
	this->keyboard = keyboard;
	this->joystick = joystick;
}

float InputManager::GetJoystickValue(int axis) {
	return sf::Joystick::getAxisPosition(0, sf::Joystick::Axis(axis)) / 100;
}

void InputManager::Update(const sf::Event* event) {
	if (event->type == sf::Event::JoystickConnected || sf::Joystick::isConnected(0))
		joystickConnected = true;

	bool isJoystickAxis = event->type == sf::Event::JoystickMoved;
	bool isJoystickButton = event->type == sf::Event::JoystickButtonPressed;

	bool isKeyPressed = event->type == sf::Event::KeyPressed;
	bool isKeyReleased = event->type == sf::Event::KeyReleased;

	if (joystickConnected) {
		if (move_left.joystick.type == Axis || move_right.joystick.type == Axis) {
			horizontal = isJoystickAxis ? GetJoystickValue(move_left.joystick.value) : 0;
		}
		else {
			int button = event->joystickButton.button;

			int left = move_left.joystick.value;
			int right = move_right.joystick.value;

			horizontal = isJoystickButton ?
				(button == left ? -1 : (button == right ? 1 : 0))
			: 0;
		}

		if (move_down.joystick.type == Axis || move_up.joystick.type == Axis) {
			horizontal = isJoystickAxis ? GetJoystickValue(move_left.joystick.value) : 0;
		}
		else {
			int button = event->joystickButton.button;

			int left = move_left.joystick.value;
			int right = move_right.joystick.value;

			horizontal = isJoystickButton ?
				(button == left ? -1 : (button == right ? 1 : 0))
				: 0;
		}
	}
	else {
		int keycode = event->key.code;

		int left = move_left.keyboard.value;
		int right = move_right.keyboard.value;

		horizontal = isKeyPressed ?
			(keycode == left ? -1 : (keycode == right ? 1 : 0))
		: (isKeyReleased ? 0 : horizontal);
	}

	if (event->type == sf::Event::JoystickDisconnected)
		joystickConnected = false;
}

float InputManager::GetAxis(std::string name) {
	return name == "Horizontal" ? Maths::Round(horizontal, 4) : (name == "Vertical" ? vertical : 0);
}
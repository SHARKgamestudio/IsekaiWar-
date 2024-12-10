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

	#pragma region Update Axes

	for (int i = 0; i < axes.size(); i+=2) {
		if (joystickConnected) {
			if (axes[i].joystick.type == Axis || axes[i + 1].joystick.type == Axis) {
				values[i / 2] = isJoystickAxis ? GetJoystickValue(axes[i].joystick.value) : 0.0f;
			}
			else {
				int button = event->joystickButton.button;

				int negative = axes[i].joystick.value;
				int positive = axes[i + 1].joystick.value;

				values[i / 2] = isJoystickButton ?
					(button == negative ? -1.0f : (button == positive ? 1.0f : 0.0f))
					: 0.0f;
			}
		}
		else {
			int keycode = event->key.code;

			int left = axes[i].keyboard.value;
			int right = axes[i + 1].keyboard.value;

			values[i / 2] = isKeyPressed ?
				(keycode == left ? -1 : (keycode == right ? 1.0f : 0.0f))
				: (isKeyReleased ? 0.0f : values[i / 2]);
		}
	}

	#pragma endregion

	#pragma region Update Keys

	for (int i = 0; i < keys.size(); i++) {
		if (joystickConnected) {

		}
	}

	#pragma endregion

	if (event->type == sf::Event::JoystickDisconnected)
		joystickConnected = false;
}

float InputManager::GetAxis(std::string name) {
	return name == "Horizontal" ? Maths::Round(values[0], 4) : (name == "Vertical" ? Maths::Round(values[1], 4) : 0);
}

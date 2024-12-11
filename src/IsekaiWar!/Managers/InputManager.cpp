#include "InputManager.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../Utils/Maths.h"

#pragma endregion

#define ACCURACY 4

Axis::Axis(std::string name, sf::Keyboard::Key negative, sf::Keyboard::Key positive, sf::Joystick::Axis joystick) {
	this->name = name;
	this->negative = negative;
	this->positive = positive;
	this->joystick = joystick;
}

Key::Key(std::string name, sf::Keyboard::Key key, unsigned int button) {
	this->name = name;
	this->key = key;
	this->button = button;
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

	for (int i = 0; i < axes.size(); i++) {
		if (joystickConnected) {
				axes[i].value = isJoystickAxis ? GetJoystickValue(axes[i].joystick) : 0.0f;
		}
		else {
			int keycode = event->key.code;

			axes[i].value = isKeyPressed ?
				(keycode == axes[i].negative ? -1 : (keycode == axes[i].positive ? 1.0f : 0.0f))
				: (isKeyReleased ? 0.0f : axes[i].value);
		}
	}

	#pragma endregion

	#pragma region Update Keys

	for (int i = 0; i < keys.size(); i++) {
		if (joystickConnected) {
			if (sf::Joystick::isButtonPressed(0, keys[i].button)) {
				if (!keys[i].hold) {
					keys[i].state = Pressed;
					keys[i].hold = true;
				}
				else {
					keys[i].state = Hold;
				}
			} else if (keys[i].hold) {
				keys[i].state = Released;
				keys[i].hold = false;
			}
			else {
				keys[i].state = None;
			}
		}
		else {
			keys[i].state = sf::Keyboard::isKeyPressed(keys[i].key) ? Pressed : None;
		}
	}

	#pragma endregion

	if (event->type == sf::Event::JoystickDisconnected)
		joystickConnected = false;
}

float InputManager::GetAxis(std::string name) {
	for (int i = 0; i < axes.size(); i++) {
		if (axes[i].name == name) {
			return Maths::Round(axes[i].value, ACCURACY);
			break;
		}
	}
}

bool InputManager::GetKeyDown(std::string name) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			return keys[i].state == Pressed;
			break;
		}
	}
}

bool InputManager::GetKey(std::string name) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			return keys[i].state == Pressed || keys[i].state == Hold;
			break;
		}
	}
}

bool InputManager::GetKeyUp(std::string name) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			return keys[i].state == Released;
			break;
		}
	}
}
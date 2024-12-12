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
	this->hold = false;
	this->state = None;
}

float InputManager::GetRawAxis(std::string name) {
	for (int i = 0; i < axes.size(); i++) {
		if (axes[i].name == name) {
			return axes[i].value;
		}
	}
	return 0;
}

State InputManager::GetRawKey(std::string name) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			return keys[i].state;
		}
	}
	return None;
}

float InputManager::GetJoystickValue(sf::Joystick::Axis axis) {
	return sf::Joystick::getAxisPosition(0, axis) / 100;
}

bool InputManager::GetKeyValue(sf::Keyboard::Key key) {
	return sf::Keyboard::isKeyPressed(key);
}

void InputManager::UpdateInputs() {

	#pragma region Update Axes

	for (int i = 0; i < axes.size(); i++) {
		if (joystickConnected) {
				axes[i].value = GetJoystickValue(axes[i].joystick);
		}
		else {
			axes[i].value = GetKeyValue(axes[i].negative) ? -1.0f
			: (GetKeyValue(axes[i].positive) ? 1.0f : 0.0f);
		}
	}

	#pragma endregion

	#pragma region Update Keys

	for (int i = 0; i < keys.size(); i++) {
		if (joystickConnected) {
			if (sf::Joystick::isButtonPressed(0, keys[i].button)) {
				keys[i].state = keys[i].hold ? Hold : Pressed;
				keys[i].hold = true;
			} else {
				keys[i].state = keys[i].hold ? Released : None;
				keys[i].hold = false;
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(keys[i].key)) {
				keys[i].state = keys[i].hold ? Hold : Pressed;
				keys[i].hold = true;
			}
			else {
				keys[i].state = keys[i].hold ? Released : None;
				keys[i].hold = false;
			}
		}
	}

	#pragma endregion

}

void InputManager::UpdateEvents(sf::Event* event) {
	if (event->type == sf::Event::JoystickConnected || sf::Joystick::isConnected(0))
		joystickConnected = true;
	if (event->type == sf::Event::JoystickDisconnected)
		joystickConnected = false;
}

float InputManager::GetAxis(std::string name) {
	return Maths::Round(GetRawAxis(name), ACCURACY);
}

bool InputManager::GetKeyDown(std::string name) {
	return GetRawKey(name) == Pressed;
}

bool InputManager::GetKey(std::string name) {
	return GetRawKey(name) == Hold;
}

bool InputManager::GetKeyUp(std::string name) {
	return GetRawKey(name) == Released;
}
#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#pragma endregion

enum Type {
	Keycode,
	Axis
};

struct Key {
	int value;
	Type type;

	Key();
	Key(int value, Type type);
};

struct Action {
	Key keyboard;
	Key joystick;

	Action(Key keyboard, Key joystick);
};

static class JoystickButton {
public:
	enum {
		A = 0,
		B = 1,
		X = 2,
		Y = 3,
		LB = 4,
		RB = 5,
		Back = 6,
		Start = 7,
		LS = 8,
		RS = 9
	};
};

class InputManager {
private:
	Action move_left = { Key(sf::Keyboard::Q, Keycode), Key(sf::Joystick::Axis::X, Axis) };
	Action move_right = { Key(sf::Keyboard::D, Keycode), Key(sf::Joystick::Axis::X, Axis) };
	float horizontal = 0.0f;

	Action move_up = { Key(sf::Keyboard::Z, Keycode), Key(sf::Joystick::Axis::Y, Axis) };
	Action move_down = { Key(sf::Keyboard::S, Keycode), Key(sf::Joystick::Axis::Y, Axis) };
	float vertical = 0.0f;

	Action shoot_auto = { Key(sf::Keyboard::Space, Keycode), Key(JoystickButton::X, Keycode) };

	bool joystickConnected = false;

	float GetJoystickValue(int axis);
public:
	void Update(const sf::Event* event);

	float GetAxis(std::string name);

	bool GetKeyDown();
	bool GetKey();
	bool GetKeyUp();
};
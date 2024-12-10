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

class JoystickButton {
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
	std::vector<Action> axes {
		{ Key(sf::Keyboard::Q, Keycode), Key(sf::Joystick::Axis::X, Axis) },
		{ Key(sf::Keyboard::D, Keycode), Key(sf::Joystick::Axis::X, Axis) },
		{ Key(sf::Keyboard::Z, Keycode), Key(sf::Joystick::Axis::Y, Axis) },
		{ Key(sf::Keyboard::S, Keycode), Key(sf::Joystick::Axis::Y, Axis) }
	};
	std::vector<float> values{
		0,
		0
	};


	std::vector<Action> keys{
		{ Key(sf::Keyboard::Space, Keycode), Key(JoystickButton::X, Keycode) }
	};
	std::vector<bool> states {
		false,
		false
	};


	bool joystickConnected = false;

	float GetJoystickValue(int axis);
public:
	void Update(const sf::Event* event);

	float GetAxis(std::string name);

	bool GetKeyDown(std::string name);
	bool GetKey(std::string name);
	bool GetKeyUp(std::string name);
};
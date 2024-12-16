#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#pragma endregion

enum State {
	None,
	Pressed,
	Hold,
	Released
};

class Axis {
public:
	std::string name;

	sf::Keyboard::Key negative;
	sf::Keyboard::Key positive;

	sf::Joystick::Axis joystick;

	float value = 0;

	Axis(std::string name, sf::Keyboard::Key negative, sf::Keyboard::Key positive, sf::Joystick::Axis joystick);
};

class Key {
public:
	std::string name;

	sf::Keyboard::Key key;
	unsigned int button;

	bool hold;
	State state;

	Key(std::string name, sf::Keyboard::Key key, unsigned int button);
};

class InputManager {
private:
	std::vector<Axis> axes {
		Axis("Horizontal", sf::Keyboard::Q, sf::Keyboard::D, sf::Joystick::X),
		Axis("Vertical", sf::Keyboard::Z, sf::Keyboard::S, sf::Joystick::Y)
	};
	
	std::vector<Key> keys{
		Key("Auto", sf::Keyboard::K, 0),
		Key("Special", sf::Keyboard::L, 2),
		Key("Ult", sf::Keyboard::M, 2)
	};

	bool joystickConnected = false;


	float GetRawAxis(std::string name);
	State GetRawKey(std::string name);

	float GetJoystickValue(sf::Joystick::Axis axis);
	bool GetKeyValue(sf::Keyboard::Key key);
public:
	void UpdateInputs();
	void UpdateEvents(sf::Event* event);

	float GetAxis(std::string name);
	
	bool GetKeyDown(std::string name);
	bool GetKey(std::string name);
	bool GetKeyUp(std::string name);
};
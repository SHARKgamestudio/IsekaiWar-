#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <magic_enum.hpp>
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
	State current;

	Key(std::string name, sf::Keyboard::Key key, unsigned int button);
};

class InputManager {
private:
	sf::Event* event;
	bool joystickConnected = false;

	float GetRawAxis(std::string name);
	State GetRawKey(std::string name);

	float GetJoystickValue(sf::Joystick::Axis axis);
	bool GetKeyValue(sf::Keyboard::Key key);
public:
	std::vector<Axis> axes{
		Axis("Horizontal", sf::Keyboard::Q, sf::Keyboard::D, sf::Joystick::X),
		Axis("Vertical", sf::Keyboard::Z, sf::Keyboard::S, sf::Joystick::Y)
	};

	std::vector<Key> keys{
		Key("quit", sf::Keyboard::Escape, 8),
		Key("Confirm", sf::Keyboard::K, 0),
		Key("Confirm", sf::Keyboard::K, 0),
		Key("Cancel", sf::Keyboard::K, 1),

		Key("Auto", sf::Keyboard::K, 2),
		Key("Special", sf::Keyboard::L, 0),
		Key("Ult", sf::Keyboard::M, 5)
	};

	~InputManager();

	bool isJoystickConnected();

	void UpdateInputs();
	void UpdateEvents(sf::Event* event);

	float GetAxis(std::string name);
	
	bool GetKeyDown(std::string name);
	bool GetKey(std::string name);
	bool GetKeyUp(std::string name);

	void MapAxisNegativeKeyboard(std::string name);
	void MapAxisPositiveKeyboard(std::string name, sf::Keyboard::Key key);
	void MapAxisGamepadInput(std::string name, sf::Keyboard::Key key);

	std::string KeyToString(sf::Keyboard::Key key);
	std::string JoystickToString(sf::Joystick::Axis axis);
};
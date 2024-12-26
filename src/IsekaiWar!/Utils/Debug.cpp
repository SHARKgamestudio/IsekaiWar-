#include "Debug.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

void Debug::Assert(bool condition, std::string message, bool quit) {
	if (condition) return;

	std::cout << "Assertion failed ";
	std::cout << message << std::endl;

	if (quit) exit(1);
}
#pragma once

#include <string>

class Debug {
public:
	[[noreturn]] static void Assert(bool condition, std::string message, bool quit = true);
};
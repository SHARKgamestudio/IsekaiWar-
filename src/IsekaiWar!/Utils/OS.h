#pragma once

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

class OS {
public:
	static std::string GetExecutablePath();
	static std::vector<std::string> GetFilesInDirectory(std::string path, std::string extension = ".png");
};
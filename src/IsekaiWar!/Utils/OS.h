#pragma once

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

class OS {
public:
	/// <summary>
	/// Returns the path of the program executable.
	/// </summary>
	static std::string GetExecutablePath();

	/// <summary>
	/// Transforms a relative path into an absolute path.
	/// </summary>
	static std::string GetAbsolutePath(std::string path);

	/// <summary>
	/// Replace all backslashes with forward slashes.
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	static std::string GetStandardPath(std::string path);

	/// <summary>
	/// Returns a vector of file paths with a specific extension in a directory and its subdirectories.
	/// </summary>
	static std::vector<std::string> GetFilesInDirectory(std::string path, std::string extension = ".png");
};
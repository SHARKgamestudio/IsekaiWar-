#include "OS.h"

#pragma region External Dependencies

#include <filesystem>
#include <windows.h>
#include <iostream>
#include <codecvt>
#include <string>
#include <locale>
#include <vector>

#pragma endregion

namespace fs = std::filesystem;

std::string OS::GetExecutablePath() {
    wchar_t path[MAX_PATH];
    DWORD length = GetModuleFileName(NULL, path, MAX_PATH);

    if (length == 0) {
        return "";
    }

    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, path, -1, NULL, 0, NULL, NULL);
    if (bufferSize == 0) {
        return "";
    }

    std::string result(bufferSize - 1, '\0');
    WideCharToMultiByte(CP_UTF8, 0, path, -1, &result[0], bufferSize, NULL, NULL);

    result = GetStandardPath(result);

    size_t position = result.find_last_of("/");
    if (position != std::string::npos) {
        result = result.substr(0, position);
    }

    return result;
}

std::string OS::GetAbsolutePath(std::string path) {
   return fs::absolute(path).generic_string(); 
}

std::string OS::GetStandardPath(std::string path) {
    std::replace(path.begin(), path.end(), '\\', '/');
    return path;
}

std::vector<std::string> OS::GetFilesInDirectory(std::string path, std::string extension) {
    std::vector<std::string> files;
    fs::path directoryPath(path);

    for (const auto& entry : fs::recursive_directory_iterator(directoryPath, fs::directory_options::skip_permission_denied)) {
        if (fs::is_regular_file(entry) && entry.path().extension() == extension) {
            files.push_back(GetStandardPath(entry.path().string()));
        }
    }

    return files;
}
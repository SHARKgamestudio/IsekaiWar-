#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"
#include "../Utils/OS.h"
#include <iostream>

#pragma endregion

ResourceManager::ResourceManager() {

	std::string path = OS::GetExecutablePath() + "/resourcepacks/";

	std::vector<std::string> assets = OS::GetFilesInDirectory(path, ".png");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddTexture(name, asset);
    }
}

void ResourceManager::AddTexture(std::string name, std::string path) {
	bool success = textures[name].loadFromFile(path);
	Debug::Assert(success, "Could not add the texture to the resources");
}

sf::Texture* ResourceManager::GetTexture(std::string name) {
	bool success = textures.contains(name);
	Debug::Assert(success, "Could not retreive requested resource");
	return &textures[name];
}
#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"

#pragma endregion

ResourceManager::ResourceManager() {
	textures = std::map<std::string, sf::Texture>();
}

void ResourceManager::AddTexture(std::string name, std::string path) {
	bool success = textures[name].loadFromFile(path);
	Debug::Assert(success, "Could not add the texture to the resources");
}

sf::Texture* ResourceManager::GetTexture(std::string name) {
	Debug::Assert(textures.contains(name), "Error adding texture to resources.");
	return &textures[name];
}
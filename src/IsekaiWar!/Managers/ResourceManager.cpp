#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"

#pragma endregion

ResourceManager::ResourceManager() {
	sf::Texture texture;
	texture.loadFromFile(path + "water.jpg");
	textures["water"] = texture;
}

void ResourceManager::AddTexture(std::string name, std::string path) {
	bool success = textures[name].loadFromFile(path);
	Debug::Assert(success, "Could not add the texture to the resources");
}

sf::Texture* ResourceManager::GetTexture(std::string name) {
	bool success = textures.contains(name);
	Debug::Assert(success, "Error adding texture to resources.");
	return &textures[name];
}
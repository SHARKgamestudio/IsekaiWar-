#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"

#pragma endregion

ResourceManager::ResourceManager() {
	std::vector<std::string> nameAsset = {
		"water",
		"fireball"
	};
	std::vector<std::string> nameFile = {
		"water.jpg",
		"fireball.png"
	};
	sf::Texture texture;
	for (int i = 0; i < nameAsset.size(); i++)
	{
		texture.loadFromFile(path + nameFile[i]);
		textures[nameAsset[i]] = texture;
	}
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
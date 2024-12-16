#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"
#include "../Utils/OS.h"
#include <iostream>

#pragma endregion

ResourceManager::ResourceManager() {
	std::string path = OS::GetExecutablePath();

	LoadTextures(path);
	LoadSounds(path);
}

void ResourceManager::LoadTextures(std::string path) {
	std::vector<std::string> assets = OS::GetFilesInDirectory(path + "/resourcepacks/", ".png");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddTexture(name, asset);
	}
}
void ResourceManager::LoadSounds(std::string path) {
	std::vector<std::string> assets = OS::GetFilesInDirectory(path + "/resourcepacks/", ".wav");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddSound(name, asset);
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

void ResourceManager::AddSound(std::string name, std::string path) {
	bool success = sounds[name].loadFromFile(path);
	Debug::Assert(success, "Could not add the sound to the resources");
}
sf::SoundBuffer* ResourceManager::GetSound(std::string name) {
	bool success = sounds.contains(name);
	Debug::Assert(success, "Could not retreive requested resource");
	return &sounds[name];
}
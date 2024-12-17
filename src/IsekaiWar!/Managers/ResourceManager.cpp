#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"
#include "../Utils/OS.h"
#include <iostream>

#pragma endregion

const std::string DEBUG_PATH = "../../../src/IsekaiWar!/";

ResourceManager::ResourceManager() {
	std::string root = "";
	std::string subdir = "";

	#ifdef _DEBUG
		root = OS::GetAbsolutePath(DEBUG_PATH);
		subdir = "Assets/";
	#else
		root = OS::GetExecutablePath();
		subdir = "/resourcepacks/";
	#endif

	std::string path = root + subdir;

	LoadTextures(path);
	LoadSounds(path);
	LoadMusics(path);
	LoadFonts(path);
}

void ResourceManager::LoadTextures(std::string path) {
	std::vector<std::string> assets = OS::GetFilesInDirectory(path, ".png");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddTexture(name, asset);
	}
}
void ResourceManager::LoadSounds(std::string path) {
	std::vector<std::string> assets = OS::GetFilesInDirectory(path, ".wav");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddSound(name, asset);
	}
}
void ResourceManager::LoadMusics(std::string path) {
	std::vector<std::string> assets = OS::GetFilesInDirectory(path, ".wav");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddMusic(name, asset);
	}
}
void ResourceManager::LoadFonts(std::string path) {
	std::vector<std::string> assets = OS::GetFilesInDirectory(path, ".ttf");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddFont(name, asset);
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
	sf::SoundBuffer* buffer = new sf::SoundBuffer;
	buffer->loadFromFile(path);

	sounds[name] = sf::Sound(*buffer);
	bool success = sounds.contains(name);
	Debug::Assert(success, "Could not add the sound to the resources");
}
sf::Sound* ResourceManager::GetSound(std::string name) {
	bool success = sounds.contains(name);
	Debug::Assert(success, "Could not retreive requested resource");
	return &sounds[name];
}

void ResourceManager::AddMusic(std::string name, std::string path) {
	bool success = musics[name].openFromFile(path);
	Debug::Assert(success, "Could not add the music to the resources");
}
sf::Music* ResourceManager::GetMusic(std::string name) {
	bool success = musics.contains(name);
	Debug::Assert(success, "Could not retreive requested resource");
	return &musics[name];
}

void ResourceManager::AddFont(std::string name, std::string path) {
	bool success = fonts[name].loadFromFile(path);
	Debug::Assert(success, "Could not add the font to the resources");
}
sf::Font* ResourceManager::GetFont(std::string name) {
	bool success = fonts.contains(name);
	Debug::Assert(success, "Could not retreive requested resource");
	return &fonts[name];
}
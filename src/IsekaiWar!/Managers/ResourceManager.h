#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>

#pragma endregion

class ResourceManager {
private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::SoundBuffer> sounds;
	ResourceManager();

	void LoadTextures(std::string path);
	void LoadSounds(std::string path);
public:
	void AddTexture(std::string name, std::string path);
	sf::Texture* GetTexture(std::string name);

	void AddSound(std::string name, std::string path);
	sf::SoundBuffer* GetSound(std::string name);

	friend class Managers;
};